#include "game.h"

#include <vector>

Game::Game() : m_status(false) {}

Game::Game(bool status) : m_status(status) {}

void Game::CheckStatus(const std::vector<std::vector<int>> &Board) {
  int stones_player1{0};
  int stones_player2{0};

  for (int i = 1; i < 7; i++) {
    stones_player1 += Board.at(i).at(0);
  }
  if (stones_player1 == 0) {
    m_status = false;
  }

  for (int i = 1; i < 7; i++) {
    stones_player2 += Board.at(i).at(1);
  }
  if (stones_player2 == 0) {
    m_status = false;
  }
}

void Game::switchStatus() { m_status = !m_status; }

bool Game::getStatus() { return m_status; }