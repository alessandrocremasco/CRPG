#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "enemy.h"
#include "combat.h"
#include "map.h"

void clear_screen();
int main(){
  srand(time(NULL));

  Player player;
  init_player(&player);

  printf("\n");
  printf("WELCOME IN CRPG!\n");
  printf("\n");
  printf("The princess of Gondor was kidnapped.\nWith a sword and a shield you were assigned the mission to bring back to kingdom its beloved princess.\nVenture into the deep, dark dungeon. Move across the caves and slash every creature that comes your way to find the princess and succeding the quest!\n");
  printf("\n");
  printf("Good luck, slayer!\n");
  printf("\n");
  char direction;

  while(player.hp > 0){
    clear_screen();
    printf("-----------------------------------------------\n");
    printf("PLAYER STATS:\n");
    printf("\n");
    printf("HP: %d\nAttack: %d\nDefence: %d\n", player.hp, player.attack, player.defence);
    print_map(&player);

    printf("\n");

    printf("Which way? (w/a/s/d)\n");
    scanf(" %c", &direction);
    printf("\n");
    printf("\n");
    printf("\n");

    int moved = move_player(&player, direction);

    if (moved){
      int event = rand() % 3;
      if(event == 0){
      Enemy enemy;
      create_enemy(&enemy);
      start_combat(&player, &enemy);
      }
      else{
        printf("Nothing happen...\n");
        printf("\n");
      }
    printf("-----------------------------------------------\n");
    }
    else{
      printf("You can't go there...\n");
      printf("\n");
      printf("-----------------------------------------------\n");
    }
  }
  
  printf("\n");

  printf("\nGAME OVER 💀\n");
  printf("The princess never returned to her kingdom 💔\n");

  return 0;
}

void clear_screen(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
