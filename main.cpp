#include "player.h"
#include "game.h"

#include <iostream>
#include <vector>

int main () {
  std::vector<std::vector<int>> Board (8, std::vector<int>(2));               //sets up blank board
  for (int i = 0; i < 8; i++) {                                               //start of game sets board up with 4 stones in each playable pocket
    for (int j = 0; j < 2; j++) {
      if (i == 0 || i == 7) {
        continue;
      }
      Board.at(i).at(j) = 4;
    }
  }

  Player player1(true, 0);
  Player player2(false, 0);
  int pocket{0};
  Game game(true);

  while (game.Status()) {
    while (player1.Turn()) {
      player1.Print1(Board);
      std::cout << "Player 1 turn\n";
     std::cout << "Please enter number of pocket to play: ";
      std::cin >> pocket;
      player1.Move1(pocket, Board);
      player1.Print1(Board);
      player1.SwitchTurn();
      player2.SwitchTurn();
    }

    game.CheckStatus(Board);

    while (player2.Turn()) {
      player2.Print2(Board);
      std::cout << "Player 2 turn\n";
      std::cout << "Please enter number of pocket to play: ";
      std::cin >> pocket;
      player2.Move2(pocket, Board);
      player2.Print2(Board);
      player1.SwitchTurn();
      player2.SwitchTurn();
    }

    game.CheckStatus(Board);
  }
}