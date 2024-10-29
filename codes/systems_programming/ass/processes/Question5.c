// THEURI BONFACE KARUE
// SCT211-0573/2022
// Question 5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// Function to demonstrate the use of execlp()
void demo_execlp() {
    printf("Demonstrating execlp():\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls -l' using execlp()\n", getpid());
        // execlp searches for 'ls' in PATH and passes arguments as a list
        // Format: execlp(file, arg0, arg1, ..., (char *)NULL)
        execlp("ls", "ls", "-l", NULL);
        // If execlp() is successful, the code below won't be executed
        // If we reach here, execlp() has failed
        perror("execlp");
        exit(1);
    } else {
        // Parent process
        wait(NULL);  // Wait for the child process to complete
        printf("Parent: Child process for execlp() completed\n\n");
    }
}

// Function to demonstrate the use of execle()
void demo_execle() {
    printf("Demonstrating execle():\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'env' with custom environment using execle()\n", getpid());
        char *envp[] = {"CUSTOM_VAR=Hello from execle", NULL};
        // execle uses a list of arguments and allows specifying the environment
        // Format: execle(path, arg0, arg1, ..., (char *)NULL, envp)
        execle("/usr/bin/env", "env", NULL, envp);
        perror("execle");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Child process for execle() completed\n\n");
    }
}

// Function to demonstrate the use of execv()
void demo_execv() {
    printf("Demonstrating execv():\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls -l' using execv()\n", getpid());
        char *args[] = {"ls", "-l", NULL};
        // execv requires full path and uses an array of arguments
        // Format: execv(path, argv)
        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Child process for execv() completed\n\n");
    }
}

// Function to demonstrate the use of execvp()
void demo_execvp() {
    printf("Demonstrating execvp():\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ps aux' using execvp()\n", getpid());
        char *args[] = {"ps", "aux", NULL};
        // execvp searches for 'ps' in PATH and uses an array of arguments
        // Format: execvp(file, argv)
        execvp("ps", args);
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Child process for execvp() completed\n\n");
    }
}

// Function to demonstrate the use of execve()
void demo_execve() {
    printf("Demonstrating execve():\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'env' with custom environment using execve()\n", getpid());
        char *args[] = {"env", NULL};
        char *envp[] = {"CUSTOM_VAR=Hello from execve", NULL};
        // execve requires full path, uses an array of arguments, and allows specifying the environment
        // Format: execve(path, argv, envp)
        execve("/usr/bin/env", args, envp);
        perror("execve");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Child process for execve() completed\n");
    }
}

int main() {
    printf("Demonstrating exec() family system calls\n\n");

    // Call each demonstration function
    demo_execlp();
    demo_execle();
    demo_execv();
    demo_execvp();
    demo_execve();

    return 0;
}
