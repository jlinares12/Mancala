#include <iostream>
#include <vector>

class Player {
  public:

  private:
     
};

int main () {
  std::vector<std::vector<int>> Board (8, std::vector<int>(2));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 2; j++) {
      if (i == 0 || i == 7) {
        continue;
      }
      Board.at(i).at(j) = 4;
    }
  }
  
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout<<Board.at(i).at(j);
    }
    std::cout << '\n';
  }
}
