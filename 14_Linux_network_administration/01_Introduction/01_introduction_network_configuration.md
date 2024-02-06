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
Connecting internet subnets is mostly a process of sending data through hosts connected to more than one subnet. Linux kernel distinguishes between two different kinds of destinations by using a routing table to determine its routing behavior. 

```$ip route show```

The above command shows the routing table.

## The Default Gateway
`0.0.0.0/0` for IPv4. This is the default route, and the address configured as the intermediary in the default route is the default gateway.

When no other rules match, the default route always does and the default gateway is where you send messges when there is no other choice. 

## The IPv6 Addresses and Networks


## Basic ICMP and DNS Tools
`Internet Control Message Protocol (ICMP)` which can help to root out problems with connectivity and routing and the domain name service (DNS) system. `DNS` maps names ot IP addresses so that we don't have to remember a bunch of numbers.

ICMP is a transport layer protocol used to configure and diagnose internt networks. By comparison `DNS` is an application layer protocol used ot map human-readable names to internet addresses.

### ping
It very basic network debugging tools and sends ICMP echo request packets to a host that asks a recipient host ot return the packet to the sender. 
```$ping 192.168.1.10```

### DNS and host
DNS translates the domain name such as `www.google.com` to its IP address.

```$host www.google.com```

## The Physical Layer and Ethernet
Internet is a software network but in order to communicate with other system, we still have to put a network layer on top of some kind of hardware. This interface is the **physical layer**.

All devices on an Ethernet network have a Media Access Control (MAC) address. Devices on an ethernet network send messages in frames, which are wrappers around the data sent. A frame contains the origin and destination MAC addresses. 

We also need an `ethernet bridge` to switch between two different network media on same computer.

## Linux Network Interface
when we configure a network interface, we link the IP address settings from the internet side with the hardware identification on the physical device side.

network interfaces have name such as `eth0` or `wlan0`. Such names are known as **predictable network interface** device name because it remains the same after a reboot.

```$ifconfig```

## Network Interface Configuration
We have seen all the lower levels of a network stack: physical layer, the network (internet) layer and the linux kernel's network interfaces. In order to combine all these, we need a software to do the following:
1. Connect the network hardware and ensure that the kernel has a driver for it.
2. Perform any additional physical layer setup, such as choosing a network name or password.
3. Assign IP addresses and subnets to ther kernel network interface.
4. Add any additional necessary routes, including the default gateway.

### Manual Configuration
```$ip address add address/subnet dev interface```

```$ip route add default via gw-address dev interface```

```$ip route del default```

**Example**
```$ip route add 192168.45.0./24 via 10.23.2.44```
```$ip route del 192.168.45.0/24```

## Boot activated network configuration
there is not specific standard due to different distributions with different implementations.

A tool called `netplan` transform the configuration into the files used by existing network managers. `netplan` files are in `YAML` format and reside in `/etc/netplan`


## Network Configuration Managers
Network Manager is most widely used option on destops to configure networks in Linux-based systems. There is an add-on to `systemd` called `systemd-networkd` that can do basic network configuration and is useful on servers. 

Other network management tools for smaller embedded systems are `OpenWRT netifd`, `Android connectivity manager service`, `ConnMan` and `Wicd`

Systemd-networkd related configuration directory is `/etc/systemd/network`.

### Network Manager Operation

<---To be Done----->

## Resolving Hostnames
DNS is used to resolve the hostnames.The resolution process typically unfolds like this:
1. the appliation calls a function to look up the IP address behind a hostname. This function is in the system's shared library.
2. The function acts according to a set of rule (found in `/etc/nsswitch.conf`) to determine a plan of action on lookups. E.g. the rule usually say that even before going to DNS, check for a manual override in the `/etc/hosts` file.
3. when the function decides to use DNS for the name lookup, it consults an additional configuration file to find a DNS name server. The name server is given as an IP address.
4. The function sends a DNS lookup request to the name server.
5. The name server replies with the IP address for the hostname and the function returns this IP address to the application.

On most systems, we can override hostname lookups with the `/etc/hosts` file.

### resolv.conf
It (`/etc/resolv.conf`) is the traditional configuration file for DNS servers.
The search line defines rules for incomplete hostnames.

### caching and zero-configuration DNS
In traditional DNS config, local machine doesn't cache name server replies, which may result into unnecessarily slow requests. So, in many machines there is an intermediate `daemon` to intercept name server requests and cache the reply and then use the cached answers if possible. The most common of these `daemons` is `systemd-resolved`. We can also set up `BIND` as a cache.

we can often tell, if we are running a name server caching daemon if we see `127.0.0.53` or `127.0.0.1` in `/etc/resolv.conf` file or listed as the server when we run `$nslookup -debug host`. 

We can check the current DNS settings with the `$resolvectl status` command. If we wanted to change our settings, then we need to edit `/etc/systemd/resolved.conf` 

`/etc/nsswitch.conf` is the traditional interface for controlling several name-related precedence settings on system, such as user and password information and it has a host lookup setting. 

### Localhost
The `lo` interface is called loopback as it "loops back" to itself (`127.0.0.1 or ::1 in IPv6`)

## The Transport Layer TCP UDP Services


