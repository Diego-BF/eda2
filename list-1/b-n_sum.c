#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_entries, i, sum, entry;

  scanf("%d", &num_entries);

  sum = 0;
  for(i = 0; i < num_entries; i++) {
    scanf("%d", &entry);
    sum += entry;
  }

  printf("%d\n", sum);

  return 0;
}
