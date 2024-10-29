/*
Name:Theuri Bonface Karue 
Reg_No:SCT211-0573/2022
Question 2: Write another C program that reads the integer present in the Kenya.txt file and prints it onto the screen 
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *int_file;
    int number;

    // OPENING FILE IN READ MODE 
    int_file=fopen("Kenya,txt","r");

    // Checking whether the file has been opened successfully
    if (int_file==NULL){    
        printf("An error occured while trying to open the file in read mode.");
    }
    
    fscanf(int_file,"%d",&number);

    fclose(int_file);

        printf("The integer written on the Kenya.txt file is %d ",number);
    return 0;
}