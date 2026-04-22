#include <stdio.h>
#include "combat.h"
#include "player.h"
#include "enemy.h"
#include "inventory.h"

void start_combat(Player *player, Enemy *enemy){
  printf("%s appears!\n", enemy->name);
  printf("\n");
  printf("\n");

  while(player->hp > 0 && enemy->hp > 0){
    printf("\n");
    printf("YOUR TURN:\n");

    printf("What do you do?\n");
    printf("\n");
    printf("1. Attack enemy\n");
    printf("2. Use potion\n");

    int choice1;
    scanf("%d", &choice1);

    if(choice1 == 1){
      enemy->hp -= player->attack;
      printf("You slash the %s! %s gets %d damages.\n",enemy->name, enemy->name, player->attack);
      printf("%s HP: %d\n", enemy->name, enemy->hp);
    
      printf("\n");
      printf("\n");
    }
    else if(choice1 == 2){
      printf("Quale oggetto vuoi scegliere?\n");
      int choice2;
      print_inventory(&player->inventory);
      scanf("%d", &choice2);
      use_potion(&player->inventory, choice2, &player->hp);
      printf("\n");
    }
    else{
      printf("No potions available...\n");
      continue;
    }

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