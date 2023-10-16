/*
    gcc main.cpp `sdl2-config --cflags --libs` -lstdc++
    ou
    gcc main.cpp -o main -lSDL2 -lstdc++
    export DISPLAY=:0

    ./main
*/

#include <SDL2/SDL.h>
#include <ostream>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Gestion de l'erreur en cas d'échec
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Exemple SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        // Gestion de l'erreur en cas d'échec
        std::cerr << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Boucle principale
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        // Gestion des événements
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Nettoyage et sortie
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
