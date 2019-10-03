#include <stdio.h>
#include <stdlib.h>

void hexa_to_unsigned(char hex_vec[3][9], unsigned* unsig_vec, int pos) {
  int i;

  for (i = 0; i < 3; i++) {
    unsig_vec[i] = strtol(hex_vec[i], NULL, 16);
  }
}


int read_input(unsigned* unsig_vec, int pos) {
  char hex_input[3][9];
  int ret_scanf = 0;

  ret_scanf = scanf("%8s %8s %8s", hex_input[0], hex_input[1], hex_input[2]);
  if (ret_scanf == 3) {
    hexa_to_unsigned(hex_input, unsig_vec, pos);
  }

  return ret_scanf;
}


int main() {
  int i;
  unsigned ptr1[3], ptr2[3], *dump;

  read_input(ptr1, 0);
  read_input(ptr2, 0);

  printf("\n\n");
  for (i = 0; i < 3; i++) {
    printf("%d ", ptr1[i]);
  }
  printf("\n");
  for (i = 0; i < 3; i++) {
    printf("%d ", ptr2[i]);
  }
  printf("\n");

  return 0;
}
