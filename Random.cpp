//
// Created by Damir on 10/13/2021.
//

#include "Random.h"

Random::Random() {
  // sets a seed for a random number generator
  // seed is equal to current time
  srand(time(nullptr));
}

Random::~Random() = default;
// Returns random a pseudo number
int Random::getRandomNumber() {
  return rand();
}