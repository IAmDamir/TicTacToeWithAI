//
// Created by Damir on 10/25/2021.
//

#include "Environment.h"

Environment::Environment() {
  vector<char> subVector;
  subVector.reserve(3);
  for (int i = 0; i < 3; ++i) {
    subVector.push_back(' ');
  }
  for (int i = 0; i < 3; ++i) {
    gameBoard.push_back(subVector);
  }
}

void Environment::showTheBoard() {
  for (int i = 0; i < 3; ++i) {
    cout << "-------" << endl;
    cout << ':';
    for (int j = 0; j < 3; ++j) {
      cout << gameBoard[i][j] << ':';
    }
    cout << endl;
  }
  cout << "-------" << endl;
}

bool Environment::markTheSpace(char mark, int row, int column) {
  bool isPossibleToPlace = true;
  if (row > 3 || row < 0) {
    cout << "Row is out of the board, please choose a row within the board" << endl;
    isPossibleToPlace = false;
  }
  if (column > 3 || column < 0) {
    cout << "Column is out of the board, please choose a row within the board" << endl;
    isPossibleToPlace = false;
  }

  if (!isPossibleToPlace) {
    return false;
  }

  if (gameBoard[row][column] == ' ') {
    gameBoard[row][column] = mark;
    return true;
  } else {
    cout << "Impossible to place it here, please place it in the open space" << endl;
  }
  return false;
}

bool Environment::isWin(int row, int column) {
  bool diagonallyEqual = false;
  // Checking horizontal axis
  bool horizontallyEqual = gameBoard[row][0] == gameBoard[row][1] && gameBoard[row][1] == gameBoard[row][2];
  // Checking the vertical axis
  bool verticallyEqual = gameBoard[0][column] == gameBoard[1][column] && gameBoard[1][column] == gameBoard[2][column];
  bool center = row == 1 && column == 1;
  bool diagonalCannotBeChecked = row == 1 || column == 1;

  // Checking if diagonal axis could be checked
  if (center) {
    diagonallyEqual = gameBoard[row][column] == gameBoard[0][0] && gameBoard[row][column] == gameBoard[2][2];
    if (!diagonallyEqual) {
      diagonallyEqual = gameBoard[row][column] == gameBoard[0][2] && gameBoard[row][column] == gameBoard[2][0];
    }
  } else if (!diagonalCannotBeChecked) {
    diagonallyEqual = gameBoard[row][column] == gameBoard[2-row][2-column] && gameBoard[row][column] == gameBoard[1][1];
  }

  return verticallyEqual || horizontallyEqual || diagonallyEqual;
}

bool Environment::isTie() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (gameBoard[i][j] == ' ') {
        return false;
      }
    }
  }

  return true;
}

bool Environment::isSpaceEmpty(int row, int column) {
  if (gameBoard[row][column] == ' ') {
    return true;
  }

  return false;
}

Environment::~Environment() = default;