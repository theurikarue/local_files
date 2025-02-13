#!/bin/bash -x 
#{place the -x after shebang line}


# method 2 - when running your script add a -x flag
# bash -x ./file_name.sh # shows lines being executed 

# method 3 - set -x in the script 

# set -x

echo "Enter the file name to print using AWK"
read file_name

# set +x

if [ -f $file_name ]
then 
    # awk '{print}' $file_name #prints the entire file
    # awk '/Linux/ {print}' $file_name #prints the lines with the word Linux
    awk '{print $1,$3}' $file_name #prints the first and third columns of the file
else
    echo "File not found"
fi
