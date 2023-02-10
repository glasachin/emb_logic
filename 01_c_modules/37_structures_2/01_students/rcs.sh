# This file loads file (check in) into rcs and then check them out for development purpose.
#! /bin/bash

# check in files into rcs
for file in $(ls *.h) $(ls *.c)
do
    ci $file
done

# check out them for further development
for file in $(ls *.h,v) $(ls *.c,v)
do 
    co -l $file
done