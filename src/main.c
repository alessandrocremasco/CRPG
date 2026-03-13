#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "enemy.h"
#include "combat.h"

int main(){
  srand(time(NULL));

  Player player;
  init_player(&player);

  printf("Benvenuto in CRPG!\n");

  while(player.hp > 0){
    printf("\nPremi invio per esplorare...");
    getchar();

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

