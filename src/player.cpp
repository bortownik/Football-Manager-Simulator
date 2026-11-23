#include "player.h"

#include <iomanip>

#include "constants.h"

Player::Player()
    : name_("Nieznany"),
      age_(18),
      position_(Position::MID),
      technique_(50),
      physicality_(50),
      stamina_(50),
      morale_(DEFAULT_MORALE),
      fitness_(DEFAULT_FITNESS),
      market_value_(1.0),
      goals_scored_(0) {}

Player::Player(const std::string& name, int age, Position position,
               int technique, int physicality, int stamina,
               double market_value)
    : name_(name),
      age_(age),
      position_(position),
      technique_(clamp(technique, MIN_ATTRIBUTE, MAX_ATTRIBUTE)),
      physicality_(clamp(physicality, MIN_ATTRIBUTE, MAX_ATTRIBUTE)),
      stamina_(clamp(stamina, MIN_ATTRIBUTE, MAX_ATTRIBUTE)),
      morale_(DEFAULT_MORALE),
      fitness_(DEFAULT_FITNESS),
      market_value_(market_value),
      goals_scored_(0) {}

Player::~Player() {}

double Player::overall() const {
  if (position_ == Position::FWD) {
    return 0.75 * attackScore() + 0.25 * defenseScore();
  }
  if (position_ == Position::MID) {
    return 0.50 * attackScore() + 0.50 * defenseScore();
  }
  if (position_ == Position::DEF) {
    return 0.25 * attackScore() + 0.75 * defenseScore();
  }
  return 0.05 * attackScore() + 0.95 * defenseScore();
}

double Player::conditionFactor() const {
  return 0.55 + 0.45 * static_cast<double>(fitness_) / MAX_CONDITION;
}

double Player::moraleFactor() const {
  return 0.90 + 0.20 * static_cast<double>(morale_) / MAX_ATTRIBUTE;
}

double Player::skillFactor(double technique_weight,
                           double physicality_weight) const {
  double technique_part =
      technique_weight * (static_cast<double>(technique_) - 50.0) / 200.0;
  double physicality_part =
      physicality_weight * (static_cast<double>(physicality_) - 50.0) / 200.0;
  return 1.0 + technique_part + physicality_part;
}

const std::string& Player::name() const { return name_; }
int Player::age() const { return age_; }
Position Player::position() const { return position_; }
int Player::technique() const { return technique_; }
int Player::physicality() const { return physicality_; }
int Player::stamina() const { return stamina_; }
int Player::morale() const { return morale_; }
int Player::fitness() const { return fitness_; }
double Player::marketValue() const { return market_value_; }
int Player::goalsScored() const { return goals_scored_; }

void Player::setMorale(int morale) {
  morale_ = clamp(morale, MIN_CONDITION, MAX_ATTRIBUTE);
}

void Player::setFitness(int fitness) {
  fitness_ = clamp(fitness, MIN_CONDITION, MAX_CONDITION);
}

void Player::setMarketValue(double market_value) {
  market_value_ = market_value < 0.0 ? 0.0 : market_value;
}

void Player::adjustFitness(int delta) { setFitness(fitness_ + delta); }

void Player::adjustMorale(int delta) { setMorale(morale_ + delta); }

void Player::addGoal() { ++goals_scored_; }

bool Player::operator==(const Player& other) const {
  return name_ == other.name_ && position_ == other.position_;
}

std::string Player::positionLabel(Position position) {
  if (position == Position::GK) {
    return "GK";
  }
  if (position == Position::DEF) {
    return "DEF";
  }
  if (position == Position::MID) {
    return "MID";
  }
  return "FWD";
}

int Player::clamp(int value, int min_value, int max_value) {
  if (value < min_value) {
    return min_value;
  }
  if (value > max_value) {
    return max_value;
  }
  return value;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
  out << std::fixed << std::setprecision(1);
  out << player.name() << " ("
      << Player::positionLabel(player.position()) << "), wiek "
      << player.age() << ", ocena " << player.overall()
      << ", kondycja " << player.fitness() << "%, morale "
      << player.morale() << "%, wartosc " << player.marketValue()
      << " mln";
  return out;
}