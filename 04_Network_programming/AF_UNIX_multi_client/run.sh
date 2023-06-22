### This file compiles the server and client binaries from their respective folders and then move the
### executables to current folder

#!/bin/bash

buildserver()
{
    if(make -C ./Server)
    then
        echo "Server build successfully"
        mv ./Server/server .
    else    
        echo "Server build failed"
        read
    fi
}

buildclient()
{
    if(make -C ./Client)
    then
        echo "Client build successfully"
        mv ./Client/client .
    else    
        echo "Client build failed"
        read
    fi
}

buildserver
buildclient