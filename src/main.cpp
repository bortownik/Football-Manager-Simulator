#include <iostream>
#include <iomanip>

#include "field_player.h"
#include "player.h"
#include "goalkeeper.h"
#include "manager.h"

void showPlayer(const Player& player) {
  std::cout << player << "\n";
  std::cout << "  atak " << player.attackScore() << ", obrona "
            << player.defenseScore() << "\n";
}

int main() {
  FieldPlayer del_piero("Del Piero", 25, Position::FWD, 88, 70, 78,
                        24.0, 90, 35);
  FieldPlayer nesta("Nesta", 23, Position::DEF, 68, 82, 80, 22.0,
                    30, 90);

  Goalkeeper buffon("Buffon", 26, 75, 80, 85, 30.0, 90, 88);

  showPlayer(del_piero);
  showPlayer(nesta);
  showPlayer(buffon);
  std::cout << "  fit GK " << buffon.positionFit(Position::GK) << ", fit DEF " << buffon.positionFit(Position::DEF) << "\n";

    Manager mourinho("Jose Mourinho", TacticStyle::COUNTER);
  Manager guardiola("Pep Guardiola", TacticStyle::POSSESSION);

  std::cout << mourinho.name() << " - "
            << Manager::styleLabel(mourinho.preferredStyle()) << "\n";
  std::cout << "  "
            << Manager::styleDescription(mourinho.preferredStyle())
            << "\n";

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "  bonus kontra "
            << mourinho.styleBonus(TacticStyle::COUNTER)
            << ", bonus ofensywna "
            << mourinho.styleBonus(TacticStyle::ATTACKING) << "\n";
  std::cout << "  zgodny z kontra: "
            << mourinho.matchesStyle(TacticStyle::COUNTER)
            << ", z posiadaniem: "
            << mourinho.matchesStyle(TacticStyle::POSSESSION) << "\n";

  std::cout << guardiola.name() << " - "
            << Manager::styleLabel(guardiola.preferredStyle()) << "\n";
  return 0;
}