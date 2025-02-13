#! /bin/bash

# no commas between the elements
car=('BMW' 'Toyota' 'Honda' 'Ford' 'Nissan' 'Rover') # array declaration
echo "${car[@]}"
unset car[2] # removes the 3rd element from the array = Honda
echo "${car[@]}"
car[2]='Mercedes' # adds a new element to the array to the second index
echo "${car[@]}"
echo "${car[0]}" # prints the first element of the array = BMW
echo "${!car[@]}" # prints the indices of the array = 0 1 2 3 4 5
echo "${#car[@]}" # prints the length of the array = 6





