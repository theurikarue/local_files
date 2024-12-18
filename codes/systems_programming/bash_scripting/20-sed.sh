#!/bin/bash

echo "Enter Filename to substitute using sed: "
read sed_file

if [[ -f $sed_file ]] 
then
    # cat grep.txt | sed 's/i/I/' #s for substitute - it basically substitutes all small is into capital Is
    # cat grep.txt | sed 's/i/I/g' # g for global to replace all the small is with capital Is
    # cat grep.txt | sed 's/i/I/g' $sed_file > sed.txt # g for global to replace all the small is with capital Is
    cat grep.txt | sed 's/linux/Unix/g' $sed_file > sed.txt # for whole words
else 
    echo "$sed_file does not exist"
fi
