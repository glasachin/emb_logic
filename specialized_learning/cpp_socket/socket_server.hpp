#pragma once
#include <iostream>
#include <string>

extern "C"
{
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
// #include "../utility/settings.h"
}

#define DEBUG
// --------------------MACRO DEFINITIONS--------------------
#define LISTEN_BACKLOG 10
#define SOCKET_READ_BUFFER_SIZE 1024
// -------------------ENUM DEFINITIONS--------------------
typedef enum
{
    ERROR_NONE = 0,
    SOCKET_ERRROR_READ_FAILED = 100,
    SOCKET_NO_DATA_AVAILABLE,
    SOCKET_ERROR_NO_CLIENT_CONNECTED
} e_frtuErrorCodes;
// -------------------STRUCT DEFINITIONS--------------------


// -------------------CLASS DEFINITIONS--------------------
class SocketServer
{
private:
    int serverSocketFd;
    int clientSocketFd;
    int port;
    struct sockaddr_in serverAddr;
    bool isSocketCreated;
    char socketReadBuffer[SOCKET_READ_BUFFER_SIZE];
public:
    SocketServer(int port);
    ~SocketServer();
    bool SocketServer_createSocket(void);
    bool SocketServer_bindSocket(void);
    bool SocketServer_listenOnSocket(void);
    bool SocketServer_acceptClient(void); 
    e_frtuErrorCodes SocketServer_readFromClient(std::string &data);
    bool SocketServer_writeToClient(const std::string &data);
    bool SocketServer_closeClientConnection(void);
    bool SocketServer_isSocketCreated(void);
};
