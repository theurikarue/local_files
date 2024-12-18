#!/bin/bash
# using select command 
# to create a simple menu

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



# eg3
echo "Press any key to continue"
while [ true ]
do 
    read -t 3 -n 1
    if [ $? = 0 ]
    then 
        echo "You've terminated the script"
        exit;
    else 
        echo "Waiting for you to press the key sir"
    fi
done







