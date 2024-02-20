#include "game.h"
#include "player.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> Board(
      8, std::vector<int>(2));  // sets up blank board
  for (int i = 0; i < 8; i++) { // start of game sets board up with 4 stones in
                                // each playable pocket
    for (int j = 0; j < 2; j++) {
      if (i == 0 || i == 7) {
        continue;
      }
      Board.at(i).at(j) = 4;
    }
  }

  Player1 player1(true, 0);
  Player2 player2(false, 0);
  int pocket{0};
  Game game(false);

  while (!game.getStatus()) {
    std::string menu;
    std::cout << "HELLO! Welcome to my very low level version of Mancala.\n";
    std::cout << "Whenever you're ready to play just type \"start\".\n";
    std::cin >> menu;

    if (menu == "start") {
      game.switchStatus();
    }
  }

  while (game.getStatus()) {
    while (player1.getTurn()) {
      player1.Print(Board);
      std::cout << "Player 1 turn\n";
      std::cout << "Please enter number of pocket to play: ";
      std::cin >> pocket;
      if (Board.at(pocket).at(0) == 0) {
        std::cout << "You gotta pick a pocket with stones silly!\n";
        continue;
      }
      player1.Move(pocket, Board);
      player1.Print(Board);
      game.CheckStatus(Board);
      if (!game.getStatus()) {
        break;
      }
      player1.SwitchTurn();
    }

    player2.SwitchTurn();
    if (!game.getStatus()) {
      break;
    }

    while (player2.getTurn()) {
      player2.Print(Board);
      std::cout << "Player 2 turn\n";
      std::cout << "Please enter number of pocket to play: ";
      std::cin >> pocket;
      if (Board.at(pocket).at(1) == 0) {
        std::cout << "You gotta pick a pocket with stones silly!\n";
        continue;
      }
      player2.Move(pocket, Board);
      player2.Print(Board);
      game.CheckStatus(Board);
      if (!game.getStatus()) {
        break;
      }
      player2.SwitchTurn();
    }

    player1.SwitchTurn();
  }
}