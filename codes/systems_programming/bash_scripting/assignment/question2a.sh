#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question :Write a Shell script that reads the text in a text file called Angukanayo.txt and outputs number of characters (inclusive of white spaces ) in that textfile

#check if the file exists
if [ ! -f Angukanayo.txt ]
then
    echo "Error!: The file Angukanayo.txt does not exist"
    exit 1
fi

#count the number of characters in the file
character_count=$(wc -m < Angukanayo.txt | awk '{print $1}') #Pipes to awk to extract the number

#output the number of characters in the file
echo "The number of characters (inclusive of white spaces) in the file Angukanayo.txt is: $character_count"
