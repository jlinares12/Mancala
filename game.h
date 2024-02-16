#ifndef GAME_H
#define GAME_H

#include <vector>
class Game {
  private:
    bool m_status;

  public:
    Game ();
    Game (bool status);
    void CheckStatus(const std::vector<std::vector<int>>& Board);
    void switchStatus();
    bool getStatus ();
};

#endif