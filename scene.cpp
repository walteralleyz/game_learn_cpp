#include "scene.hpp"

bool Scene::is_lagging() {
    double current = this->clock.getElapsedTime().asMilliseconds();
    double elapsed = current - this->start_time;
    
    this->start_time = current;
    this->lag_time += elapsed;

    return this->lag_time >= this->time_default;
}

void Scene::compact_fps() {
    this->lag_time -= this->time_default;
}