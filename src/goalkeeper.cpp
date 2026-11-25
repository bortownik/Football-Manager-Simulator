#include "goalkeeper.h"

#include "constants.h"

Goalkeeper::Goalkeeper()
    : Player("Nieznany", 18, Position::GK, 50, 50, 50, 1.0),
      reflexes_(50),
      positioning_(50) {}

Goalkeeper::Goalkeeper(const std::string& name, int age, int technique,
                       int physicality, int stamina, double market_value,
                       int reflexes, int positioning)
    : Player(name, age, Position::GK, technique, physicality, stamina,
             market_value),
      reflexes_(clamp(reflexes, MIN_ATTRIBUTE, MAX_ATTRIBUTE)),
      positioning_(clamp(positioning, MIN_ATTRIBUTE, MAX_ATTRIBUTE)) {}

double Goalkeeper::attackScore() const {
  return 0.10 * technique() + 0.05 * positioning_;
}

double Goalkeeper::defenseScore() const {
  return 0.50 * reflexes_ + 0.35 * positioning_ + 0.15 * physicality();
}

double Goalkeeper::positionFit(Position slot) const {
  if (slot == Position::GK) {
    return 1.00;
  }
  return 0.30;
}

int Goalkeeper::reflexes() const { return reflexes_; }
int Goalkeeper::positioning() const { return positioning_; }