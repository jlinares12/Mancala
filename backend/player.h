#include "pocket.cpp"

class Player1 {
  public:
    Player1(bool turn, std::vector<Pocket>& pockets) : m_pockets(pockets), m_turn(turn),  m_points(0) {}
    void print(sf::RenderWindow* main_window) {
      for (const auto& pocket : m_pockets) {
        main_window->draw(pocket);
      }
    }
    void switchTurn() { m_turn = !m_turn; }
    bool getTurn() {return m_turn; }
    void move(Pocket* start);
    unsigned int getPoints() const;

  private:
    std::vector<Pocket> m_pockets;
    bool m_turn;
    unsigned int m_points;
};

class Player2 {
  public:
    void move(Pocket* start);
    unsigned int getPoints() const;
};