#ifndef POCKET_H
#define POCKET_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "stone.h"

class Pocket{
  public:
    Pocket();
    ~Pocket();
    sf::CircleShape* body;
    std::vector<Stone>& getStones() const{
      return *m_stones;
    }

  private:
    std::vector<Stone>* m_stones;
};

#endif