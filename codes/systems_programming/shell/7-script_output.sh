#!/bin/bash

# 1 prints out the std output while 2 prints out the std error
# ls -al 1>7a-output.txt 2>7b-error.txt 
# ls +al 1>7a-output.txt 2>7b-error.txt

# when you don't want to specify and would like both the output and error to be printed out in the same file
# ls -al > 7c-output_both.txt 2>&1 
ls -al >& 7c-output_both.txt 