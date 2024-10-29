/*
Name:Theuri Bonface Karue
Reg_no:SCT211-0573/2022
Question1 : Write a program that takes integer input from a user and stores it in a notepad file(Kenya.txt) stored in any location in your drive.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    // Dec;aring variables to be used
    FILE *int_file;
    int number;

    //Taking input from user 
    printf("Hello, kindly enter an integer of your choice: ");
    scanf("%d",&number);

    // Opening the file in write mode 
    int_file=fopen("Kenya.txt","w");

    // Checking whether file has been opened successfully 
    if (int_file==NULL){

        printf("An error occured while opening file in write mode");
        printf("\n Make sure you have the appropriate permissions and try opening the file again");

        return 1;
    }

    fprintf(int_file,"%d",number);
    
    fclose(int_file);

    printf("\nYou have successfully written onto the Kenya.txt file");
    return 0;
}
