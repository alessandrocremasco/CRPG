#include "player.h"

void init_player(Player *player){

  player->hp = 50;
  player->attack = 15;
  player->defence = 5;

  player->row = 2;
  player->column = 2;

}