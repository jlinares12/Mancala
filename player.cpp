#include "player.h"

#include <iostream>
#include <vector>

Player1::Player1 () : m_turn(false), m_points(0) {}
Player1::Player1 (bool turn, int points) :  m_turn (turn), m_points (points) {}

void Player1::Move (int start, std::vector<std::vector<int>>& Board) {        //takes in which pocket the player chooses to play & current state of board
      int amount_stones {Board.at(start).at(0)};                              //sets up the limit of stones you can place on the board = #stones in pocket
      int stone = amount_stones;
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

    int checker = stone + start;
    if (checker == 7) {
        m_turn = false;
    }

    if (checker > 7) {
        if (((checker + 6) % 13) == 0) {
            m_turn = false;
        }
    }
}

void Player1::Print (const std::vector<std::vector<int>>& Board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout<<Board.at(i).at(j);
        }
        std::cout << '\n';
    }
    std::cout << "=======\n";
}

bool Player1::Turn (){
      return m_turn;
    }

bool Player1::SwitchTurn () {
    m_turn = !m_turn;
    return m_turn;
}

//////////////////////////    start of   /////////////////////////////////////////
//////////////////////////    Player 2   /////////////////////////////////////////

Player2::Player2 () : m_turn(false), m_points(0) {}
Player2::Player2 (bool turn, int points) :  m_turn (turn), m_points (points) {}

void Player2::Move (int start, std::vector<std::vector<int>>& Board) {
    int amount_stones {Board.at(start).at(1)};
    int stone = amount_stones;                                                  //sets up the limit of stones you can place on the board = #stones in pocket
    Board.at(start).at(1) = 0;                                                  //sets pocket played to 0
  
    for (int i = start - 1; i >= 0; i--) {                                      //for loop runs up right side of board adding one to each pocket, starts on pocket chosen to play
        while (amount_stones > 0){                                              //while loop checks to see if we still have stones left
          Board.at(i).at(1) += 1;
          amount_stones--;
          break;                                                                //break while loop to move to the next pocket before checking condition again
        }
    }

    for (int i = 1; i < 8; i++) {                                               //for loop runs down left side of the board adding one to each pocket
        while(amount_stones > 0) {                                                //while loop serves same porpuse as previous one
          Board.at(i).at(0) += 1;
          amount_stones--;
          break;
        }
    }

    int checker = stone + start;
    if (stone == start) {
        m_turn = false;
    }

    if (stone > start) {
        if (((stone - start) % 13) == 0){
            m_turn = false;
        }
    }
}

void Player2::Print (const std::vector<std::vector<int>>& Board) {
    for (int i = 7; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
            std::cout<<Board.at(i).at(j);
        }
        std::cout << '\n';
    }
    std::cout << "=======\n";
}

bool Player2::Turn (){
      return m_turn;
    }

bool Player2::SwitchTurn () {
    m_turn = !m_turn;
    return m_turn;
}