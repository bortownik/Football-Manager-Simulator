#ifndef MANAGER_H
#define MANAGER_H

#include <string>

#include "types.h"

class Manager {
 public:
  Manager();
  Manager(const std::string& name, TacticStyle preferred_style);

  const std::string& name() const;
  TacticStyle preferredStyle() const;

  bool matchesStyle(TacticStyle tactic) const;
  double styleBonus(TacticStyle tactic) const;

  static std::string styleLabel(TacticStyle style);
  static std::string styleDescription(TacticStyle style);

 private:
  std::string name_;
  TacticStyle preferred_style_;
};

#endif