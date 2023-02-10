#1 /bin/bash

# this shell scripts invokes the RCS and take in all the *.c files.

for files in $(ls *.c *.h)
do
    ci $files
done

# check out files for compilation
for files in $(ls *.c,v *.h,v)
do
    co $files
done

# compile files
make

# Checkout files for development
for files in $(ls *.c,v *.h,v)
do
    co -l $files > /dev/null
done