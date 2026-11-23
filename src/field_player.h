#ifndef FIELD_PLAYER_H
#define FIELD_PLAYER_H

#include "player.h"

class FieldPlayer : public Player {
 public:
  FieldPlayer();
  FieldPlayer(const std::string& name, int age, Position position,
              int technique, int physicality, int stamina,
              double market_value, int shooting, int tackling);

  double attackScore() const override;
  double defenseScore() const override;
  double positionFit(Position slot) const override;

  int shooting() const;
  int tackling() const;

 private:
  int shooting_;
  int tackling_;
};

#endif