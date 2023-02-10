#! /bin/bash

echo "List of Positional Paramters: $@"
echo "Process ID: $$"
echo "Number of Positional Parameters: $#"
echo "List of Positional Parameters: $*"

while [ $1 ]
do 
	echo $1
	shift
done
