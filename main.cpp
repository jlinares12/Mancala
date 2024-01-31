#include <iostream>
#include <vector>

int main () {
  std::vector<std::vector<int>> Board {std::vector<int>(8), std::vector<int>(8)};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 8; j++) {
        std::cout << Board.at(i).at(j);
    }
    std::cout << '\n';
  }
}
