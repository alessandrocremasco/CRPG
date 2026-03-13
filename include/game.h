#include <player.h>
#include <inventory.h>
#include <map.h>

typedef struct {
  Player player;
  Inventory inventory;
  Map map;
} Game;