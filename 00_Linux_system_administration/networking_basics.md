# Networking

1. `ip route show`
2. `ip addr show <interfacename>`
3. `ip link set <interface> up` : to bring interface up
4. `ip addr add <ip-addr>/24 dev <interface>` : to assign ip address
5. `ip route add 192.168.7.0/24 dev <interface>` : to add route to interface in routing table.
6. 

**ipv6 related** : this shows routing tables

1. `ip -6 route` : to show `IPv6 routing table.
    1. `ip -6 route show dev <interface>` : to view only specific interface
2. `route -A inet6`
3. `netstat -rn -A inet6`


## Netplan Configuration



## interfaces file (/etc/network/interfaces)



## UDHCPC related
`udhcpc`(Micro DHCP Client) is a lightweight DHCP client included in the BusyBox suite of utilities. It is commonly used in embedded Linux systems or lightweight Linux distributions where resource usage is a critical concern. 

**Basic Command**

`udhcpc -i <interface>`

**configuration file**

`/usr/share/udhcpc/default.script`

Using udhcpc in Embedded Systems:
Default Script Handling:

When udhcpc gets an IP lease, it runs a script (often /usr/share/udhcpc/default.script).
This script typically updates network settings like IP address, DNS, and routes.

**Disable DHCP on a Specific Interface**

`udo udhcpc -i <interface> -R`

or kill the `udhcpc` process


## Setting up Nameserver

sometimes nameserver gets overwritten on reboot. We can avoid it by the following:


