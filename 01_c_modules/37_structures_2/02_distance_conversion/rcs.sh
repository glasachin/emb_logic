#! /bin/bash

for file in $(ls *.h *.c)
do 
    ci $file
done

# check out them for further development
for file in $(ls *.h,v *.c,v)
do 
    co -l $file
done

# run make file
if (make)
then
    echo "build success"
else
    echo "build failed"
fi

# run binary
./dis_convert
