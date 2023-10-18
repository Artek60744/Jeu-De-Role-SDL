// gcc main2.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
// export DISPLAY=:0
// ./main
#include "header.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(HAUTEUR, LARGEUR), "Afficher une image");

    // Charger une texture (une image)
    sf::Texture texture;
    if (!texture.loadFromFile("images/personnages/ichigo1.png")) {
        // Gestion des erreurs si le chargement de l'image échoue
        return -1;
    }

    // Créer un sprite à partir de la texture chargée
    sf::Sprite sprite(texture);

    // Boucle principale du programme
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Effacer l'écran
        window.clear();

        // Dessiner le sprite
        window.draw(sprite);

        // Rafraîchir l'écran
        window.display();
    }

    return 0;
}

