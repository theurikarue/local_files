#!/bin/bash
#The declare command in Bash is used to set variables and attributes for variables. 
# It allows you to define variables with specific properties like being read-only, integers, arrays, or even exporting them to the environment.

# declare -p - run that command on terminal

# These are the various options
: '
-r	Makes a variable read-only (cannot be modified).
-i	Treats a variable as an integer (arithmetic operations can be performed).
-a	Declares a regular array variable.
-A	Declares an associative array variable (key-value pairs).
-x	Exports a variable to the environment for child processes.
-l	Converts the variables value to lowercase.
-u	Converts the variables value to uppercase.
-p	Displays all variables with their attributes.
'


declare -r pwdfile=/etc/passwd
echo $pwdfile

$pwdfile=/etc/abc.txt
echo $pwdfile