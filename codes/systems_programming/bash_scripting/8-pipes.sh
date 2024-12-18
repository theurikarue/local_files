#!/bin/bash
# More of sending output from one script to another 

: '
MSG="Hello Linux Audience"
echo "Testing that MSG is okay > $MSG"
export MSG
./8b-pipes.sh
'

echo "Enter your first string"
read str1

echo "Enter your second string"
read str2
: '
if [ "$str1" = "$str2" ]
then
    echo "Strings match"
else 
    echo "Strings DO NOT match"
fi
'

# length of strings
: '
len1=${#str1}
len2=${#str2}

if [ "$len1" -gt "$len2" ]
then
    echo "Str1 is longer than str2"
elif [ "$len1" -lt "$len2" ] 
then
    echo "Str2 is longer than str1"
else 
    echo "Both strings are of equal length"
fi
'

# string concatenation
: 'c=$str1$str2
echo $c
'
c=$str1$str2
echo $c

#upper case
echo "First letter as uppercase is ${str1^}"
echo "First string as uppercase is ${str1^^}"
echo "Second letter as uppercase is ${str2^}"
echo "Second string as uppercase is ${str2^^}"


