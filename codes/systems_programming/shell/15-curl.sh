#!/bin/bash

url="https://proof.ovh.net/files/1Mb.dat"
curl ${url} -O #Will save file with same name 
#saving file you've downloaded with a different name
# curl ${url} -o 15a-newfile_o.dat #method 1 
# curl ${url} > 15b-newfile_angle.dat # method 2
# curl ${url} --output newfile_output.dat # method 3


#checking the headers  
curl -I ${url}

