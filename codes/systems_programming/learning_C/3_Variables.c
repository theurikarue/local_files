/*
Examples of variables in C include char, int, float, double, void, bool and user defined objects
Rules in naming variables:
    1. The variable name must not begin with a digit 
    2. 0Variable name can consist of digits, alphabets and even special symbols such as an underscore
    3. Variable name must not contain any keywords eg int, float
    4. No spaces or blanks in the var name 
    5. Case sensitivity
    6. Have meaningful names 
Classification of variables in C:
    1. Global Variable - Variable that gets defined outside a block or function
    2. LOcal Variable - one that's defined inside a block or function
    3. Automatic variable - any variable that is declared inside a block (in C lang) is be default automatic in nature 
    4. Static Variable - any variable that's declared using the static Variable.
    5. External Variable - A user will be capable of sharing a variable in multiple source files in C if they use external variable eg extern int a=10 
Naming conventions:    
    1. camelCase - words ar joined together and each word's first letter except the first one is capitalized mostly java, JS, C# eg useState
    2. Pascal - Similar to camelCase but the first letter of the word is also capitalized. mostly for classes, interfaces C#, C++, Swift eg class Student
    3. snake_case - Words are separated by underscores with all as lowercase letters mostly for variables constants and sometimes fns eg character_name
    4. kebab-case - similar to snake_case but instead of underscores hyphens are used mostly for URLs, HTML attributes and CSS classes eg kebab-case-example

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[5]="John";
    int age = 30;

    printf("There once was a man name %s who was %d years old\n", name, age);
    
    age = 21;
    char campus[]="JKUAT";
    printf("There once was a student named %s who was %d years old studying at %s", name, age, campus);

}