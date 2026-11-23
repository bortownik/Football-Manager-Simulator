#include <iostream>

#include "field_player.h"
#include "player.h"

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

  showPlayer(del_piero);
  showPlayer(nesta);
  return 0;
}