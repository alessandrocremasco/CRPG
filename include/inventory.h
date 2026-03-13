#include <item.h>
#define INVENTORY_SIZE 15

typedef struct {
  Item items[INVENTORY_SIZE];
  int count;
} Inventory;