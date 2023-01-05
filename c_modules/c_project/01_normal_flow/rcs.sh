#! /bin/bash

check in all *.c and *.h files
for files in $(ls *.c) $(ls *.h)
do 
    ci $files
done

# chekout all files for further development
for files in $(ls *.c,v) $(ls *.h,v)
do 
    co -l $files
done

# Run make file to compile the code
if (make)
then
    echo "Build Success!"
else
    echo "Build Failed!"
fi

# run binary file
./compress
