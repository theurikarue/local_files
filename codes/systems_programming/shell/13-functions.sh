#!/bin/bash

function fun() {
    echo "This is a function"
}
# fun  #This is how you call a function

# Using arguments
function funOne() {
    echo "This is a function with arguments"
    echo $1 $2
}
funOne Hello World #<hello and world are the two arguments>This is how you call a function with arguments


#global and local variables
function check(){
    returnValue="Using function right now ..."
    echo $returnValue
} #The variable is exclusive for this block
returnValue="This is a global variable"
echo $returnValue
check














