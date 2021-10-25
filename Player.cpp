//
// Created by Damir on 10/25/2021.
//

#include "Player.h"

Player::Player(bool AI, Environment* gameBoard) {
  this->AI = AI;
  this->gameBoard = gameBoard;
}

pair<int, int> Player::ChooseASpace() {
  pair<int, int> answer;

  if (AI) {
    answer.first = random.getRandomNumber()%3;
    answer.second = random.getRandomNumber()%3;
    while(!gameBoard->isSpaceEmpty(answer.first, answer.second)) {
      answer.first = random.getRandomNumber()%3;
      answer.second = random.getRandomNumber()%3;
    }
  } else {
    cout << "Please choose a space where you want to place your sign";
    cin >> answer.first >> answer.second;
  }

  return answer;
}

bool Player::isAI() const {
  return AI;
}

void Player::setAI(bool AI) {
  AI = AI;
}

Player::~Player() {
  delete gameBoard;
}
