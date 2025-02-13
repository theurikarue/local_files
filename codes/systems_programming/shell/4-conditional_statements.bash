#!/bin/bash

: '
count=10
# if [ $count -eq 10 ] # NE, GT, LT, GE, LE
#if (( $count == 10 )) # NE, GT, LT, GE, LE
if (( $count < 9 )) # NE, GT, LT, GE, LE
then
    echo "The first condition is true"
elif (( $count > 9 ))
then
    echo "The second condition is true"
else   
    echo "The condition is false"
fi
'

: '
# Logical AND operator ( && or -a )
#for someone to be considered part of the youth they should be between 18 and 35
age=16
if [ $age -gt 18 ] && [ $age -lt 35 ]
# if [ $age -gt 18 -a $age -lt 35 ]
then
    echo "The age is valid"
else
    echo "The age is not valid"
fi
'


# Logical OR operator ( || or -o )
# for someone to be considered part of the youth they should be either 18 or 35
: '
age=35
if [ $age -eq 18 ] || [ $age -eq 35 ]
# if [[ $age -eq 18 || $age -eq 35 ]]
# if [ $age -eq 18 -o $age -eq 35 ]
# if (( $age == 18 || $age == 35 ))
then
    echo "The age is valid"
else
    echo "The age is not valid"
fi
'

# Switch case statement
# : 
# fruit="apple"

# case $fruit in
#     "apple")
#         echo "It's an apple." ;;
#     "banana")
#         echo "It's a banana." ;;
#     "orange"|"lemon")
#         echo "It's a citrus fruit." ;;
#     *)
#         echo "Unknown fruit.";;
# esac

: 
# # example 2
# NOW=$(date +"%a")
# case $NOW in Mon) echo "Full backup";;
# Tue|Wed|Thu|Fri) echo "Partial backup";;
# Sat|Sun) echo "No backup";;
# *) ;;
# esac


# example 3

option="${1}"
case ${option} in
    -f)
        file="${2}"
        echo "File name is $file"
        ;;
    -d)
        dir="${2}"
        echo "Directory name is $dir"
        ;;
    *)
        echo "Invalid option. Usage: $0 [-f <file> | -d <dir>]"
        ;;
esac

