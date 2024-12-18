#!/bin/bash

#while loop
: '
number=0
while [ $number -lt 10 ] #to print all the way to 10 use -le
do 
    echo "$number"
    number=$(( number+1 ))
done
'

#until loop
: '
number=0
until [ $number -ge 10 ] #outputs until the condition becomes true - so once it becomes True then it stops 
do 
    echo "$number"
    number=$(( number+1 ))
done
'


#for loop
: '
for num in {0..100..2}
do
    echo $num
done
'

# more common for loop
#eg1
: '
for (( num=0; num<5; num++ ))
do
    echo $num
done
'
#eg2
: '
for (( num=0; num<10; num++ ))
do
    if [ $num -gt 5 ]
    then 
        break
    fi
    echo $num
done
'
#eg3 - this prints all values apart from 5 & 8
for (( num=0; num<=10; num++ ))
do
    if [ $num -eq 5 ] || [ $num -eq 8 ]
    then 
        continue
    fi
    echo $num
done







