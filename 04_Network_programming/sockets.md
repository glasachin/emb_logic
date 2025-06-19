# Sockets

## Socket Attributes

Three attributes

1. `Socket Domain`: specify the `network medium`
    * `AF_INET` : refers to internet networking
    * `AF_UNIX`
    * `AF_ISO`
    * `AF_XNS`
    * `AF_IPX`
    * `AF_APLETALK`

2. `Socket Types`: `Internet protocols provide two communication mechanism
    * `Stream Sockets` : similar to standard input/output streams. 
        * Specified by `SOCK_STREAM`, implemented in `AF_INET` domain by TCP/IP
        * also the usual type in the `AF_UNIX` domain.
    * `Datagram Sockets` : 
        * Specified by `SOCK_DGRAM`, in `AF_INET` domain by UDP/IP

3. `Protocol` : underline transport mechanism

## Socket system Calls or Functins

```c
#include <sys/socket.h>
#include <sys/types.h>
```

### Creating a socket**

```c
int socket(int domain, int type, int protocol);
```

### Socket Address**

**for AF_UNIX Socket**

```c
struct sockaddr_un {
    sa_family_t sun_family;
    char sun_path[];
};
```

**for AF_INET Doman**

```c
struct sockaddr_in {
    short int sin_family; 
    unsigned short int sin_port;
    struct in_addr  sin_addr;
};
```

**IP Address Structure**

```c
struct in_addr {
    unsigned long int s_addr;
};
```

### Naming a Socket

server program need to give the sacket a name.
* `AF_UNIX` sockets are associated with a file system pathname.
* `AF_INET` sockets are associated with an IP port number.

`int bind(int socket, const struct sockaddr *address, size_t address_len);`


### Creating a Socket Queue

To accept incoming connections on a socket, the server need to create a queue to store pending requests

`int listen(int socket, int backlog);`

it sets queue length to `backlog`

### Accepting Connections
Once a socket has been created and named then it can wait for connections

`int accept(int socket, struct sockaddr *address, size_t *address_len);`

This call returns when a client program attempts to connect to the socket.

`NOTE`: this function will block if there is not pending connection in the queue. we can change this behavior by using the `O_NONBLOCK` flag on the socket file descriptor using `fcntl` function.

```c
int flags = fcntl(socket, F_GETFL, 0);
fcntl(socket, f_SETFL, O_NONBLOCK | flags);
```

### Requesting Connections
Client programs connect to servers by establishing a connection.

```c
#include<sys/socket.h>
int connect(int socket, const struct sockaddr *address, size_t address_len);
```

i.e. client and server both need to call `socket` first.

### Closing a Socket

`close`

## Byte Ordering
Port numbers and addresses are communicated over socket interface as binary numbers. Different computer architectures use different byte ordering (`little endian` or `big endian`)

Hence, Client and Server programs must convert their internal integer representation to the network ordering before transmission. 

```c
#include<netinet/in.h>
unsigned long int htonl(unsigned long int hostlong);
unsigned short int htons(unsigned short int hostshort);
unsigned long int ntohl(unsigned long int netlong);
unsigned short int ntohs(unsigned short int netshort);
```

The above converted between `native host format ` and `standard network ordering`. 

`htonl`: host to network long (for IP addresses and integers)
`ntons`: host to network short (for port numbers)

**E.G.**

at server
```c
server_address.sin_addr.s_addr = htonl(INADDR_ANY);
server_address.sin_port = htons(9734);
```

at client

```c
address.sin_port = htons(9734);
```


