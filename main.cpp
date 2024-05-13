#include "./backend/game.h"
#include "./backend/player.h"
#include "./backend/pocket.cpp"

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

      sf::RectangleShape board(sf::Vector2f(275, 720));
      board.setOrigin(-365,-250);
      sf::Texture board_texture;
      board_texture.loadFromFile("board_texture.jpg");
      board.setTexture(&board_texture);

      std::vector<Pocket> player1_pockets(6);

      int start{360};
      for (auto& pocket : player1_pockets) {
        pocket.getBody().setTexture(&board_texture);
        pocket.getBody().setFillColor(sf::Color(139, 105, 20));
        pocket.getBody().setPosition(402, start);
        start += 85;
      }

      std::vector<sf::CircleShape> player2_pockets {
        sf::CircleShape (40, 30),
        sf::CircleShape (40, 30),
        sf::CircleShape (40, 30),
        sf::CircleShape (40, 30),
        sf::CircleShape (40, 30),
        sf::CircleShape (40, 30),
      };

      start = 360;
      for (auto& pocket : player2_pockets) {
        pocket.setTexture(&board_texture);
        pocket.setFillColor(sf::Color(139, 105, 20));
        pocket.setPosition(527, start);
        start += 85;
      }
      

      std::string player_turn{""};
      Player1 player1(true, player1_pockets);
      player1.switchTurn();
      if (player1.getTurn())
      {
        player_turn = "1";
      }
      else {
        player_turn = "2";
      }

      instruction1.setOrigin(-750, -50);
      instruction1.setString("PLAYER " + player_turn + " TURN");

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
      player1.print(&main_window);
      for (const auto& pocket : player2_pockets) {
        main_window.draw(pocket);
      }
      main_window.draw(select_icon);
      main_window.display();
    }
  }
}
