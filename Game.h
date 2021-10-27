//
// Created by Damir on 10/25/2021.
//

#pragma once
#ifndef TICTACTOEWITHAI_GAME_H
#define TICTACTOEWITHAI_GAME_H

#include "Player.h"

class Game {
public:
  Game();
  ~Game();

  void StartGame();
  void PlayGame();

private:
  bool isPlaying;
  int playerChoice;
  Player player1;
  Player player2;
  Environment* gameBoard;
};


#endif //TICTACTOEWITHAI_GAME_H
