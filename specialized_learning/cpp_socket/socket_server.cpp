#include "socket_server.hpp"

SocketServer::SocketServer(int port) : port(port), isSocketCreated(false)
{
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(socketReadBuffer, 0, SOCKET_READ_BUFFER_SIZE);
    serverSocketFd = -1;
    clientSocketFd = -1;
    isSocketCreated = false;
    SocketServer_createSocket();
    SocketServer_bindSocket();
    SocketServer_listenOnSocket();
}

SocketServer::~SocketServer()
{
    if (isSocketCreated)
    {
        close(serverSocketFd);
    }
    if (clientSocketFd != -1)
    {
        close(clientSocketFd);
        clientSocketFd = -1;
    }
    isSocketCreated = false;
}

bool SocketServer::SocketServer_createSocket()
{
    serverSocketFd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (serverSocketFd < 0)
    {
#ifdef DEBUG
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
#endif
        return false;
    }
    // create non-blocking accept
    int flags = fcntl(serverSocketFd, F_GETFL, 0);
    fcntl(serverSocketFd, F_SETFL, flags | O_NONBLOCK);
    isSocketCreated = true;
    return true;
}

bool SocketServer::SocketServer_bindSocket()
{
    if (!isSocketCreated)
    {
#ifdef DEBUG
        std::cerr << "Socket not created. Cannot bind." << std::endl;
#endif
        return false;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(port);

    if (bind(serverSocketFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
#ifdef DEBUG
        std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
#endif
        return false;
    }
    return true;
}

bool SocketServer::SocketServer_listenOnSocket(void)
{
    if (!isSocketCreated)
    {
#ifdef DEBUG
        std::cerr << "Socket not created. Cannot listen." << std::endl;
#endif
        return false;
    }

    if (listen(serverSocketFd, LISTEN_BACKLOG) < 0)
    {
#ifdef DEBUG
        std::cerr << "Error listening on socket: " << strerror(errno) << std::endl;
#endif
        return false;
    }
    return true;
}

bool SocketServer::SocketServer_isSocketCreated(void)
{
    return isSocketCreated;
}

bool SocketServer::SocketServer_acceptClient(void)
{
    if (!isSocketCreated)
    {
#ifdef DEBUG
        std::cerr << "Socket not created. Cannot accept clients." << std::endl;
#endif
        return false;
    }

    if (clientSocketFd != -1)
    {
#ifdef DEBUG
        std::cerr << "Client already connected. Cannot accept new client." << std::endl;
#endif
        return false; // already a client connected
    }

    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    clientSocketFd = accept(serverSocketFd, (struct sockaddr *)&clientAddr, &clientLen);
    if (clientSocketFd < 0)
    {
#ifdef DEBUG
        std::cerr << "Error accepting client: " << strerror(errno) << std::endl;
#endif
        return false;
    }

    // client message is accepted successfully, now we can read and write to clientSocketFd
    return true;
}

e_frtuErrorCodes SocketServer::SocketServer_readFromClient(std::string &data)
{
    if (clientSocketFd < 0)
    {
        return SOCKET_ERROR_NO_CLIENT_CONNECTED;
    }

    // Make read non-blocking
    int flags = fcntl(clientSocketFd, F_GETFL, 0);
    fcntl(clientSocketFd, F_SETFL, flags | O_NONBLOCK);
    memset(socketReadBuffer, 0, SOCKET_READ_BUFFER_SIZE);
    ssize_t bytesRead = read(clientSocketFd, socketReadBuffer, SOCKET_READ_BUFFER_SIZE - 1);
    if (bytesRead == -1 && (errno == EAGAIN || errno == EWOULDBLOCK))
    {
        // No data available to read
        return SOCKET_NO_DATA_AVAILABLE;
    }
    else if (bytesRead < 0)
    {
        return SOCKET_ERRROR_READ_FAILED;
    }
    else if (bytesRead == 0)
    {
        // Client closed the connection
        return SOCKET_ERROR_NO_CLIENT_CONNECTED;
    }
    else
    {
#ifdef DEBUG
        perror("read failed");
#endif
    }
    // std::cout << "Bytes read: " << bytesRead << ", Data: " << socketReadBuffer << std::endl;
    data.assign(socketReadBuffer, bytesRead);
    // data = std::string(socketReadBuffer);
    return SOCKET_ERROR_NONE;
}

bool SocketServer::SocketServer_writeToClient(const std::string &data)
{
    if (clientSocketFd < 0)
    {
#ifdef DEBUG
        std::cerr << "No client connected. Cannot write data." << std::endl;
#endif
        return false;
    }
    ssize_t bytesWritten = write(clientSocketFd, data.c_str(), data.size());
    if (bytesWritten < 0)
    {
#ifdef DEBUG
        std::cerr << "Error writing to client: " << strerror(errno) << std::endl;
#endif
        return false;
    }
    return true;
}

bool SocketServer::SocketServer_closeClientConnection(void)
{
    if (clientSocketFd < 0)
    {
#ifdef DEBUG
        std::cerr << "No client connected. Cannot close connection." << std::endl;
#endif
        return false;
    }
    close(clientSocketFd);
    clientSocketFd = -1;
    return true;
}
