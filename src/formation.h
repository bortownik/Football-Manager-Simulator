#ifndef FORMATION_H
#define FORMATION_H

#include <string>
#include <vector>

#include "types.h"

class Formation {
 public:
  Formation();
  Formation(FormationType type, const std::string& name, int defenders,
            int midfielders, int forwards, double attack_weight,
            double defense_weight);

  FormationType type() const;
  const std::string& name() const;
  int defenders() const;
  int midfielders() const;
  int forwards() const;
  double attackWeight() const;
  double defenseWeight() const;
  const std::vector<Position>& slots() const;
  int slotCount() const;

  double synergyWith(TacticStyle style) const;

  static Formation create(FormationType type);

 private:
  FormationType type_;
  std::string name_;
  int defenders_;
  int midfielders_;
  int forwards_;
  double attack_weight_;
  double defense_weight_;
  std::vector<Position> slots_;
};

#endif