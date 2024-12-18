#!/bin/bash 
#I use bash more compared to sh since it has extra features inside

# mkdir -p sampledir


# checking whether a directory exists
: '
echo "Enter directory name to check"
read dir

if [ -d $dir ]
then 
    echo "$dir exists"
else 
    echo "The $dir does not exist"
fi
'

#eg2 - Searching for a file in current directory
: '
echo "Enter filename name to check" #usage add the file extension as well eg file.txt
read file

if [[ -f $file ]]
then 
    echo "The $file exists"
else 
    echo "The $file does not exist"
fi
'

#eg 3 - Appending to a file
: '
echo "Enter filename to append to"
read file_append

if [[ -f "$file_append" ]]
then 
    echo "Enter the text to append"
    read text
    echo $text >> $file_append
else 
    echo "The $file_append does not exist"
fi
'

#eg 4 - reading from a file line by line 
: 
echo "Enter filename to read from"
read file_read

if [[ -f "$file_read" ]]
then 
    while IFS= read -r line
    do 
        echo "$line"
    done < $file_read #change in sign from > to < since were not writing to the file but reading from it
else 
    echo "The $file_read does not exist"
fi



# eg 5 - Deleting a file
: '
echo "Enter filename to delete"
read file_delete

if [[ -f "$file_delete" ]]
then 
    rm $file_delete
    echo "The $file_delete has been deleted"
else 
    echo "The $file_delete does not exist"
fi
'


