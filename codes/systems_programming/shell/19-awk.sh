#!/bin/bash

# awk is a scripting lang used to manipulate data and generate reports.
# however it can still be used in bash 


echo "Enter the file name to print using AWK"
read file_name

if [ -f $file_name ]
then 
    # awk '{print}' $file_name #prints the entire file
    awk '/Linux/ {print}' $file_name #prints the lines with the word Linux
    awk '{print $1,$3}' $file_name #prints the first and third columns of the file
else
    echo "File not found"
fi