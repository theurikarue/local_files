#!/bin/bash

echo "Enter the file you want to use SED on: "
read file_name

if [ -f $file_name ]
then
    #  sed 's/l/L/' "$file_name" # s stands for substitute, thus this command substitutes first small ls in the file with Ls
    #  sed 's/l/L/g' $file_name # g stands for global, thus this command substitutes all small ls in the file with Ls
    #  sed -i 's/l/L/g' $file_name # -i stands for in-place, thus this command substitutes all small ls in the file with Ls and saves the changes in the file
    #  sed -i 's/l/L/g' $file_name > newfile.txt # this command substitutes all small ls in the file with Ls and saves the changes in a new file
    sed 's/Linux/Unix/g' $file_name # this command substitutes all instances of Linux with Unix in the file
else 
    echo "File does not exist"
fi