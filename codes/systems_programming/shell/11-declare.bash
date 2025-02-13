#! /bin/bash

# Declare is used to create a variable and assign a value to it
# FOr the terminal use the following command to see the output of the script
# declare -p

declare -r pwdfile=/etc/passwd

echo "The file is $pwdfile"
pwdfile=/etc/school.txt
echo "The file is $pwdfile"





