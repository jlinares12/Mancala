#include "./backend/game.h"
#include "./backend/player.h"
#include "./backend/pocket.h"


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {

  // Sets up the main window with it's texture and the font
  sf::RenderWindow main_window(sf::VideoMode(1024, 1024), "Mancala");
  main_window.setFramerateLimit(60);
  sf::Font font;
  sf::Texture background_texture;
  background_texture.loadFromFile("main_menu.png");
  sf::Sprite background(background_texture);
  if (!font.loadFromFile("Stylish-Regular.ttf"))
  {
      std::cerr << "opps! we could not find your text file ;-;";
  }

  // Sets up the layout of the main menu
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
  
  // Opens up the main_window and starts rendering
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
        }
      }

      // it rearranges the instructions and the canvas back to original position
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

    sf::RectangleShape board(sf::Vector2f(275, 720));
    board.setOrigin(-365,-250);
    sf::Texture board_texture;
    board_texture.loadFromFile("board_texture.jpg");
    board.setTexture(&board_texture);

    std::vector<Pocket> player1_pockets(6);
    std::vector<Pocket> player2_pockets(6);

    Player1 player1(player1_pockets);
    Player2 player2(player2_pockets);

    while (mancala.Status()) {
      sf::Event event;
      // Define debounce threshold in milliseconds
      const sf::Time debounceTime = sf::milliseconds(200);
      // Variable to track debounce state
      bool isDebouncing = false;

      // Variables to track debounce time
      sf::Clock debounceClock;
      sf::Time debounceStartTime;

      int start{360};
      for (std::vector<Pocket>::iterator pocket = player1_pockets.begin();
           pocket != player1_pockets.end(); pocket++) {
        pocket->body->setTexture(&board_texture);
        pocket->body->setFillColor(sf::Color(139, 105, 20));
        pocket->body->setPosition(402, start);
        start += 85;
      }

      start = 360;
      for (std::vector<Pocket>::iterator pocket = player2_pockets.begin();
           pocket != player2_pockets.end(); pocket++) {
        pocket->body->setTexture(&board_texture);
        pocket->body->setFillColor(sf::Color(139, 105, 20));
        pocket->body->setPosition(527, start);
        start += 85;
      }

      // sets player's turn to 1 or 2
      std::string player_turn{""};
      if (player1.getTurn())
      {
        player_turn = "1";
      }
      else {
        player_turn = "2";
      }

      //prints out all the instructions
      instruction1.setOrigin(-750, -50);
      instruction1.setString("PLAYER " + player_turn + " TURN");

      instruction2.setOrigin(-667, -950);
      instruction2.setString("EXIT TO MAIN MENU");

      canvas.setSize(sf::Vector2f(275, 50));
      canvas.setOrigin(-740, -50);

      sf::RectangleShape bottom_canvas(sf::Vector2f(360, 50));
      bottom_canvas.setPosition(657, 955);

      select_icon.setPosition(375, 375);
      select_icon.setFillColor(sf::Color::White);

      main_window.clear();
      main_window.draw(background);
      main_window.draw(canvas);
      main_window.draw(bottom_canvas);
      main_window.draw(instruction1);
      main_window.draw(instruction2);
      main_window.draw(title);
      main_window.draw(board);
      for (const auto& pocket : player1_pockets) {
        main_window.draw(*pocket.body);
      }
      for (const auto& pocket : player2_pockets) {
        main_window.draw(*pocket.body);
        for (auto& stone : pocket.getStones()){
          main_window.draw(*stone.body);
        }
      }
      main_window.draw(select_icon);
      main_window.display();
      
      while (main_window.pollEvent(event))
      {
        if (event.type == sf::Event::KeyPressed)
        {
          // Check if not currently debouncing
          if (!isDebouncing)
          {
            // Process the key press event
            if(event.key.code == sf::Keyboard::X) {
              mancala.switchStatus();
              main_menu.switchStatus();
              select_icon.setFillColor(sf::Color(55, 80, 55));
              select_icon.setPosition(460, 267.5);
            }
            if (event.key.code == sf::Keyboard::Y){
              player1.switchTurn();
              player2.switchTurn();
            }
            // Start debouncing
            isDebouncing = true;
            debounceStartTime = debounceClock.getElapsedTime();
          }
        }

        // Check if debouncing and debounce time has elapsed
        if (isDebouncing && debounceClock.getElapsedTime() - debounceStartTime >= debounceTime)
        {
          // End debouncing
          isDebouncing = false;
        }
      }
    }
  }
}
