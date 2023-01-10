#! /bin/bash
# This is a rcs maintained directory. In this bash file we will create a menu for file addition into rcs
# and checkout from rcs

CheckInProgram()
{
    for file in $(ls *.c *.h)
    do
        ci $file
    done
}

CheckOutBuild()
{
    for file in $(ls *.c,v *.h,v)
    do
        co $file
    done
}

BuildFile()
{
    gcc -o power 01_power.c
}

RunFile()
{
    sh ./power
}

CheckOutDev()
{
    for file in $(ls *.c,v *.h,v)
    do
        co -l $file
    done
}


MainMenu()
{
    echo
    echo "----------Main Menu (RCS)---------"
    echo "1. Checkin"
    echo "2. Checkout for build"
    echo "3. Build File"
    echo "4. Run File"
    echo "5. Checkout for development"
    echo "0. Exit"
    read -n1 -p "Enter your choice: "
    case 
        0)
            exit 0
            ;;
        1)
            CheckInProgram()
            ;;
        2)
            CheckOutBuild()
            ;;
        
        *)
            echo "Invalid Choice"
    esac
}

MainMenu