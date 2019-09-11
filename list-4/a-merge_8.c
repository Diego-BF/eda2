#include <stdio.h>

# define SIZE1 100000
# define SIZE2 200000
# define SIZE4 400000
# define SIZE8 800000


void read_list(int* size, int* vet) {
  int i;

  scanf("%d", size);
  for (i = 0; i < *size; i++) {
    scanf("%d", &vet[i]);
  }
}


void merge2(int* final_vet, int* vet1, int size1, int* vet2, int size2) {
  int i = 0, j = 0, pos = 0;

  while (i < size1 && j < size2) {
    if(vet1[i] < vet2[j]) {
      final_vet[pos] = vet1[i];
      i++;
    } else {
      final_vet[pos] = vet2[j];
      j++;
    }
    pos++;
  }

  while (i < size1) {
    final_vet[pos] = vet1[i];
    i++;
    pos++;
  }
  while (j < size2) {
    final_vet[pos] = vet2[j];
    j++;
    pos++;
  }
}


void merge4(int* final_vet, int* vet1, int size1, int* vet2, int size2,
            int* vet3, int size3, int* vet4, int size4) {
  int temp_vet1[SIZE2], temp_vet2[SIZE2], temp_size1, temp_size2;

  merge2(temp_vet1, vet1, size1, vet2, size2);
  merge2(temp_vet2, vet3, size3, vet4, size4);

  temp_size1 = size1 + size2;
  temp_size2 = size3 + size4;
  merge2(final_vet, temp_vet1, temp_size1, temp_vet2, temp_size2);
}

void merge8(int* final_vet, int* vet1, int size1, int* vet2, int size2,
            int* vet3, int size3, int* vet4, int size4, int* vet5, int size5,
            int* vet6, int size6, int* vet7, int size7, int* vet8, int size8) {
  int temp_vet1[SIZE4], temp_vet2[SIZE4], temp_size1, temp_size2;

  merge4(temp_vet1, vet1, size1, vet2, size2, vet3, size3, vet4, size4);
  merge4(temp_vet2, vet5, size5, vet6, size6, vet7, size7, vet8, size8);

  temp_size1 = size1 + size2 + size3 + size4;
  temp_size2 = size5 + size6 + size7 + size8;
  merge2(final_vet, temp_vet1, temp_size1, temp_vet2, temp_size2);
}


int main() {
  int i, final_size = 0, size1 = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0,
      size6 = 0, size7 = 0, size8 = 0;
  int final_vet[SIZE8], vet1[SIZE1], vet2[SIZE1], vet3[SIZE1], vet4[SIZE1], vet5[SIZE1],
      vet6[SIZE1], vet7[SIZE1], vet8[SIZE1];

  read_list(&size1, vet1);
  read_list(&size2, vet2);
  read_list(&size3, vet3);
  read_list(&size4, vet4);
  read_list(&size5, vet5);
  read_list(&size6, vet6);
  read_list(&size7, vet7);
  read_list(&size8, vet8);

  merge8(final_vet, vet1, size1, vet2, size2, vet3, size3, vet4, size4, vet5,
          size5, vet6, size6, vet7, size7, vet8, size8);

  final_size = size1 + size2 + size3 + size4 + size5 + size6 + size7 + size8;

  for (i = 0; i < final_size; i++) {
    printf("%d", final_vet[i]);
    if (i < final_size - 1) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
