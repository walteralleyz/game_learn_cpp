#ifndef OBJECTS
#define OBJECTS

#include <SFML/Graphics.hpp>
#include "../game_configs.hpp"

namespace Objects {

    class GameObject {

        public:
            int xpos;
            int ypos;
            int width;
            int height;
            char* image;

            sf::Texture texture;
            sf::IntRect rect;

            GameObject(int x, int y, char* image, int width, int height) {
                this->xpos = x;
                this->ypos = y;
                this->image = image;
                this->width = width;
                this->height = height;
                this->rect = sf::IntRect(0, 0, this->width, this->height);

                this->build_texture();
            }

            void move_forward();
            void move_back();
            void move_left();
            void move_right();
            void build_texture();
            sf::Sprite get_sprite();
            bool should_destroy();
    };

    class SpaceShip : public GameObject {

        public:
            SpaceShip() : GameObject(
                (Configs::SCREEN_WIDTH / 2) - 15,
                Configs::SCREEN_HEIGHT - 31 * 2,
                (char*) "./assets/ship.png",
                45, 31) {}
    };

    class Laser : public GameObject {

        public:
            Laser(SpaceShip &ship) : GameObject(
                ship.xpos + 15,
                ship.ypos - 31,
                (char*) "./assets/m_lsr.png",
                14,
                24
            ) {}

            bool should_destroy() {
                return this->ypos == 10;
            }
    };

    class SpaceBackground : public GameObject {

        public:
            SpaceBackground() : GameObject(
                0, 0, 
                (char*) "./assets/space.png", 
                Configs::SCREEN_WIDTH,
                Configs::SCREEN_HEIGHT) {}
    };
}

#endif