#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
typedef struct {
  int hp;
  int attack;
  int defense;
  Inventory inventory;

  int row;
  int column;

} Player;

void init_player(Player *player);

#endif