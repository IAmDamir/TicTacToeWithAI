//
// Created by Damir on 10/25/2021.
//

#include "Game.h"

Game::Game() {
  isPlaying = true;
  player1 = Player(false);
}

void Game::StartGame() {
  while(isPlaying) {
    cout << "1. Start" << endl;
    cout << "0. Exit" << endl;

    cin >> playerChoice;

    switch (playerChoice) {
      case 1:
        PlayGame();
        break;
      case 0:
        isPlaying = false;
    }
  }
}

void Game::PlayGame() {
  bool gameOver = false;
  pair<int, int> spaceChoice;
  cout << "Please choose who you will be playing against" << endl;
  cout << "1. Player" << endl;
  cout << "2. AI" << endl;
  cout << "0. Back" << endl;

  cin >> playerChoice;

  switch (playerChoice) {
    case 1:
      player2 = Player(false);
      break;
    case 2:
      player2 = Player(true);
      break;
    case 0:
      return;
  }

  while (!gameOver) {
    spaceChoice = player1.ChooseASpace();
    if (!gameBoard.markTheSpace('X', spaceChoice.first, spaceChoice.second)) {
      continue;
    }

    gameOver = gameBoard.isWin(spaceChoice.first, spaceChoice.second) || gameBoard.isTie();
    if(gameOver) {
      continue;
    }
    gameBoard.showTheBoard();

    spaceChoice = player2.ChooseASpace();
    if (!gameBoard.markTheSpace('O', spaceChoice.first, spaceChoice.second)) {
      continue;
    }
    gameBoard.showTheBoard();

    gameOver = gameBoard.isWin(spaceChoice.first, spaceChoice.second) || gameBoard.isTie();
  }

  gameBoard.showTheBoard();
}

Game::~Game() = default;