#! /bin/bash

# This script is a professional menu for the user to choose from
: '
select car in BMW Mercedes Tesla Rover Toyota
do 
    echo "You have selected $car"
done
'


# eg 2
: '
select car in BMW Mercedes Tesla Rover Toyota
do 
    case $car in 
        BMW)
            echo "BMW selected";;
        Mercedes)
            echo "Mercedes selected";;
        Tesla)
            echo "Tesla selected";;
        Rover)
            echo "Rover selected";;
        Toyota) 
            echo "Toyota selected";;
        *)
            echo "Error: Please try again (select 1..5)";;
    esac
done
'


while [ true ]
do 
    read -t 3 -n 1
if [ $? = 0 ]
then 
    echo "You have terminated the script"
else 
    echo "Waiting for you to press the key sir"
fi
done
