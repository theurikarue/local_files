#!/bin/bash

number=1
: '
while [ $number -lt 10 ]
do 
    echo "The number is $number"
    number=$(( number+1 ))
done
'

# until loop - it runs until the condition becomes True
until [ $number -ge 10 ]
do 
    echo "The number is $number"
    number=$(( number+1 ))
done


# for loop

for i in {0..20..2} # {start..end..increment} , {1..20..2} - increments by two thus will print odd number 
# for (( i=0; i<=30; i++ ))
do 
    echo "The number is $i"
done

# eg 2
for (( i=0; i<=10; i++ ))
do 
    if [ $i -gt 5 ]
    then
        break
    fi
    echo "The number is $i"
done

# this will skip numbers 3 and 6 and continue with the loop
for (( i=0; i<=10; i++ ))
do 
    if [ $i -eq 3 ] || [ $i -eq 6 ]
        then
            continue
        fi
    echo "The number is $i"
done









