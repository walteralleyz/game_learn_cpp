#include <SFML/Graphics.hpp>
#include "./playable.hpp"
#include "./game_configs.hpp"

void Player::move_right() {
    if(this->xpos < Configs::SCREEN_WIDTH - 10) 
    ++this->xpos;
}

void Player::move_left() {
    if(this->xpos > 10) {
        --this->xpos;
    }
}

void Player::build_texture() {
    this->texture.loadFromFile(this->image, this->rect);
}

sf::Sprite Player::get_sprite() {
    sf::Sprite sprite;
    sprite.setTexture(this->texture);
    sprite.setPosition(sf::Vector2f(this->xpos, this->ypos));

    return sprite;
}