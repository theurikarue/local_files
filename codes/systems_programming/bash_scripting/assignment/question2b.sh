#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question 2A : 2(b) write the script to report if in the text file called Angukanayo.txt has a string Mpangale and the line number on which it occurs within file.

#check if the file Angukanayo.txt exists
if [ ! -f Angukanayo.txt ]
then
    echo "Error!: The file Angukanayo.txt does not exist"
    exit 1
fi

#search for the string 'Mpangale' in the file Angukanayo.txt
echo "Searching for 'Mpangale' in the file Angukanayo.txt..."
matches=$(grep -n "Mpangale" Angukanayo.txt)

#check the exit status of the grep command
if [ $? -eq 0 ]
then
    echo "$matches" | while IFS= read -r line 
    do 
        line_number=$(echo "$line" | cut -d ':' -f1)
        full_line=$(echo "$line" | cut -d ':' -f2-)
        echo "The string 'Mpangale' was found on line $line_number: $full_line"
    done
else
    echo "The string 'Mpangale' was not found in the file Angukanayo.txt"
fi