#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "objects/objects.hpp"
#include "scene.hpp"

void wait_user_close(sf::RenderWindow &window);
void wait_input(Objects::SpaceShip &ship);
void create_lasers(std::list<Objects::Laser> &laser_list, Objects::SpaceShip &ship, sf::Sound &effect);
std::list<Objects::Laser> laser_list(std::list<Objects::Laser> &laser_list);

int laser_time = 0;

int main() {
    Scene scene;
    Objects::SpaceBackground background;
    Objects::SpaceShip ship;
    std::list<Objects::Laser> lasers;
    sf::SoundBuffer sound_buffer;
    sf::Sound sound;

    sound_buffer.loadFromFile("./assets/shoot.ogg");
    sound.setBuffer(sound_buffer);

    while(scene.isOpen()) {

        while(scene.is_lagging()) {
            wait_user_close(scene);
            wait_input(ship);
            create_lasers(lasers, ship, sound);

            scene.compact_fps();
            laser_time++;
        }

        lasers = laser_list(lasers);

        scene.clear();
        scene.draw(background.get_sprite());
        scene.draw(ship.get_sprite());

        for(Objects::Laser &laser : lasers) {
            scene.draw(laser.get_sprite());
        }

        scene.display();
    }
}

void wait_user_close(sf::RenderWindow &window) {
    sf::Event event;

    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void wait_input(Objects::SpaceShip &ship) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        ship.move_right();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        ship.move_left();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        ship.move_forward();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        ship.move_back();
    }
}

void create_lasers(std::list<Objects::Laser> &laser_list, Objects::SpaceShip &ship, sf::Sound &effect) {
    for(Objects::Laser &laser : laser_list) {
        laser.move_forward();
    }

    if(laser_time == 50) {
        Objects::Laser laser(ship);

        laser_list.push_front(laser);
        effect.play();

        laser_time = 0;
    }
}

std::list<Objects::Laser> laser_list(std::list<Objects::Laser> &laser_list) {
    std::list<Objects::Laser> temp;
    
    for(Objects::Laser laser : laser_list) {
        if(!laser.should_destroy()) {
            temp.push_back(laser);
        }
    }

    laser_list.clear();

    return temp;
}