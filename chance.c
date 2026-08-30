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
 
  srand(time((void *) 0));

  /*random 0-9*/
  dice = rand() % 10;

  printf("dice %d\n", dice);

  if (dice > 2) printf("attack 100 !\n");
  else printf("attack %d !\n", rand() % 100);

}
