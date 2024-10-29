#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI color codes for rainbow colors
const char *rainbow_colors[] = {
    "\033[31m",  // Red
    "\033[38;5;214m",  // Orange
    "\033[33m",  // Yellow
    "\033[32m",  // Green
    "\033[34m",  // Blue
    "\033[38;5;54m",  // Indigo
    "\033[35m"   // Violet
};

#define NUM_COLORS 7
#define RESET_COLOR "\033[0m"

int main() {
    // Open original file
    FILE *input = fopen("Theuri.txt", "r");
    if (!input) {
        printf("Error opening Theuri.txt!\n");
        return 1;
    }

    // Create colored version
    FILE *output = fopen("Theuri_colored.txt", "w");
    if (!output) {
        printf("Error creating colored file!\n");
        fclose(input);
        return 1;
    }

    char line[1024];
    int line_count = 0;

    // Process each line
    while (fgets(line, sizeof(line), input)) {
        // Remove newline if present
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        if (strlen(line) > 0) {
            int color_index = line_count % NUM_COLORS;
            fprintf(output, "%s%s%s\n", 
                    rainbow_colors[color_index],
                    line,
                    RESET_COLOR);
        } else {
            fprintf(output, "\n");
        }
        line_count++;
    }

    fclose(input);
    fclose(output);

    printf("Colored version has been created as 'Theuri_colored.txt'\n");
    printf("To view the colors, use: cat Theuri_colored.txt\n");
    return 0;
}
