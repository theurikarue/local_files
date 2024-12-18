#!/bin/bash

# method one
num1=30
num2=10
echo $(( num1+num2 ))
echo $(( num1-num2 ))
echo $(( num1*num2 ))
echo $(( num1/num2 ))
echo $(( num1%num2 )) #returns the remainder  

# method two using expr
echo $(expr $num1 + $num2 ) # make sure there's space between + operator
echo $(expr $num1 - $num2 )
echo $(expr $num1 \* $num2 )
echo $(expr $num1 / $num2 )
echo $(expr $num1 % $num2 )

#converting from decimal to hexadecimal
echo "Enter the Hex number of your choice"
read Hex

echo -n "The decimal value of $Hex is :"
echo "obase=10; ibase=16; $Hex" | bc #eg A is hex for 10

