#include <SFML/Graphics.hpp>
#include "./game_configs.hpp"
#include "./playable.hpp"

void wait_user_close(sf::RenderWindow &window);
void wait_input(Player &player, int xpos);

int main() {
    Player player;

    int width = Configs::SCREEN_WIDTH;
    int height = Configs::SCREEN_HEIGHT;
    char* title = (char*) "Space Super Attack";

    sf::RenderWindow window(sf::VideoMode(width, height), title);
    sf::Clock clock;

    int a = 0;
    double previous = clock.getElapsedTime().asMilliseconds();
    double lag = 0.;

    while(window.isOpen()) {
        double milli = sf::milliseconds(32).asMilliseconds();
        double current = clock.getElapsedTime().asMilliseconds();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        while(lag >= milli) {
            wait_user_close(window);
            wait_input(player, a);

            lag -= milli;
        }

        window.clear();
        window.draw(player.get_sprite());
        window.display();
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

void wait_input(Player &player, int xpos) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move_right();
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move_left();
    }
}