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

    if ( gcc -DDEBUG -o rc2 ./Clients/rc2.c )
    then
        echo "Client build successfully"
        mv ./Clients/rc2 .
    else
        echo "Client build failed"
        read
    fi

    if ( gcc -DDEBUG -o rc3 ./Clients/rc3.c )
    then
        echo "Client build successfully"
        mv ./Clients/rc3 .
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
        echo "Adder build failed"
        read
    fi
    if(gcc -o subtract ./vendors/subtract.c -DDEBUG)
    then
        echo "subtract build successfully"
        mv ./vendors/subtract .
    else
        echo "Subtract build failed"
        read
    fi
    if(gcc -o multiply ./vendors/multiply.c -DDEBUG)
    then
        echo "multiply build successfully"
        mv ./vendors/multiply .
    else
        echo "Multiply build failed"
        read
    fi
    if(gcc -o divide ./vendors/divide.c -DDEBUG)
    then
        echo "divide build successfully"
        mv ./vendors/divide .
    else
        echo "divide build failed"
        read
    fi
}

buildClients
buildServer
buildVendors