#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Define the command to execute
    const char *command = "ls"; // List directory contents

    // Example using execlp()
    printf("Using execlp():\n");
    // execlp() takes the command and arguments as separate parameters
    execlp(command, command, "-l", NULL); // Execute 'ls -l'
    // If execlp() is successful, this line will not be executed
    perror("execlp failed"); // Print error if execlp() fails

    // Example using execle()
    printf("Using execle():\n");
    // execle() takes the command path, arguments, and environment variables
    char *envp[] = { "HOME=/usr/home", "USER=unknown", NULL };
    execle("/bin/ls", command, "-l", NULL, envp); // Execute 'ls -l' with env
    perror("execle failed"); // Print error if execle() fails

    // Example using execv()
    printf("Using execv():\n");
    // execv() takes the command path and an array of arguments
    char *args_v[] = { command, "-l", NULL };
    execv("/bin/ls", args_v); // Execute 'ls -l'
    perror("execv failed"); // Print error if execv() fails

    // Example using execvp()
    printf("Using execvp():\n");
    // execvp() takes the command and an array of arguments
    char *args_vp[] = { command, "-l", NULL };
    execvp(command, args_vp); // Execute 'ls -l'
    perror("execvp failed"); // Print error if execvp() fails

    // Example using execve()
    printf("Using execve():\n");
    // execve() takes the command path, arguments, and environment variables
    char *args_e[] = { command, "-l", NULL };
    execve("/bin/ls", args_e, envp); // Execute 'ls -l' with env
    perror("execve failed"); // Print error if execve() fails

    return 0; // End of the program
}
