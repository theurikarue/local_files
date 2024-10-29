/*
    we can use the scanf() function to get input from the user 
    use fgets when you want to take input of a long phrase
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int age;
    double gpa;
    char Grade;
    char name[30];

    printf("Enter your name: ");
    // scanf("%s",&name);
    
    fgets(name,30,stdin); // the problem with fgets is that it prints a new line character when you press enter  

    printf("Enter your age: ");
    scanf("%d",&age);


    printf("Enter your grade: ");
    scanf("%c", &Grade);


    printf("Enter your gpa: ");
    scanf("%lf", &gpa); 


    printf("Your name is %s your current age is %d. You obtained a grade of %c with a GPA of %f", name, age, Grade, gpa);

    return 0;
}