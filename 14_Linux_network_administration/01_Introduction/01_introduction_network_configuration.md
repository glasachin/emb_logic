# 01: Introduction to Network and Configurations

## Introduction to Networking

Ubiquitous netowrking
LAN
MAN
WAN

## Packets
Computer transmits data in the form of packets. It contains two parts:
1. Header: identifying information such as source & destination address
2. Payload: Actual application data (e.g. html, data, image etc.)

A host can send, receive and process packets in any order. It make hosts to communicate simultaneously.

## Network Layers
A fully functional network includes a set of network layers called a network stack. 

### Application Layer

Contains the "language" that applications and servers use to communicate. e.g HTTP, FTP.

### Transport Layer
It defines the data transmission characteristics of the application layer. It includes data integrity checking, source and destination ports and specifications for breaking application data into packets at the host side and reassembling them at the destination. **TCP** and **UDP** are the most common transport layer protocols. sometime this layer is also called the **protocol layer**.

### Network or Internet Layer
It defines the flow of packets movement from source to a destination host. The packet transit rule set for the internet is known as the internet protocol.

As network layers are meant to be hardware independent, we can simultaneously configure several independent network layers such as IPv4, IPv6, IPX and AppleTalk on a single host.

### Physical layer
It defines, how to send raw data across a physical medium such as Ethernet or a modem. It is also called as `link lyaer` or `host-to-network layer`.


## Internet Layer
It is based on IPv4 or IPv6. 

The internet's topology is decentralized; it is made up of smaller networks called `subnets`. The idea is that all subnets are interconnected in some way. A host can be connected to more than one subnet. Such host is called a `router`.

### IP Address
In IPv4, IP address is in the form of **a.b.c.d** 

To see the IP address:

``` 
$ip address show
or
$ifconfig
```

### Subnets
It is a connected group of hosts with IP addresses in a particular range. We can define a subnet with two pieces:
1. A network prefix (routing prefix)
2. Subnet mask (network mask or routing mask)

e.g `subnet: 255.255.255.0`

**Common Subnet Masks and CIDR Notation**

Classlesll Inter-Domain Routing (CIDR) notation, where `10.23.2.0/255.255.255.0` is written as `10.23.2.0/24`. In binary `255.255.255.0` has 24 `1-bits` followed by 8 `0-bits`. The CIDR notation identifies the subnet mask by the number of leading `1s` in the subnet mask. Common CIDR subnet masks are `/8, /16, /12, /24, /26`.

## Routes and The Kernel Routing Table
