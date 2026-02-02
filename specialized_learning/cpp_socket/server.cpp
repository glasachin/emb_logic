#include <iostream>
#include "socket_server.hpp"

#define DEBUG

int main()
{
    SocketServer server(8034);

    e_frtuErrorCodes result;

    if (!server.SocketServer_isSocketCreated())
    {
        std::cerr << "Failed to create server socket." << std::endl;
        return -1;
    }
    std::cout << "Server socket created and listening on port 8034." << std::endl;

    while (1)
    {
        if (server.SocketServer_acceptClient())
        {
            std::cout << "Client connected." << std::endl;
            while (1)
            {
                std::string receivedData;
                result = server.SocketServer_readFromClient(receivedData);
                if (result == ERROR_NONE)
                {
                    std::cout << "Received from client: " << receivedData << std::endl;
                    // Echo back the received data
                    server.SocketServer_writeToClient("hello from server");
                }
                else if (result == SOCKET_ERROR_NO_CLIENT_CONNECTED)
                {
                    // std::cout << "Client disconnected." << std::endl;
                    break;
                }
                else if (result == SOCKET_NO_DATA_AVAILABLE)
                {
                    // No data available, continue waiting
                    std::cout << "Waiting for data from client..." << std::endl;
                    usleep(1000000); // Sleep for 100ms
                    continue;
                }
                else
                {
                    std::cerr << "Error reading from client." << std::endl;
                    break;
                }
            }
            server.SocketServer_closeClientConnection();
            // std::cout << "Client disconnected." << std::endl;
        }
        // Sleep or perform other tasks
        std::cout << "Waiting for client to get connected..." << std::endl;
        usleep(1000000); // Sleep for 100ms
    }

    return 0;
}