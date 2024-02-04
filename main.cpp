#include <iostream>
#include <vector>

class Player {
  public:
    
  private:
      
};

void PrintPlayer1 (const std::vector<std::vector<int>>& Board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout<<Board.at(i).at(j);
    }
    std::cout << '\n';
  }
   std::cout << "=======\n";
}

void PrintPlayer2 (const std::vector<std::vector<int>>& Board) {
  for (int i = 7; i >= 0; i--) {
    for (int j = 1; j >= 0; j--) {
      std::cout<<Board.at(i).at(j);
    }
    std::cout << '\n';
  }
   std::cout << "=======\n";
}

void MovePlayer1 (int i_start, std::vector<std::vector<int>>& Board) {        //takes in which pocket the player chooses to play & current state of board
  int amount_stones {Board.at(i_start).at(0)};                                //sets up the limit of stones you can place on the board = #stones in pocket
  Board.at(i_start).at(0) = 0;                                                //sets pocket played to 0
  
  for (int i = i_start + 1; i < 8; i++) {                                     //for loop runs down left side of board adding one to each pocket, starts on pocket chosen to play
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

void MovePlayer2 (int i_start, std::vector<std::vector<int>>& Board) {
  int amount_stones {Board.at(i_start).at(1)};                                //sets up the limit of stones you can place on the board = #stones in pocket
  Board.at(i_start).at(1) = 0;                                                //sets pocket played to 0
  
  for (int i = i_start - 1; i >= 0; i--) {                                     //for loop runs up right side of board adding one to each pocket, starts on pocket chosen to play
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
  
  PrintPlayer1(Board);

  int hole{0};
  std::cout << "Please enter number of pocket to play: ";
  std::cin >> hole;
  MovePlayer1(hole, Board);

  PrintPlayer1(Board);
  std::cout << "Player 2's turn\n";
  PrintPlayer2(Board);
  std::cout << "Please enter number of pocket to play: ";
  std::cin >> hole;
  MovePlayer2 (hole, Board);
  PrintPlayer2(Board);
}