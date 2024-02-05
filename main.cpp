#include <iostream>
#include <vector>

class Player {
  private://variables
    int m_start{1};
    bool m_turn{false};
    int m_points{0};

  public:
    bool Turn() {
      return m_turn;
    }

    Player (bool turn, int points) {
      m_turn = turn;
      m_points = points;
    }

    void Move1(int start, std::vector<std::vector<int>>& Board) {        //takes in which pocket the player chooses to play & current state of board
      int amount_stones {Board.at(start).at(0)};                                //sets up the limit of stones you can place on the board = #stones in pocket
      Board.at(start).at(0) = 0;                                                //sets pocket played to 0
  
      for (int i = start + 1; i < 8; i++) {                                     //for loop runs down left side of board adding one to each pocket, starts on pocket chosen to play
        while (amount_stones > 0){                                                //while loop checks to see if we still have stones left
          Board.at(i).at(0) += 1;
          amount_stones--;
          break;                                                                  //break while loop to move to the next pocket before checking condition again
        }
      }

      for (int i = 6; i > 0; i--) {                                               //for loop runs up right side of the board adding one to each pocket
        while(amount_stones > 0) {                                                //while loop serves same porpuse as previous one
          Board.at(i).at(1) += 1;
          amount_stones--;
          break;
        }
      }
    }
    void Move2 (int start, std::vector<std::vector<int>>& Board) {
      int amount_stones {Board.at(start).at(1)};                                //sets up the limit of stones you can place on the board = #stones in pocket
      Board.at(start).at(1) = 0;                                                //sets pocket played to 0
  
      for (int i = start - 1; i >= 0; i--) {                                     //for loop runs up right side of board adding one to each pocket, starts on pocket chosen to play
        while (amount_stones > 0){                                                //while loop checks to see if we still have stones left
          Board.at(i).at(1) += 1;
          amount_stones--;
          break;                                                                  //break while loop to move to the next pocket before checking condition again
        }
      }

      for (int i = 1; i < 8; i++) {                                               //for loop runs down left side of the board adding one to each pocket
        while(amount_stones > 0) {                                                //while loop serves same porpuse as previous one
          Board.at(i).at(0) += 1;
          amount_stones--;
          break;
        }
      }
    }

    void Print1 (const std::vector<std::vector<int>>& Board) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
          std::cout<<Board.at(i).at(j);
        }
        std::cout << '\n';
      }
       std::cout << "=======\n";
    }

    void Print2 (const std::vector<std::vector<int>>& Board) {
      for (int i = 7; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
         std::cout<<Board.at(i).at(j);
        }
        std::cout << '\n';
      }
      std::cout << "=======\n";
    }
};

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

  while (player1.Turn()) {
    player1.Print1(Board);
    std::cout << "Player 1 turn\n";
    std::cout << "Please enter number of pocket to play: ";
    std::cin >> pocket;
    player1.Move1(pocket, Board);
    player1.Print1(Board);
  }

  while (player2.Turn()) {
    std::cout << "Player 2's turn\n";
    player2.Print2(Board);
    std::cout << "Please enter number of pocket to play: ";
    std::cin >> pocket;
    player2.Move2(pocket, Board);
    player2.Print2(Board);
  }
}