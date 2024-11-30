#!/bin/sh

#echo "File name: $0"
#echo "First parameter: $1"
#echo "Second parameter: $2"
#echo "Quoted values: $@"
#echo "Quoted values: $*"
#echo "No of paramters: $#"

#for TOKEN in $*
#do
#	echo $TOKEN
#done

echo "Enter first number"
read A

echo "Enter second number"
read B

SUM=$((A+B))

# SUM=`expr $a + $b`

echo "The sum of the two numbers is: $SUM"

