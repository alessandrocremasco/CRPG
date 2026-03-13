#ifndef ENEMY_H
#define ENEMY_H
typedef struct {
  char name[50];
  int hp;
  int attack;
} Enemy;

void create_enemy(Enemy *enemy);

#endif

