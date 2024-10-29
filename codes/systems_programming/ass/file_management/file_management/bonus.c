#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void play_mp3_file(const char *file_path) {
    Mix_Music *music = Mix_LoadMUS(file_path);
    if (!music) {
        fprintf(stderr, "Error: Could not load %s - %s\n", file_path, Mix_GetError());
        return;
    }

    // Play the loaded music
    if (Mix_PlayMusic(music, 1) == -1) {
        fprintf(stderr, "Error: Could not play %s - %s\n", file_path, Mix_GetError());
        Mix_FreeMusic(music);
        return;
    }

    // Wait until the music finishes playing
    while (Mix_PlayingMusic()) {
        SDL_Delay(100);  // Delay to prevent CPU overuse
    }

    // Free the music after it finishes playing
    Mix_FreeMusic(music);
}

int main(int argc, char *argv[]) {
    // Initialize SDL and SDL_mixer
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Error: SDL could not initialize - %s\n", SDL_GetError());
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        fprintf(stderr, "Error: SDL_mixer could not initialize - %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    // Open the file with the list of .mp3 files
    FILE *file = fopen("Theuri.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open Theuri.txt\n");
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    char file_path[1024];
    printf("Starting to play files listed in Theuri.txt...\n");

    // Read each line in the file and play the corresponding mp3
    while (fgets(file_path, sizeof(file_path), file)) {
        // Remove newline character if present
        file_path[strcspn(file_path, "\n")] = 0;

        // Play the mp3 file
        printf("Playing: %s\n", file_path);
        play_mp3_file(file_path);
    }

    // Cleanup
    fclose(file);
    Mix_CloseAudio();
    SDL_Quit();

    printf("Playback finished.\n");
    return 0;
}

