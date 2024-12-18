#!/bin/bash

# scan a file by line
# split each import line into different fields 
# perform actions on mast lines


echo "Enter Filename to print from awk: "
read awk_file

if [[ -f $awk_file ]] 
then
    awk '/Linux/ {print $1,$3}' $awk_file #eg for the line 'This is Linux' only 'is' is printed since it's the second 
else 
    echo "$awk_file does not exist"
fi