//
// Created by Damir on 10/25/2021.
//

#pragma once
#ifndef TICTACTOEWITHAI_ENVIRONMENT_H
#define TICTACTOEWITHAI_ENVIRONMENT_H

#include <vector>
#include <iostream>

using namespace std;

class Environment {
public:
  Environment();
  ~Environment();

  void showTheBoard();
  bool markTheSpace(char mark, int row, int column);
  bool isWin(int row, int column);
  bool isTie();
  bool isSpaceEmpty(int row, int column);

private:
  vector<vector<char>> gameBoard;
};


#endif //TICTACTOEWITHAI_ENVIRONMENT_H
