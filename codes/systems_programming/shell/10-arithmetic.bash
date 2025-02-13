#! /bin/bash

num1=20
num2=5

# method 1 : use of $(( expression ))
echo $(( num1 + num2 ))
echo $(( num1 - num2 ))
echo $(( num1 * num2 ))
echo $(( num1 / num2 ))
echo $(( num1 % num2 ))

# method 2 : use of expr
echo $(expr $num1 + $num2 )
echo $(expr $num1 - $num2 )
echo $(expr $num1 \* $num2 )
echo $(expr $num1 / $num2 )
echo $(expr $num1 % $num2 )

# method 3 : use of let
let result=num1+num2
let result2=num1-num2
let result3=num1*num2
let result4=num1/num2
echo $result3


# method 4 : use of bc
echo "20.5+5" | bc
echo "20.5-5" | bc
echo "20.5*5" | bc
echo "20/5"   | bc
echo "20.5%5" | bc


# method 5 : use of awk
echo | awk "{print $num1 + $num2}"
echo | awk "{print $num1 - $num2}"
echo | awk "{print $num1 * $num2}"
echo | awk "{print $num1 / $num2}"
echo | awk "{print $num1 % $num2}"

# changing decimal to hexadecimal using bc calculator
echo "enter the number you want to convert to hex"
read num

#obase = output base
#ibase = input base
echo "obase=16; ibase=10; $num" | bc
# echo "obase=2; $num" | bc
