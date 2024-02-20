#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player1 {
public:
  Player1();
  Player1(bool turn, int points);
  void Move(int start, std::vector<std::vector<int>> &Board);
  void Print(const std::vector<std::vector<int>> &Board);
  int getPoints(const std::vector<std::vector<int>> &Board);
  bool getTurn();
  bool SwitchTurn();

private:
  bool m_turn;
  int m_points;
};

class Player2 {
public:
  Player2();
  Player2(bool turn, int points);
  void Move(int start, std::vector<std::vector<int>> &Board);
  void Print(const std::vector<std::vector<int>> &Board);
  int getPoints(const std::vector<std::vector<int>> &Board);
  bool getTurn();
  bool SwitchTurn();

private:
  bool m_turn;
  int m_points;
};

#endif