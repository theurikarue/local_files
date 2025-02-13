#!/bin/bash

# $0 - makes sure your file name is also printed out
# method 1
# echo $0 $1 $2 $3

# method 2 : array method 
: '
args=("$@")
# echo $0 ${args[0]} ${args[1]} ${args[2]} # for 1st, 2nd and 3rd elements from the array
echo $@ # prints all the arguments passed to the script
'


while read line
do 
    echo $line
done < "${1:-/dev/stdin}" # this will read the file passed as an argument to the script











