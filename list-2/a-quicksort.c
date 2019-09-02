#include <stdio.h>

void swap(int *vector, int pos_1, int pos_2) {
  int temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}

int partition(int *vector, int pos_left, int pos_right) {
  int i, j, pivot;

  pivot = vector[pos_left];
  i = pos_left;
  j = pos_right;
  while (1) {
    while (i < pos_right && vector[i] < pivot) {
      i++;
    }
    while (j > pos_left && vector[j] > pivot) {
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

void quicksort(int *vector, int pos_left, int pos_right) {
  if (pos_left < pos_right) {
    int pivot = partition(vector, pos_left, pos_right);
    quicksort(vector, pos_left, pivot);
    quicksort(vector, pivot + 1, pos_right);
  }
}

int main() {
  int vect_num[100000], count = 0, num = 0, i;

  while (scanf("%d", &num) == 1) {
    vect_num[count] = num;
    count++;
  }

  quicksort(vect_num, 0, count - 1);

  if (count > 0) {
    for (i = 0; i < count; i++) {
      printf("%d", vect_num[i]);
      if (i != count -1) {
        printf(" ");
      }
    }
  }
  printf("\n");

  return 0;
}
