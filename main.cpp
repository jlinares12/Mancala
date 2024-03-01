#include "game.h"
#include "player.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
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
      std::cout
          << "Please enter the number (between 1 - 6) of a pocket to play: ";
      std::cin >> pocket;

      while (std::cin.fail()) { // Checks to see that user inputed an int
        std::cout << "Sorry brosky but you have to enter a number. \nTry again."
                  << std::endl;
        std::cin.clear(); // This line clears the error flags on std::cin,
                          // allowing further input operations to be attempted.
        std::cin.ignore(256, '\n'); // This line clears the input buffer up to the
                                    // next newline character or up to 256 characters
        player1.Print(Board);
        std::cin >> pocket;
      }

      while ((pocket == 0 || pocket == 7) ||
             (pocket < 0 ||
              pocket > 7)) { // makes sure number is in playable range
        std::cout << "You have to pick a number between 1 and 6!\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        player1.Print(Board);
        std::cin >> pocket;
      }

      if (Board.at(pocket).at(0) == 0) { // player must have stones to play
        std::cout << "You gotta pick a pocket with stones silly!\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
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

      while (std::cin.fail()) {
        std::cout << "Sorry brosky but you have to enter a number. \nTry again."
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        player2.Print(Board);
        std::cin >> pocket;
      }

      while ((pocket == 0 || pocket == 7) || (pocket < 0 || pocket > 7)) {
        std::cout << "You have to pick a number between 1 and 6!\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        player2.Print(Board);
        std::cin >> pocket;
      }

      if (Board.at(pocket).at(1) == 0) {
        std::cout << "You gotta pick a pocket with stones silly!\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
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