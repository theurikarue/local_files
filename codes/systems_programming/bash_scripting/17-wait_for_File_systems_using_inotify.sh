#!/bin/bash

# Wait for a file to be created in a directory
mkdir InotifyFolder
inotifywait -m InotifyFolder 
