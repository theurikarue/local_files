// Working with files
#include<stdio.h>
#include<stdlib.h>

int main(){

    char Line [255];
    // FILE *fptr = fopen("employees.txt","w"); // for writing
    // FILE *fptr = fopen("employees.txt","a"); // for appending
    FILE *fptr = fopen("employees.txt","r"); // for reading


    // fprintf(fptr,"Theuri - CEO\nPam - Receptionist\nDaniel - CTO\nOscar - Accounting\n");
    // fprintf(fptr,"Kelly- Customer Service");
    fgets(Line,255,fptr);
    printf("%s",Line);
    fgets(Line,255,fptr);
    printf("%s",Line);
    fgets(Line,255,fptr);
    printf("%s",Line);
    fgets(Line,255,fptr);
    printf("%s",Line);


    fclose(fptr);
    return 0;
}

