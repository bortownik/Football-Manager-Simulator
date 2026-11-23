#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "types.h"

class Player {
 public:
  Player();
  Player(const std::string& name, int age, Position position,
         int technique, int physicality, int stamina,
         double market_value);
  virtual ~Player();

  virtual double attackScore() const = 0;
  virtual double defenseScore() const = 0;
  virtual double positionFit(Position slot) const = 0;

  double overall() const;
  double conditionFactor() const;
  double moraleFactor() const;
  double skillFactor(double technique_weight,
                     double physicality_weight) const;

  const std::string& name() const;
  int age() const;
  Position position() const;
  int technique() const;
  int physicality() const;
  int stamina() const;
  int morale() const;
  int fitness() const;
  double marketValue() const;
  int goalsScored() const;

  void setMorale(int morale);
  void setFitness(int fitness);
  void setMarketValue(double market_value);
  void adjustFitness(int delta);
  void adjustMorale(int delta);
  void addGoal();

  bool operator==(const Player& other) const;

  static std::string positionLabel(Position position);

 protected:
  static int clamp(int value, int min_value, int max_value);

 private:
  std::string name_;
  int age_;
  Position position_;
  int technique_;
  int physicality_;
  int stamina_;
  int morale_;
  int fitness_;
  double market_value_;
  int goals_scored_;
};

std::ostream& operator<<(std::ostream& out, const Player& player);

#endif