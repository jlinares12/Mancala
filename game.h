#ifndef GAME_H
#define GAME_H

class Game {
  private:
    bool m_status;

  public:
    Game () {}
    Game (bool status) : m_status(status) {}
    void CheckStatus(std::vector<std::vector<int>>& Board) {}
};

#endif