#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Player {
  public:
    Player() : m_turn(false), m_points(0) {}
    Player(bool turn, int points) : m_turn(turn), m_points(points) {}
    bool getTurn() { return m_turn; }
    void switchTurn() { m_turn = !m_turn; }
  
  private:
    bool m_turn;
    int m_points;
};

class Player1 : public Player{
public:
  Player1() : Player() {}
  Player1(bool turn, int points) : Player(turn, points) {}
  void Move(int start, std::vector<std::vector<int>> &Board);
  void Print(const std::vector<std::vector<int>> &Board);
  int getPoints(const std::vector<std::vector<int>> &Board);

private:
  bool m_turn;
  int m_points;
};

class Player2 : public Player{
public:
  Player2() : Player() {}
  Player2(bool turn, int points) : Player(turn, points) {}
  void Move(int start, std::vector<std::vector<int>> &Board);
  void Print(const std::vector<std::vector<int>> &Board);
  int getPoints(const std::vector<std::vector<int>> &Board);

private:
  bool m_turn;
  int m_points;
};

#endif