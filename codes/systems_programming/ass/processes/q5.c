#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Listing all processes with their PID, PPID, and priority:\n");

    // Execute the "ps" command with custom output format
    execlp("ps", "ps", "-o", "pid,ppid,pri,comm", NULL);

    // If execlp fails, print an error message
    perror("execlp failed");
    return 1;
}
