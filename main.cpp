#include "./backend/game.h"
#include "./backend/player.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
  sf::RenderWindow main_window(sf::VideoMode(1024, 1024), "Mancala");
  main_window.setFramerateLimit(60);
  sf::Font font;
  sf::Texture t;
  t.loadFromFile("main_menu.png");
  sf::Sprite background(t);
  if (!font.loadFromFile("Stylish-Regular.ttf"))
  {
      std::cerr << "opps! we could not find your text file ;-;";
  }
  sf::Text title;
  sf::Text instruction1;
  sf::Text instruction2;
  title.setFont(font);
  title.setCharacterSize(90);
  title.setFillColor(sf::Color(50, 74, 14));
  title.setOrigin(-512 + 204, -125); // to make title centered too half of the window res and subtracted half of the length of the string
  title.setString("MANCALA");

  instruction1.setFont(font);
  instruction1.setCharacterSize(40);
  instruction1.setFillColor(sf::Color(50, 74, 14));

  instruction2.setFont(font);
  instruction2.setCharacterSize(40);
  instruction2.setFillColor(sf::Color(50, 74, 14));

  sf::RectangleShape canvas;
  canvas.setFillColor(sf::Color(255, 255, 255, 128));

  sf::CircleShape select_icon(20, 3);
  select_icon.setFillColor(sf::Color(55, 80, 55));
  select_icon.rotate(90);
  select_icon.setPosition(460, 267.5);
  
  while (main_window.isOpen()) {
    Game main_menu(true);
    while (main_menu.Status()) {
      sf::Event selection;
      while (main_window.pollEvent(selection))
      {
        if (selection.key.code == sf::Keyboard::Down) {
          select_icon.setPosition(370, 357.5);
        }
        if (selection.key.code == sf::Keyboard::Up) {
          select_icon.setPosition(460, 267.5);
        }
        if (selection.key.code == sf::Keyboard::Enter) {
          if (select_icon.getPosition().x > 400 )
            main_menu.switchStatus();
          else {
            main_window.close();
            return 0;
          } 
          continue;
        }
      }

      instruction1.setOrigin(-512 + 50, -260);
      instruction1.setString("PLAY");

      instruction2.setOrigin(-512 + 140, -350);
      instruction2.setString("EXIT THE GAME ;-;");

      canvas.setSize(sf::Vector2f(400, 295));
      canvas.setOrigin(-295,-125);


      main_window.draw(background);
      main_window.draw(canvas);
      main_window.draw(title);
      main_window.draw(instruction1);
      main_window.draw(instruction2);
      main_window.draw(select_icon);
      main_window.display();
    }

    Game mancala(true);
    while (mancala.Status()) {
      sf::Event event;
      while (main_window.pollEvent(event))
      {
        if(event.key.code == sf::Keyboard::X) {
          mancala.switchStatus();
          main_menu.switchStatus();
          break;
        }
      }

      std::string player{"1"};

      sf::RectangleShape board(sf::Vector2f(275, 512));
      board.setOrigin(-365,-250);
      board.setFillColor(sf::Color::Cyan);

      instruction1.setOrigin(-750, -50);
      instruction1.setString("PLAYER " + player + " TURN");

      instruction2.setOrigin(-667, -950);
      instruction2.setString("EXIT TO MAIN MENU");

      canvas.setSize(sf::Vector2f(275, 50));
      canvas.setOrigin(-740, -50);

      sf::RectangleShape bottom_canvas(sf::Vector2f(360, 50));
      bottom_canvas.setPosition(657, 955);

      main_window.clear();
      main_window.draw(background);
      main_window.draw(canvas);
      main_window.draw(bottom_canvas);
      main_window.draw(instruction1);
      main_window.draw(instruction2);
      main_window.draw(title);
      main_window.draw(board);
      main_window.display();
    }
  }

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
      player1.SwitchTurn();
    }

    player2.SwitchTurn();
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
      player2.SwitchTurn();
    }

    player1.SwitchTurn();
  }
}
