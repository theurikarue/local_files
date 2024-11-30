#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# QUESTION :  Write the shell script that reads any 6 numbers from the keyboard and print their sum, if non numbers are keyed from the keyboard , it throws an alert to key in numbers only.


#Function to validate that the input is in fact a number
is_number(){
    re='^[0-9]+([.][0-9]+)?$'
    if ! [[ $1 =~ $re ]]; then
        echo "Please Enter Numbers Only!!!"
        exit 1
    fi
    return 0
}

#initializing variables
sum=0
count=0

echo "Enter 6 numbers:"

#loop until 6 valid numbers are entered
while [ $count -lt 6 ]
do
    #Prompt the user to enter a number
    read -p "Enter number $(($count + 1)): " input

    if is_number "$input"; # check if the input is a number
    then
        sum=$(echo "$sum + $input" | bc) #bc is a command line calculator
        #sum=$(($sum + $input)) # using shell arithmetic for summation
        count=$(($count + 1))
    else
        echo "Please Enter Numbers Only!!!"
        exit 1
    fi
done

#output the sum of the 6 entered numbers
echo "The sum of the entered numbers is: $sum"

     