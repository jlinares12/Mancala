#include "pocket.h"

#include <SFML/Graphics.hpp>
#include <vector>

Pocket::Pocket() {
  for (auto& stone : m_stones) {
    stone = nullptr;
  }
  
  body = new sf::CircleShape(40, 30);
}

Pocket::~Pocket() {
  delete body;
  body = nullptr;
}
