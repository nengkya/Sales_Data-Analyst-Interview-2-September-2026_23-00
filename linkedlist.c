#include "stdio.h"


struct node {
  int data;
  struct node * next;
};


int main() {

  struct node * node1, * node2 = nullptr;

  (* node1).data = 1; (* node1).next = node2;

  while (!NULL) {
    printf("%d\n", (*node1).data);
  }

}
