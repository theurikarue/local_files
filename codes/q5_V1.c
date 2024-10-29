#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * This program demonstrates different exec system calls.
 * exec system calls replace the current process with a new process.
 * If the exec function is successful, it does not return.
 * Otherwise, it returns -1 and sets errno.
 */

int main() {
    // Demonstrate execlp()
    printf("Using execlp to list files (execlp):\n");
    // execlp(const char *file, const char *arg0, ..., NULL);
    // Here, execlp takes the command name, followed by arguments, and ends with NULL.
    // It searches the PATH for the command.
    if (fork() == 0) {
        // In child process
        execlp("ls", "ls", "-l", NULL);  // Replace the process with "ls -l"
        perror("execlp failed");  // If exec fails, print error
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Parent waits for child

    // Demonstrate execle()
    printf("\nUsing execle to list files with custom environment (execle):\n");
    // execle(const char *path, const char *arg0, ..., NULL, char *const envp[]);
    // execle allows us to specify a custom environment.
    if (fork() == 0) {
        char *env[] = {"PATH=/bin", NULL};  // Custom environment
        execle("/bin/ls", "ls", "-l", NULL, env);  // Replace process with "ls -l"
        perror("execle failed");  // If exec fails, print error
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Parent waits for child

    // Demonstrate execv()
    printf("\nUsing execv to run a program with arguments (execv):\n");
    // execv(const char *path, char *const argv[]);
    // In execv, we pass the program path and an array of arguments.
    if (fork() == 0) {
        char *args[] = {"ls", "-l", NULL};  // Argument list for execv
        execv("/bin/ls", args);  // Replace process with "ls -l"
        perror("execv failed");  // If exec fails, print error
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Parent waits for child

    // Demonstrate execvp()
    printf("\nUsing execvp to run a program from PATH (execvp):\n");
    // execvp(const char *file, char *const argv[]);
    // execvp searches the PATH for the command and takes the same arguments as execv.
    if (fork() == 0) {
        char *args[] = {"ls", "-l", NULL};  // Argument list for execvp
        execvp("ls", args);  // Replace process with "ls -l"
        perror("execvp failed");  // If exec fails, print error
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Parent waits for child

    // Demonstrate execve()
    printf("\nUsing execve to run a program with custom environment (execve):\n");
    // execve(const char *path, char *const argv[], char *const envp[]);
    // In execve, we pass the program path, arguments, and environment.
    if (fork() == 0) {
        char *args[] = {"ls", "-l", NULL};  // Argument list for execve
        char *env[] = {"PATH=/bin", NULL};  // Custom environment
        execve("/bin/ls", args, env);  // Replace process with "ls -l"
        perror("execve failed");  // If exec fails, print error
        exit(EXIT_FAILURE);
    }
    wait(NULL);  // Parent waits for child

    printf("\nAll exec demos completed.\n");
    return 0;
}
