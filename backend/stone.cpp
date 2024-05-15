#include "stone.h"

Stone::Stone() {
  body = new sf::CircleShape(25, 30);
  body->setPosition(360, 120);
  x_speed = 0;
  y_speed = 0;
}

Stone::~Stone() {
    delete body;
    body = nullptr;
}