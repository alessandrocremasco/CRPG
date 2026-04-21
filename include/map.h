#ifndef MAP_H
#define MAP_H

#include "player.h"

#define MAP_ROWS 5
#define MAP_COLUMNS 5

void print_map(Player *player);
int move_player(Player *player, char direction);

#endif