#include <stdio.h>
#include "inventory.h"

void add_item(Inventory *inv, Item item){
  if(inv->count < INVENTORY_SIZE){
    inv->items[inv->count] = item;
  }
  inv->count++;
  printf("%s added to the inventory.\n", item.name);
}
void use_potion(Inventory *inv, int index, int *player_hp){
  if(index < 0 || index >= inv->count){
    printf("No item selected.\n");
    return;
  }
  Item item = inv->items[index];
  if (item.heal > 0){
    *player_hp += item.heal;
    printf("You used %s! +%d HP\n", item.name, item.heal);
  }

  for (int i = index; i < inv->count - 1; i++){
    inv->items[i] = inv->items[i+1];
  }

  inv->count--;
}

void print_inventory(Inventory *inv){
  for (int i = 0; i < inv->count; i++){
    printf("%d) %s\n", i, inv->items[i].name);
  }
}