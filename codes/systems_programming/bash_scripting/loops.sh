#!/bin/sh

#for loop
for var in 0 1 2 3 4 5 6 7 8 9
do 
	echo $var
done

#while loop
a=0
while [ $a -lt 10 ]
do
	echo $a
	a=`expr $a + 1`

done

a=0
until [ ! $a -lt 10 ]
do 
	echo $a
	a=`expr $a + 1`
done 

#nested loops
a=0
while [ "$a" -lt 10 ]
do	
	b="$a"
	while [ "$b" -ge 0 ]
	do 
		echo -n "$b"
		b=`expr $b - 1`
	done
	echo 
	a=`expr $a + 1`
done

#infinite loop
# a=10

# until [ $a -gt 0] #make sure there's no space between 0 and closing square bracket 
# do 
# 	echo $a
# 	a=`expr $a + 1`
# done

#breaking from a loop
a=0
while [ $a -lt 10 ]
do
	echo $a
	if [ $a -eq 5 ]
	then
		break
	fi
	a=`expr $a + 1` # make sure there's space between + and 1
done 

#continue statement 
NUMS=" 1 2 3 4 5 6 7 8"

for NUM in $NUMS 
do 
	Q=` expr $NUM % 2 `
	if [ $Q -eq 0 ]
	then 
		echo "Found an even number"
		continue
	fi
	echo "Found an odd number"

done 