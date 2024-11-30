#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question 5: Write a script that will convert all of the .jpg files in a given directory into .tiff files. The user should be prompted to enter the file path. The output after conversion should give us the number of images converted.

read -p "Enter the directory path to convert .jpg files to .tiff: " dir

# Expand the ~ to the full home directory path
dir=$(eval echo "$dir")

# Check if the provided directory exists
if [ ! -d "$dir" ]; then
    echo "Error: The directory '$dir' does not exist."
    exit 1
fi

# Initialize the counter for converted images
converted_count=0

# Loop through all the .jpg files in the directory and convert them to .tiff
shopt -s nullglob 
for jpg_file in "$dir"/*.jpg; 
do
    if [ ! -e "$jpg_file" ]; then
        echo "No .jpg files found in the directory."
        exit 1
    fi

    # output file name by replacing .jpg with .tiff
    tiff_file="${jpg_file%.jpg}.tiff"

    # Convert the .jpg file to .tiff using the 'convert' command from ImageMagick
    convert "$jpg_file" "$tiff_file"

    # Check if the conversion was successful
    if [ $? -eq 0 ]; 
    then
        # Increment the counter for each successful conversion
        converted_count=$((converted_count + 1))
        echo "Converted: $jpg_file -> $tiff_file"
    else
        echo "Error converting $jpg_file."
    fi
done


echo "Total number of images converted: $converted_count"

