#include <stdio.h>

void __attribute__((destructor)) finished() {
    printf("Program finished completely. Cleaning global resources...\n");
}

int main() {
    printf("Program running...\n");
    return 0;
}

