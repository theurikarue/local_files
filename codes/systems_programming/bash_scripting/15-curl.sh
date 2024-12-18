#!/bin/bash

url="https://proof.ovh.net/files/1Mb.dat"
# curl ${url} -O # -O is used to save the file with the same name as the remote file
# curl ${url} -o rename # -o is used to save the file with a different name
# curl ${url} > rename2 # > is used to save the file with a different name
curl -I ${url} # -I is used to get the headers of the file
