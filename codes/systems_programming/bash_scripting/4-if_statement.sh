#! /bin/bash


: '
#First Scenario
count=10

#first condition
# if [ $count -eq 10 ]
# then
#     echo "The condition is True"
# else 
#     echo "This condition is False"
# fi

#second condition
if (( $count < 9 ))
then 
    echo "First condition is True"
elif (( $count > 9 ))
then 
    echo "Second Condition is True "
else 
    echo "The conditon is False"
fi
'

#second scenario
age=10
if [ $age -gt 18 ] && [ $age -lt 35 ]
then 
    echo "You are a youth"
else 
    echo "You aren't a youth"
fi

