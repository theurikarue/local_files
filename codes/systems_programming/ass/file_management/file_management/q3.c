#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void searchMP3Files(const char *basePath, FILE *outputFile) {
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    struct stat filestat;

    // Unable to open directory
    if (!dir) {
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        // Skip null names and current/parent directory entries
        if (!dp->d_name || strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        // Ensure we don't exceed buffer size
        if (strlen(basePath) + strlen(dp->d_name) + 2 > sizeof(path)) {
            printf("Path too long: %s/%s\n", basePath, dp->d_name);
            continue;
        }

        // Construct new path safely
        snprintf(path, sizeof(path), "%s/%s", basePath, dp->d_name);

        // Get file stats
        if (stat(path, &filestat) == 0) {
            // If it's a directory, recurse
            if (S_ISDIR(filestat.st_mode)) {
                searchMP3Files(path, outputFile);
            }
            // If it's a file, check extension
            else {
                size_t name_len = strlen(dp->d_name);
                if (name_len > 4) {  // Minimum length for ".mp3"
                    const char *ext = dp->d_name + name_len - 4;
                    if (strcasecmp(ext, ".mp3") == 0) {
                        // Convert size to MB with 2 decimal places
                        double size_mb = (double)filestat.st_size / (1024 * 1024);
                        fprintf(outputFile, "File: %s\nSize: %.2f MB\n\n", path, size_mb);
                        printf("File: %s\nSize: %.2f MB\n\n", path, size_mb);
                    }
                }
            }
        }
    }

    closedir(dir);
}

int main() {
    char *homedir = getenv("HOME");
    if (!homedir) {
        printf("Error: Cannot get home directory!\n");
        return 1;
    }

    FILE *outputFile = fopen("Theuri.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output file!\n");
        return 1;
    }

    fprintf(outputFile, "MP3 Files Found in System:\n\n");
    printf("Searching for MP3 files...\n\n");

    // Start search from home directory
    searchMP3Files(homedir, outputFile);

    fclose(outputFile);
    printf("\nSearch complete! Results have been saved to Theuri.txt\n");
    return 0;
}
