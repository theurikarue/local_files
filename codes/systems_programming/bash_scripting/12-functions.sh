#!/bin/bash
function fun(){
    echo "This is a new function"
}
fun # call the function without the brackets


# giving arguments
function greet(){
    echo $1 $2 # or $1 but have a string instead ('Hi Theuri')
}
greet Hi Theuri

#eg3 introducing local and global variables
function funcheck(){
    returnValue="Using this function right now ..." #local variable
    echo $returnValue
}
returnValue="This will be shown first ..."
echo $returnValue
funcheck








