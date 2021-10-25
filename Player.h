//
// Created by Damir on 10/25/2021.
//

#pragma once
#ifndef TICTACTOEWITHAI_PLAYER_H
#define TICTACTOEWITHAI_PLAYER_H

#include <tuple>

#include "Random.h"
#include "Environment.h"

class Player {
public:
  explicit Player(bool isAI = true, Environment* gameBoard = new Environment());
  ~Player();

  pair<int, int> ChooseASpace();

  bool isAI() const;

  static void setAI(bool isPlayingAgainstAi);

private:
  Environment* gameBoard;
  Random random;
  bool AI;
};


#endif //TICTACTOEWITHAI_PLAYER_H
