#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question 8: Write a bash that checks the available disk spaces in your drive C and alert the “the space available is ----Mb”

# Get the available disk space in the root directory '/'
available_space=$(df / --output=avail -h | tail -n 1)

echo "The space available is: $available_space"
