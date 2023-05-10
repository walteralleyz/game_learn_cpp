#include "objects.hpp"
#include "../game_configs.hpp"

void Objects::GameObject::move_forward() {
    if(this->ypos > 10) {
        --this->ypos;
    }
}

void Objects::GameObject::move_back() {
    if(this->ypos < Configs::SCREEN_HEIGHT - this->height) {
        ++this->ypos;
    }
}

void Objects::GameObject::move_left() {
    if(this->xpos > 10) {
        --this->xpos;
    }
}

void Objects::GameObject::move_right() {
    if(this->xpos < Configs::SCREEN_WIDTH - this->width - 10) {
        ++this->xpos;
    }
}

void Objects::GameObject::build_texture() {
    this->texture.loadFromFile(this->image, this->rect);
}

sf::Sprite Objects::GameObject::get_sprite() {
    sf::Sprite sprite;
    sprite.setTexture(this->texture);
    sprite.setPosition(sf::Vector2f(this->xpos, this->ypos));

    return sprite;
}

bool Objects::GameObject::should_destroy() {
    return false;
}