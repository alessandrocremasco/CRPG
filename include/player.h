#ifndef PLAYER_H
#define PLAYER_H
typedef struct {
  int hp;
  int attack;
  int defence;
} Player;

void init_player(Player *player);

#endif