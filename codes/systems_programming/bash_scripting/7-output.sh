# !/bin/bash

ls -al 1>output1.txt 2>output2.txt #1 is for stdin while 2 is for stderr since there are no errors file2 won't have anything  
# ls +al 1>output1.txt 2>output2.txt # Make an intentional error  

# if you don't want two files then you can use this command 
# ls -al >outputboth.txt 2>&1
# ls +al >outputboth.txt 2>&1
# shortcut
ls -al >& outputshortcut.txt

# ps >&processes.txt
ps -u 1>processes_user.txt
