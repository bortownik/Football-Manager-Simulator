#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include "player.h"

class Goalkeeper : public Player {
 public:
  Goalkeeper();
  Goalkeeper(const std::string& name, int age, int technique,
             int physicality, int stamina, double market_value,
             int reflexes, int positioning);

  double attackScore() const override;
  double defenseScore() const override;
  double positionFit(Position slot) const override;

  int reflexes() const;
  int positioning() const;

 private:
  int reflexes_;
  int positioning_;
};

#endif