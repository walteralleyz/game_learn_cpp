#ifndef SCENE
#define SCENE

#include <SFML/Graphics.hpp>
#include "game_configs.hpp"

class Scene : public sf::RenderWindow {

    private:
        sf::Clock clock;
        double start_time;
        double lag_time;
        double time_default;

    public:
        Scene():sf::RenderWindow(
            sf::VideoMode(Configs::SCREEN_WIDTH, Configs::SCREEN_HEIGHT),
            (char*) "Super Space Attack"
        ) {
            this->clock = sf::Clock();
            this->start_time = this->clock.getElapsedTime().asMilliseconds();
            this->time_default = sf::milliseconds(10).asMilliseconds();
            this->lag_time = 0.;
        }

        bool is_lagging();
        void compact_fps();

};

#endif