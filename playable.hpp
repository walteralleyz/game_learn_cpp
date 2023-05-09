#ifndef PLAYABLE
#define PLAYABLE

#include <SFML/Graphics.hpp>
#include "./game_configs.hpp"

class Player {
    public:
        int ypos;
        int xpos;
        char* image;

        sf::IntRect rect;
        sf::Texture texture;

        Player() {
            this->ypos = Configs::SCREEN_HEIGHT - 31*2;
            this->xpos = (Configs::SCREEN_WIDTH / 2) - 15;
            this->image = (char*) "./assets/ship.png";
            this->rect = sf::IntRect(0, 0, 45, 31);

            this->build_texture();
        }

        void move_right();
        void move_left();
        void build_texture();
        sf::Sprite get_sprite();
};

#endif