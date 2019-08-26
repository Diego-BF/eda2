#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int entry;
  int count;
  count = 0;

  while(scanf("%u", &entry) != EOF) {
    count++;
  }

  printf("%d\n", count);

  return 0;
}
