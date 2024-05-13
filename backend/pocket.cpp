#ifndef pocket_cpp
#define pocket_cpp

#include <SFML/Graphics.hpp>
#include <vector>

class Pocket : public sf::CircleShape {
  public:
    Pocket(): m_body(sf::CircleShape(40,30)) {}
    sf::CircleShape& getBody() {return this->m_body;}
  private:
  sf::CircleShape m_body;
  std::vector<sf::CircleShape*> m_stones;
};

#endif