CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/player.c src/enemy.c src/combat.c src/map.c src/inventory.c

OUT = build/rpg

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f build/*