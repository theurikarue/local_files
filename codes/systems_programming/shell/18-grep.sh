#!/bin/bash

echo "Enter file name to search text from: "
read file_name

if [ -f $file_name ]
then 
    echo "Enter the text you want to search: "
    read grep_text
    # grep -i $grep_text $file_name #i removes case sensitivity(thus one can use either small or capital letters)
    # grep -i -n $grep_text $file_name #n shows the line number where the text is found
    # grep -i -n -c $grep_text $file_name #c shows the number of times the text is found
    grep -i -n -c -v $grep_text $file_name #v shows the number of lines where the text is NOT found
else 
    echo "File not found"
fi