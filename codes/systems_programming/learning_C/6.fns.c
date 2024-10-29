/*
    Prototyping enbales us to write a function beneath the main function
*/

#include <stdio.h>
#include <stdlib.h>

// eg of what prototyping is
void SayHi(char Name[10]); 
double Cube(double num);
int Max (int num1,int num2,int num3);

int main (){
    SayHi("254Bonface\n");
    Cube(3.0);
    Max(1,2,3);

    return 0;
}

void SayHi(char Name[10]){
    printf("Hello %s", Name);
}

double Cube(double num){
    double result = num*num*num;
    return printf("The cube is %f\n",result);
}

int Max(int num1,int num2,int num3){
    int result;
    if(num1>num2 && num1>num3){
        result=num1;
    } else if(num2>num1 && num2>num3 ){
        result=num2;
    } else{
        result = num3;
    }
    return printf("The largest of the three is %d",result);
}