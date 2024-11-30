#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question 4: Write a Shell Script that counts the number of empty folders in a directory (with size=0) 
# and outputs the list of those folders and the time they were created.

if [ $# -eq 0 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Directory to check
directory=$1

# Check if the provided argument is a valid directory
if [ ! -d "$directory" ]; then
    echo "Error: '$directory' is not a valid directory."
    exit 1
fi

# Initialize the counter for empty folders
empty_folder_count=0

# Find empty directories (size=0) and display their creation time using 'ls -ld'
echo "Searching for empty folders in '$directory'..."

# Use 'find' to find empty directories and 'ls -ld' to list their details
find "$directory" -type d -empty -exec ls -ld {} \; | while read -r line; do
    # Increment the counter for empty folders
    empty_folder_count=$((empty_folder_count + 1))
    
    # Extract the folder path and creation time from the 'ls -ld' output
    folder_path=$(echo "$line" | awk '{print $9}')
    creation_time=$(echo "$line" | awk '{print $6, $7, $8}')
    
    # Output the folder path and its creation time
    echo "Empty folder: $folder_path, Created on: $creation_time"
done

# Output the total count of empty folders
echo "Total number of empty folders: $empty_folder_count"
