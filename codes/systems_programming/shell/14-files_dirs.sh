#!/bin/bash

# mkdir SampleDir1
# read dir

if [ -d "$dir" ]
then 
    echo "The directory exists"
else
    echo "The directory does not exist"
fi

: '
# for files
echo "Enter the file name to search: "
read file
touch file.txt

if [ -f "$file" ]
then 
    echo "The file exists"
else
    echo "The file does not exist"
fi
'


# for appending
: '
echo "Enter the file name to append to: "
read appendfile


if [ -f "$appendfile" ]
then 
    echo "Enter the text you would like to append: "
    read text
    echo "$text" >> "$appendfile"
else
    echo "The file does not exist"
fi
'


# read from the file
: '
echo "Enter the file name to read from: "
read readfile
if [ -f "$readfile" ]
then 
    while IFS= read -r line
    do 
        echo "$line"
    done < "$readfile"
else
    echo "The file does not exist"
fi
'

#deleting the file
touch 14b-file_to_delete.txt
echo "Enter the file name to delete: "
read deletefile
if [ -f "$deletefile" ]
then 
    rm "$deletefile"
    echo "The file has been deleted successfully"
else
    echo "The file does not exist"
fi















