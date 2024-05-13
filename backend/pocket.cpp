#include "pocket.h"

#include <SFML/Graphics.hpp>
#include <vector>

Pocket::Pocket() {
  m_body = new sf::CircleShape(40, 30);
}

Pocket::~Pocket() {
  delete m_body;
  m_body = nullptr;
}

sf::CircleShape* Pocket::getBody() const{
  return m_body;
}