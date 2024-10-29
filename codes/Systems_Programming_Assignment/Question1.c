// THEURI BONFACE KARUE
// SCT211-0573/2022
// Question 1

# include <stdio.h>
# include <unistd.h>

int main(){
    int c = 5;
    __pid_t pid = fork();
    if (pid == 0){
        c += 5;
    } else{
        c += 10;
        if(pid){
            c+=10;
        }
    }
    fork();
    printf("%d\n", c);
}

