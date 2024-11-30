#!/bin/bash
# NAME : THEURI BONFACE KARUE   
# REG_NO : SCT211-0573/2022
# Question3: UNIX allows users to be in groups based on their access levels. Write a shell script that given a person's uid, tells you how many times that person is logged on to the system and the time for login

if [ $# -ne 1 ]
then
    echo "Usage: $0 <uid>"
    echo "Please provide a User ID (UID) as an argument"
    exit 1
fi

# store the UID as a command line argument and get username
UID=$1
username=$(id -nu $UID 2> /dev/null)

#check if the UID exist
if !id "$UID" &>/dev/null
then
    echo "Error: The User ID $UID does not exist"
    exit 1
fi

login_count=$(who | grep -c "^$username")

#displaying login info
echo "User Information"
echo "----------------"
echo "Username: $username"
echo "UID" : $UID
echo "Number of times logged in: $login_count"

#displaying login times if logged in
if [ "$login_count" -gt 0 ]; then
    echo -e "\nLogin Details:"
    who | grep "$username" | while read -r line; do
        echo "$line"
    done
else
    echo "User is currently not logged in."
fi
