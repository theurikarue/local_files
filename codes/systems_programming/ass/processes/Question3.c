// THEURI BONFACE KARUE
// SCT211-0573/2022
// Question 3

# include <stdio.h>
# include <unistd.h>

int main(){
    __pid_t pid = fork();
    
    if (pid == 0){
        printf("Niko JUja\n");
    } else{
        // Lets Parent Process sleep for 1 second
        for(int p=0; p<1; p++){
            sleep(1);
        };
        printf("ICS2305 ni softlife");
    }
    return 0;
}
