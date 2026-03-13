#include "enemy.h"
#include <stdlib.h>
#include <string.h>

void create_enemy(Enemy *enemy){
  int r = rand() % 2;

  if(r == 0){
    strcpy(enemy->name, "Goblin");
    enemy->hp = 30;
    enemy->attack = 5;
  }
  else{
    strcpy(enemy->name, "Skeleton");
    enemy->hp = 25;
    enemy->attack = 8;
  }
}