#ifndef STONE_H
#define STONE_H

#include <SFML/Graphics.hpp>

class Stone {
  public:
    Stone();
   ~Stone();
   sf::CircleShape* body;
  private:
    float x_speed;
    float y_speed;
};

#endif