#!/bin/bash


echo "Enter Filename to search text from: "
read filename

if [[ -f $filename ]] 
then
    # echo "$filename exists."
    echo "Enter text to search"
    read grepvar
    # grep -i -v $grepvar $filename #the flag -i makes sure you can use any case (upper or lower)
    grep -i -n -c -v $grepvar $filename 
        #the flag -i makes sure you can use any case (upper or lower)
        # while flag -n lists the line numbers 
        # flag -c shows number of times a word has come up
        #flag -v shows number of lines NOT containing the text you're looking for
else 
    echo "$filename does not exist"
fi

