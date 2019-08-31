#include <stdio.h>

void swap(int *vector, int pos_1, int pos_2) {
  int temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}

int main() {
  int vect_num[1000], count = 0, num = 0, i, j;

  while(scanf("%d", &num) == 1) {
    vect_num[count] = num;
    count++;
  }

  if(count > 0) {
    for(i = 1; i < count; i++) {
      for(j = i; j > 0; j--) {
        if(vect_num[j] < vect_num[j-1]) {
          swap(vect_num, j, j-1);
        }
      }
    }
    for(i = 0; i < count; i++) {
      printf("%d", vect_num[i]);
      if(i != count -1) {
        printf(" ");
      }
    }
  }
  printf("\n");

  return 0;
}
