// THEURI BONFACE KARUE
// SCT211-0573/2022
// Question 4

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH 1024

void print_process_info(const char *pid) {
    char path[MAX_PATH];
    FILE *fp;
    char line[256];
    int ppid = -1, priority = -1;

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    fp = fopen(path, "r");
    if (fp) {
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "PPid:", 5) == 0) {
                sscanf(line, "PPid:\t%d", &ppid);
            } else if (strncmp(line, "Priority:", 9) == 0) {
                sscanf(line, "Priority:\t%d", &priority);
            }
        }
        fclose(fp);
    }

    printf("PID: %s, Priority: %d, Parent PID: %d\n", pid, priority, ppid);
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

int main() {
    DIR *dir;
    struct dirent *ent;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Unable to open /proc");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (is_numeric(ent->d_name)) {
            print_process_info(ent->d_name);
        }
    }

    closedir(dir);
    return 0;
}


