/*
Name:Theuri Bonface Karue
Reg_No: SCT211-0573/2022
Question 4: Write a program that converts the text in tbe notepad to different colors as follows. 
            Let's use the rainbow colors recursively ...such that   on the colors red, orange, yellow, green, blue, indigo and violet (ROYGBIV).
            ..First line to be  red ....second orange ...7th violet ...and then start the 8 with red etc 
*/

//Include Necessary header files that'll help in the implementation of the program
#include<stdio.h>
#include<string.h>

void print_rainbow_text(const char *line, int color_index){
    //ANSI color codes for ROYGBIV
    const char *colors[]={
        "\033[31m", //Red
        "\033[33m", //Orange (using yellow code)
        "\033[93m", //Yellow (bright yellow)
        "\033[32m", //Green
        "\033[34m", //Blue
        "\033[35m", //Indigo (using magenta code)
        "\033[95m"  //Violet (light magenta)
    };

    //Reset Color code
    const char *reset_color = "\033[0m";

    //print line with the appropriate color
    printf("%s%s\n",colors[color_index],line,reset_color);
}

int main(){

    FILE *output_file = fopen("Theuri.txt","r");
    if(!output_file){
        printf("Error:Cannot open file.\n");
        return 1;
    }

    char line[1024];
    int line_number = 0;

    printf("Rainbow Text Display:\n\n");

    //Read Each line and print with color
    while(fgets(line,sizeof(line),output_file)){
        //Remove Newline Character if present
        line[strcspn(line,"\n")] = 0;


        //Determine color based on line number (0-6)
        int color_index = line_number %7;
        print_rainbow_text(line,color_index);

        line_number++;
    }

    fclose(output_file);
    output_file=NULL;
    return 0;
}