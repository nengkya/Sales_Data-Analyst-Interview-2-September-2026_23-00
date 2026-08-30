#include <stddef.h>
#include <stdio.h>


int main() {

  size_t my_size_t = 0 - 1;

  if (my_size_t < 0) printf("%ld\n", my_size_t);

  printf("%ld\n", my_size_t);

}
