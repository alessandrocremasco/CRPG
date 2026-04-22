#ifndef INVENTORY_H
#define INVENTORY_H
#define INVENTORY_SIZE 10
#include "item.h"

typedef struct {
  Item items[INVENTORY_SIZE];
  int count;
}Inventory;

void add_item(Inventory *inv, Item item);
void use_potion(Inventory *inv, int index, int *player_hp);
void print_inventory(Inventory *inv);
#endif