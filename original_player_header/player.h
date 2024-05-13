#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Player {
  public:
    Player() : m_turn(false) {}
    Player(bool turn) : m_turn(turn) {}
    bool getTurn() { return m_turn; }
    void switchTurn() { m_turn = !m_turn; }
  
  private:
    bool m_turn;
};

class Player1 : public Player{
public:
  Player1() : Player() {}
  Player1(bool turn) : Player(turn) {}
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
  Player2(bool turn) : Player(turn) {}
  void Move(int start, std::vector<std::vector<int>> &Board);
  void Print(const std::vector<std::vector<int>> &Board);
  int getPoints(const std::vector<std::vector<int>> &Board);

private:
  bool m_turn;
  int m_points;
};


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

  Player1 player1(true);
  Player2 player2(false);
  int pocket{0};
  Game game(true);

  while (game.Status()) {
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
      if (!game.Status()) {
        break;
      }
      player1.switchTurn();
    }

    player2.switchTurn();
    if (!game.Status()) {
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
      if (!game.Status()) {
        break;
      }
      player2.switchTurn();
    }

    player1.switchTurn();
  }
#endif