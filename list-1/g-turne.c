#include <stdio.h>

#define SIZE 3

int main() {
  char list_cities[SIZE][27], last_char;
  int index = 0, positions[SIZE], i, j;

  while(scanf("%26s", list_cities[index]) == 1) {
    printf("%s\n", list_cities[index]);
    index++;
  }

  for(i = 0; i < index; i++) {
    j = 0;
    while(list_cities[i][j] != '\0') {
      last_char = list_cities[i][j];
      j++;
    }
    printf("%c\n\n", last_char);

    if(list_cities[i+1][0] == last_char + 34) {
      printf("Deu match\n\n");
    }
  }

  return 0;
}
