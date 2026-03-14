#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "enemy.h"
#include "combat.h"
#include "map.h"

int main(){
  srand(time(NULL));

  Player player;
  init_player(&player);

  printf("Benvenuto in CRPG!\n");

  char direction;

  while(player.hp > 0){
    printf("HP: %d\nAttack: %d\nDefence: %d\n", player.hp, player.attack, player.defence);
    print_map(&player);

    printf("\n");

    printf("Which way? (w/a/s/d)\n");
    scanf(" %c", &direction);
    printf("\n");
    printf("\n");
    printf("\n");
    move_player(&player, direction);

    int event = rand() % 3;

    if(event == 0){
      Enemy enemy;
      create_enemy(&enemy);
      start_combat(&player, &enemy);
    }
    else
      printf("Nothing happen...\n");
  }
  
  printf("\n");

  printf("\nGame Over\n");

  return 0;
}

