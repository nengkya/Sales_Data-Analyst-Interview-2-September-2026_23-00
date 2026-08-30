#include "stdlib.h"
#include <time.h>
#include "stdio.h"

int main() {

  /*
  ada attack 100
  accuracy 70
  artinya attack punya peluang 70% untuk 100
  sisanya, attack punya peluang 30% untuk 0-99
  */

  int dice;

  //int * attack = {0, 1, 2, 100, 100, 100, 100, 100, 100, 100};
  int * attack = (int *)malloc(sizeof(int[10]));

  * attack = 0;
  attack++;
  * attack = 1;
  attack++;
  * attack = 2;

  printf("attack %d\n", * attack);
 
  srand(time((void *) 0));

  /*random 0-9*/
  dice = rand() % 10;

  printf("dice %d\n", dice);

  attack--;
  attack--;
  free(attack); attack = nullptr;

}
