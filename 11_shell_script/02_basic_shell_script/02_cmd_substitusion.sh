#! /bin/bash
# output of a command to a variable

date='date' #this doesn't seems to be working
echo $date

date=$( date )
echo $date
