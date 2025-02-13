#!/usr/bin/bash

# There are two methods of doing this 
# 1. Basically where you want to redirect the output of echo listed in the script to a file
# 2. Basically where you want to redirect the output of terminal arguments to a file and also append the output to the file

# # Method 1
# echo "Hello World! ... This is an output to an external file using echo command." > 2b-redirect.txt
echo "4. I have now appended this line" >> 2b-redirect.txt


# # Method 2 : using cat command to redirect the output of the terminal arguments to a file
# cat > 2a-redirect_cat.txt # tap ctrl+D to exit the input mode

# # To append the output to the file
# cat >> 2a-redirect_cat.txt

 