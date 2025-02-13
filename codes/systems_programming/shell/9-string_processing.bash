#! /bin/bash

echo "enter the first string"
read str1   

echo "enter the second string"
read str2

# This matches the actual order of the strings and not the length of the strings
: '
if [ "$str1" == "$str2" ]
then 
    echo "The strings match"
else 
    echo "The strings do not match"
fi
'

: '
if [ "$str1" \< "$str2" ]
then 
    echo "$str1 has smaller length than $str2"
elif [ "$str1 \> $str2" ]
then
    echo "$str1 has greater length than $str2"
else
    echo "Both strings have the same length"
fi
'

: '
if [ ${#str1} -lt ${#str2} ]
then 
    echo "$str1 has smaller length than $str2"
elif [ ${#str1} -gt ${#str2} ]
then
    echo "$str1 has greater length than $str2"
else
    echo "Both strings have the same length"
fi
'

# concatenation of strings
: '
c=$str1$str2
echo "The concatenated string is : $c"
# echo "$str1$str2"
'

# converts the first letter of the string to uppercase
echo ${str1^}
echo ${str2^}
# converts all the letters of the string to uppercase
echo ${str1^^} 
echo ${str2^^}
