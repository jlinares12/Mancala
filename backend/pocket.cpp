#include "pocket.h"

#include <SFML/Graphics.hpp>
#include <vector>

Pocket::Pocket() {
  m_stones = new std::vector<Stone>(4);
  body = new sf::CircleShape(40, 30);
}

Pocket::~Pocket() {
  delete body;
  delete m_stones;

  m_stones = nullptr;
  body = nullptr;
}
