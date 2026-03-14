#include <stdio.h>
#include "map.h"

void print_map(Player *player){
  for (int i = 0; i < MAP_ROWS; i++){
    for (int j = 0; j < MAP_COLUMNS; j++){
      
      if(j == player->row && i == player->column)
        printf("P ");
      else
        printf(". ");
    }

    printf("\n");
  }
}

void move_player(Player *player, char direction){
  if(direction == 'w' && player->column > 0)
    player->column--;
  if(direction == 's' && player->column < MAP_ROWS-1)
    player->column++;
  if(direction == 'a' && player->row > 0)
    player->row--;
  if(direction == 'd' && player->row < MAP_COLUMNS-1)
    player->row++;
}
