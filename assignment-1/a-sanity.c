#include <stdio.h>
#include <stdlib.h>

#define SIZE_VECT 10000


unsigned* read_input() {
  char hex_input[3][9];
  int ret_scanf = 0, i;
  unsigned *unsig_vec = 0;

  ret_scanf = scanf("%8s %8s %8s", hex_input[0], hex_input[1], hex_input[2]);
  if (ret_scanf == 3) {
    // convert hexadecimal to unsigned
    unsig_vec = malloc(3 * sizeof(unsigned));
    for (i = 0; i < 3; i++) {
      unsig_vec[i] = strtol(hex_input[i], NULL, 16);
    }
  }

  return unsig_vec;
}


unsigned** read_dump(int *length) {
  int i = 0;
  unsigned **dump = 0, **temp_vect = 0;

  dump = malloc(SIZE_VECT * sizeof(unsigned*));

  dump[0] = read_input();
  while (dump[*length]) {
    *length += 1;

    if (*length % SIZE_VECT == 0) {
      // increase the size of dump
      temp_vect = dump;
      dump = malloc((*length + SIZE_VECT) * sizeof(unsigned*));

      for (i = 0; i < *length; i++) {
        dump[i] = temp_vect[i];
      }
      free(temp_vect);
    }
    dump[*length] = read_input();
  }

  return dump;
}


void swap(unsigned **vector, int pos_1, int pos_2) {
  unsigned *temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}


int partition(unsigned **vector, int pos_left, int pos_right) {
  int i, j;
  unsigned pivot_value;

  pivot_value = vector[pos_left][0];
  i = pos_left;
  j = pos_right;
  while (1) {
    while (i < pos_right && vector[i][0] < pivot_value) {
      i++;
    }
    while (j > pos_left && vector[j][0] > pivot_value) {
      j--;
    }
    if (i < j) {
      swap(vector, i, j);
      i++;
      j--;
    } else {
      return j;
    }
  }
}


void quicksort(unsigned **vector, int pos_left, int pos_right) {
  if (pos_left < pos_right) {
    int pivot = partition(vector, pos_left, pos_right);
    quicksort(vector, pos_left, pivot);
    quicksort(vector, pivot + 1, pos_right);
  }
}


int main() {
  int i, length, valid_path = 1;
  unsigned *ptr1 = 0, *ptr2 = 0, **dump = 0;

  ptr1 = read_input();
  ptr2 = read_input();
  dump = read_dump(&length);

  // sort the dump by pointer address
  quicksort(dump, 0, length - 1);

  //check if the path between pointer 1 and 2 is valid

  //check if the path between pointer 2 and 1 (inverse) is valid

  // print if the path is sane
  if (valid_path) {
    printf("sana\n");
  } else {
    printf("insana\n");
  }

  // free alocated memory
  free(ptr1);
  free(ptr2);
  for (i = 0; i < length; i++) {
    free(dump[i]);
  }
  free(dump);

  return 0;
}
