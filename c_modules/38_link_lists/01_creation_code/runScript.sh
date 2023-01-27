#! /bin/bash

checkIn()
{
    for file in $(ls *.c *.h)
    do  
        ci $file
    done
}

checkoutBuild()
{
    for file in $(ls *.c,v *.h,v)
    do
        co $file
    done
}

checkoutDev()
{
    for file in $(ls *.h,v *.c,v)
    do
        co -l $file
    done
}

buildprogram()
{
    if(make)
    then
        echo "Program build successfully"
    else
        echo "Program build unsuccessfully"
        read
    fi
} 

runbinary()
{
    if (./ll)
    then
        echo "Program executed successfully"
    else
        echo "Program execution failed"
        read
    fi
}

menu()
{
    echo "__SCRIPT MENU__"
    echo "1: Clean"
    echo "2: Check in files"
    echo "3: Check Out for Build"
    echo "4: Build Program"
    echo "5: Run Application"
    echo "6: Check out for development"
    echo "0: Exit script"
    echo "Please Enter your choice: "
    read -n1 choice
    case $choice in 
        1)
            make clean
            ;;
        2)
            checkIn
            ;;
        3)
            checkoutBuild
            ;;
        4)
            buildprogram
            ;;
        5) 
            runbinary
            ;;
        6)
            checkoutDev
            ;;
        0)
            exit 0
            ;;
        *)
            echo "Invalid Choice"
    esac
}

while true
do
    menu
done