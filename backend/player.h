#ifndef PLAYER_H
#define PLAYER_H

#include "pocket.h"
#include <vector>

class Player1 {
  public:
    Player1(std::vector<Pocket>& pockets)
      : m_pockets(&pockets),
        m_turn(true),
        m_points(0) {}
    void switchTurn() { m_turn = !m_turn; }
    bool getTurn() {return m_turn; }
    void move(Pocket& start);
    unsigned int getPoints() const;

  private:
    std::vector<Pocket>* m_pockets;
    bool m_turn;
    unsigned int m_points;
};

class Player2 {
  public:
    Player2(std::vector<Pocket>& pockets)
      : m_pockets(&pockets),
        m_turn(false),
        m_points(0) {}
    void switchTurn() { m_turn = !m_turn; }
    bool getTurn() {return m_turn; }
    void move(Pocket& start);
    unsigned int getPoints() const;

  private:
    std::vector<Pocket>* m_pockets;
    bool m_turn;
    unsigned int m_points;
};

#endif