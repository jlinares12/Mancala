#include "game.h"

#include <vector>

Game::Game () : m_status(true) {}

Game::Game (bool status) : m_status(status) {}

void Game::CheckStatus (std::vector<std::vector<int>>& Board) {}

bool Game::Status() {
    return m_status;
}