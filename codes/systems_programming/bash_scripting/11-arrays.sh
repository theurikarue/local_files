#!/bin/bash

car=('BMW' 'Toyota' 'Honda' 'Hyundai') #no commas like in other programming languages 
echo "${car[@]}" # prints all elements in the array
echo "${car[0]}" #prints element at index 0
echo "${!car[@]}" #prints the indexes of all the elements in the array
echo "${#car[@]}" #no of elements in array without printing the elements out

 
for index in "${!car[@]}"; do
  echo "Index $index: ${car[$index]}"
done

