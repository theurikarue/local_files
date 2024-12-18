#!/bin/bash
#usage example > ./6-input.sh BMW MERCEDES TOYOTA

# Method one
: '
echo $0 $1 $2 $3
'

# Method two - using an array of arguments
: '
args=("$@")
echo ${args[0]} ${args[1]} #to print one argument at a time or at a certain position
echo $@ #printing all args in the array
echo $# #prints out the number of elements in the arrray
'

#reading from a file
# usage - ./6-input.sh cli_essentials.txt ~/Documents\local/codes/systems_proggramming/bash_scripting
while read line 
do
    echo "$line"
done < "${1:-/dev/stdin}" 



