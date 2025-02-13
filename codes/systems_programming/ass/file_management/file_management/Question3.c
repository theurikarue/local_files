/*
Name:Theuri Bonface Karue
Reg_No: SCT211-0573/2022
Question 3: Write a C program that search and list the name and sizes of all files with extension .mp3 in  your drive C .The program should further print a notepad of the output in C saved with Yourname.txt
*/

//Include Necessary header files that'll help in the implementation of the program
#include<stdio.h>
#include<dirent.h> //For directory manipulation
#include<string.h> //For string manipulation
#include<sys/stat.h> // For gettign file information including file size


void find_mp3_files(const char *dir, FILE *output_file){
    DIR *d = opendir(dir);
    struct dirent *entry;
    char path[512];


    if (!d) return;

    while ((entry=readdir(d))){
        //skip . and .. directories
        if(entry->d_name[0]=='.')continue;

        //create full path
        snprintf(path,sizeof(path), "%s/%s", dir, entry->d_name);

        if(entry->d_type == DT_DIR){Write a C program that search and list the name and sizes of all files with extension .mp3 in  your drive C .The program should further print a notepad of the output in C saved with Yourname.txt
*/

            find_mp3_files(path,output_file);
        }else{
            //Check if file ends with .mp3
          char *ext = strrchr(entry->d_name,'.');
          if(ext && strcasecmp(ext,".mp3")==0){
            //Get and Print file sizes
            struct stat file_stat;
            if(stat(path,&file_stat)==0){
                double size_mb = file_stat.st_size / (1024.0 * 1024.0);
                fprintf(output_file,"File: %s (%.2f MB)\n",path,size_mb);
                printf("Found: %s (%.2f MB)\n",path,size_mb);
            } 
          }
        }
    }
    closedir(d);
}

int main(){

    FILE *output_file = fopen("Theuri.txt","w");
    if(!output_file){
        printf("Error:Cannot creat output file\n");
        return 1;
    }

    printf("Searching for mp3 files ... \n\n");
    find_mp3_files("/",output_file);

    fclose(output_file);
    output_file=NULL;
    printf("\nSearch complete! Results saved in Theuri.txt file\n");
    return 0;
}