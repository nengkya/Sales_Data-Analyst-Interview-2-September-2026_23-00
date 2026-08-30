#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "stdio.h"

enum itemAugmentation {healthPoints, mana, attack, defense, accuracy};

struct item {

  char * name;
  int healthPoints, mana, attack, defense, accuracy, damage;

};


struct entity {

  char * name;
  int healthPoints, mana, attack, defense, accuracy, damage;

  struct item * item;

};


struct entity * initEntity(char * name, int healthPoints, int mana, int attack, int defense, int accuracy) {

  struct entity * entity = (struct entity *)malloc(sizeof(struct entity));

  (* entity).item = (struct item *)malloc(sizeof(struct item));

  (* entity).item->name = "Helmet of Iron Will";
  (* entity).item->healthPoints = 0;
  (* entity).item->mana=0;
  (*entity).item->attack=0;
  (*entity).item->defense=0;
  (* entity).item->accuracy=0;

  (* entity).name = name;
  (* entity).healthPoints = healthPoints + (* entity).item->healthPoints;
  (* entity).mana = mana + (*entity).item->mana;
  (* entity).attack = attack + (*entity).item->attack;
  (* entity).defense = defense + (*entity).item->attack;
  (* entity).accuracy = accuracy + (*entity).item->accuracy;

  return entity;

}


void printfStatus(struct entity * entity) {

  printf("\nentity\thealth points\tmana\tattack\tdefense\tdamage");
  printf("\n%s\t%d\t\t%d\t%d\t%d\n", (* entity).name, (* entity).healthPoints, (* entity).mana, (* entity).attack, (* entity).defense);

}


void attackTurn(struct entity * entity1, struct entity * entity2) {

  int dice = rand() % 100;

  if (dice > (99 - (* entity1).accuracy)) (* entity1).damage = (* entity1).attack - (* entity2).defense;
  else (* entity1).damage = rand() % ((* entity1).attack - 1);

  (* entity2).healthPoints = (* entity2).healthPoints - (* entity1).damage;

  printf("\n%s attack %s with %d damage\n", (* entity1).name, (* entity2).name, (* entity1).damage);

}


void lootItem(struct entity * entity) {

  printf("%s got %s\n", (* entity).name, (* entity).item->name);

}


void calculateDrop(struct entity * entity1, struct entity * entity2) {

  int dice = rand() % 5;

  switch (dice) {

    healthPoints: (* entity1).item->healthPoints = rand() * 25;

  }

  lootItem(entity2);

}


void dropItem(struct entity * entity1, struct entity * entity2) {

  calculateDrop(entity1, entity2);
  printf("struct helm drop %ld\n\n", sizeof(struct item));

}


void goBattle(struct entity * hero) {

  struct entity * enemy = initEntity("Enemy", 200, 150, 50, 20, 90);

  printfStatus(hero);
  printfStatus(enemy);

  attackTurn(hero, enemy);
  attackTurn(enemy, hero);

  if ((* hero).healthPoints <= 0) {
    printf("\n%s win. %s died with %d health points\n\n", (* enemy).name, (* hero).name, (* hero).healthPoints);
    dropItem(hero, enemy);
  }

  if ((* enemy).healthPoints <= 0) {
    printf("\n%s win. %s died with %d health points\n\n", (* hero).name, (* enemy).name, (* enemy).healthPoints);
    dropItem(enemy, hero);
  }

  free((* enemy).item); (* enemy).item = (void *) 0;
  free(enemy); enemy = (void *) 0;

}


int main() {

  int battle;

  struct entity * hero = initEntity("Hero", 200, 150, 100, 5, 70);

  //srand(time((void *) 0));

  while (1) {

    goBattle(hero);

    scanf(&battle);

    if (battle=1) continue;
    else break;

  }

  free((* hero).item); (* hero).item = nullptr;
  free(hero); hero = nullptr;

}
