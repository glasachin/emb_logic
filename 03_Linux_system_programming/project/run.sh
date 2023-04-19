#! /bin/bash

buildClients()
{
    if ( gcc -DDEBUG -o rc1 ./Clients/rc1.c )
    then
        echo "Client build successfully"
        mv ./Clients/rc1 .
    else
        echo "Client build failed"
        read
    fi
}

buildServer()
{
    if ( make -C ./Server )
    then
        echo "server build successfully"
        mv ./Server/server .
    else
        echo "server build failed"
        read
    fi
}

buildVendors()
{
    if(gcc -o adder ./vendors/adder.c -DDEBUG)
    then
        echo "adder build successfully"
        mv ./vendors/adder .
    else
        echo "Client build failed"
        read
    fi
}

buildClients
buildServer
buildVendors