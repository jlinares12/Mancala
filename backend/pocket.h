#ifndef POCKET_H
#define POCKET_H

#include <SFML/Graphics.hpp>
#include <vector>

class Pocket{
  public:
    Pocket();
    ~Pocket();
    sf::CircleShape* body;
  private:
    std::vector<sf::CircleShape*> m_stones;
};

#endif