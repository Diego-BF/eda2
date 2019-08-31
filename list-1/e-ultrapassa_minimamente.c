#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
  int i = 0, index = 0, total_num = 0;
  unsigned int vet_num[SIZE], results[SIZE], input_num = 0, baseline = 0, sum = 0;

  scanf("%u", &input_num);
  while(input_num != 0) {
    vet_num[total_num] = input_num;
    total_num++;
    scanf("%u", &input_num);
  }

  if(total_num > 0) {
    scanf("%u", &baseline);
    for(i = 0; i < total_num; i++) {
      sum += vet_num[i];
      if(sum > baseline) {
        results[index] = vet_num[i];
        index++;
        sum = 0;
      }
    }

    for (i = (index-1); i >= 0; i--) {
      printf("%u\n", results[i]);
    }
  }

  else {
    printf("0\n");
  }

  return 0;
}
