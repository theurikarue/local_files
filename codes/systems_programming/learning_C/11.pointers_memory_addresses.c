// using modulus p
// Pointers can simply be looked at as a data types that stores memory addresses 

#include<stdio.h>
#include<stdlib.h>

int main(){
    int age = 21;
    int *pAge = &age;

    char grade = 'A';
    char *pGrade = &grade;
    
    double gpa = 3.9;
    double *pGpa = &gpa;


    printf("age: %p\ngpa: %p\ngrade: %p\n",&age,&gpa,&grade);

    // DEREFERENCING A POINTER - *ptr_name
    printf("%d\n",*pAge);
    printf("%p",&age);
    printf("%d",*&age);
    // printf("%d",&*&age);
    // printf("%d",*&*&age);

    return 0;
}