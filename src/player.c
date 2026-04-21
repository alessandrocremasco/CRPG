#include "player.h"

void init_player(Player *player){

  player->hp = 50;
  player->attack = 15;
  player->defense = 5;
  player->inventory.count = 0;

  player->row = 2;
  player->column = 2;

}