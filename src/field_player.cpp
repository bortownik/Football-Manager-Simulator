#include "field_player.h"

#include "constants.h"

FieldPlayer::FieldPlayer() : Player(), shooting_(50), tackling_(50) {}

FieldPlayer::FieldPlayer(const std::string& name, int age,
                         Position position, int technique,
                         int physicality, int stamina,
                         double market_value, int shooting, int tackling)
    : Player(name, age, position, technique, physicality, stamina,
             market_value),
      shooting_(clamp(shooting, MIN_ATTRIBUTE, MAX_ATTRIBUTE)),
      tackling_(clamp(tackling, MIN_ATTRIBUTE, MAX_ATTRIBUTE)) {}

double FieldPlayer::attackScore() const {
  double base = 0.55 * static_cast<double>(shooting_) +
                0.30 * static_cast<double>(technique()) +
                0.15 * static_cast<double>(physicality());
  if (position() == Position::FWD) {
    return base;
  }
  if (position() == Position::MID) {
    return base * 0.70;
  }
  if (position() == Position::DEF) {
    return base * 0.35;
  }
  return base * 0.10;
}

double FieldPlayer::defenseScore() const {
  double base = 0.55 * static_cast<double>(tackling_) +
                0.25 * static_cast<double>(physicality()) +
                0.20 * static_cast<double>(technique());
  if (position() == Position::DEF) {
    return base;
  }
  if (position() == Position::MID) {
    return base * 0.60;
  }
  if (position() == Position::FWD) {
    return base * 0.25;
  }
  return base * 0.10;
}

double FieldPlayer::positionFit(Position slot) const {
  if (slot == Position::GK) {
    return 0.30;
  }
  if (slot == position()) {
    return 1.00;
  }
  if (slot == Position::MID || position() == Position::MID) {
    return 0.80;
  }
  return 0.50;
}

int FieldPlayer::shooting() const { return shooting_; }
int FieldPlayer::tackling() const { return tackling_; }