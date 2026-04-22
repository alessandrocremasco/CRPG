#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "player.h"
#include "enemy.h"
#include "combat.h"
#include "map.h"
#include "inventory.h"

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
    printf("HP: %d\nAttack: %d\
      Defense: %d\n", player.hp, player.attack, player.defense);
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
      else if (event == 1){
        printf("Nothing happen...\n");
        printf("Do you want to use any potion?\n");
        printf("1. Yes\n");
        printf("2. No\n");

        int choice2;
        scanf("%d", &choice2);
  
        if(choice2 == 1){
          print_inventory(&player.inventory);
          int choice3;
          scanf("%d", &choice3);
          use_potion(&player.inventory, choice3, &player.hp);
          printf("\n");
        }
        else
          printf("No potion used.\n");

        printf("\n");
      }

      else if (event == 2){
        Item potion;
        strcpy(potion.name, "Water of Life");
        potion.heal = 25;
        printf("You found a potion!\n");
        add_item(&player.inventory, potion);
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
