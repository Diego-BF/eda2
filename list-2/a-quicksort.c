#include <stdio.h>

void swap(int *vector, int pos_1, int pos_2) {
  int temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}

int select_pivot(int *vector, int pos_left, int pos_right) {
  int mid = (pos_left + pos_right) / 2;
  if(vector[mid] < vector[pos_left]){ swap(vector, mid, pos_left); }
  if(vector[pos_right] < vector[pos_left]){ swap(vector, pos_right, pos_left); }
  if(vector[mid] < vector[pos_right]){ swap(vector, mid, pos_right); }
}

int partition(int *vector, int pos_left, int pos_right) {
  int i, j, pivot;
  select_pivot(vector, pos_left, pos_right);

  pivot = vector[pos_right];
  i = pos_left;
  j = pos_right - 1;
  while(i < j) {
    while(i <= j && vector[i] <= pivot) { i++; }
    while(i < j && vector[j] >= pivot) { j--; }
    if(i < j) {
      swap(vector, i, j);
      i++;
      j--;
    }
  }

}

void quicksort(int *vector, int pos_left, int pos_right) {
  if(pos_left < pos_right) {
    int pivot = partition(vector, pos_left, pos_right);
    quicksort(vector, pos_left, pivot - 1);
    quicksort(vector, pivot + 1, pos_right);
  }
}

int main() {
  int vect_num[1000], count = 0, num = 0, i, j;

  while(scanf("%d", &num) == 1) {
    vect_num[count] = num;
    count++;
  }

  return 0;
}
