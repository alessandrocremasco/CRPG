#include <stdio.h>
#include "combat.h"

void start_combat(Player *player, Enemy *enemy){
  printf("%s appears!\n", enemy->name);
  printf("\n");
  printf("\n");

  while(player->hp > 0 && enemy->hp > 0){
    printf("YOUR TURN:\n");
    enemy->hp -= player->attack;
    
    printf("You slash the %s! %s gets %d damages.\n",enemy->name, enemy->name, player->attack);
    printf("%s HP: %d\n", enemy->name, enemy->hp);
    
    printf("\n");
    printf("\n");

    if(enemy->hp <= 0)
      break;

    printf("ENEMY TURN:\n");
    player->hp -= enemy->attack;
    printf("The %s hits you!\nHP player: %d\n", enemy->name, player->hp);
  }

  printf("\n");

  if(player->hp > 0){
    printf("You win!\n");
    printf("\n");
  }
  else
    printf("You are dead...\n");
}