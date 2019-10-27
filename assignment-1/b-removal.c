#include <stdio.h>
#include <stdlib.h>

#define SIZE_DUMP 1000


typedef struct node_Struct {
  unsigned address;
  unsigned prev;
  unsigned next;
  int valid;
} node;


node read_input() {
  char hex_input[3][9];
  int ret_scanf = 0;
  node unsig_vec;

  ret_scanf = scanf("%8s %8s %8s", hex_input[0], hex_input[1], hex_input[2]);
  if (ret_scanf == 3) {
    // convert hexadecimal to unsigned
    unsig_vec.address = strtol(hex_input[0], NULL, 16);
    unsig_vec.prev = strtol(hex_input[1], NULL, 16);
    unsig_vec.next = strtol(hex_input[2], NULL, 16);
    unsig_vec.valid = 1;
  } else {
    unsig_vec.valid = 0;
  }

  return unsig_vec;
}


void swap(node *vector, int pos_1, int pos_2) {
  node temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}


int partition(node *vector, int pos_left, int pos_right) {
  int i, j;
  unsigned pivot_value;

  pivot_value = vector[pos_left].address;
  i = pos_left;
  j = pos_right;
  while (1) {
    while (i < pos_right && vector[i].address < pivot_value) {
      i++;
    }
    while (j > pos_left && vector[j].address > pivot_value) {
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


void quicksort(node *vector, int pos_left, int pos_right) {
  if (pos_left < pos_right) {
    int pivot = partition(vector, pos_left, pos_right);
    quicksort(vector, pos_left, pivot);
    quicksort(vector, pivot + 1, pos_right);
  }
}


node binary_search(node *vector, unsigned target, int size) {
  int start = 0, end = size - 1, mid = 0;
  node not_found;

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (vector[mid].address == target) {
      return vector[mid];
    }

    if (target < vector[mid].address) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  not_found.valid = 0;
  return not_found;
}


int main() {
  node ptr1, ptr2, dump[SIZE_DUMP], start, end, read_node;
  int length = 0, i = 0;
  unsigned removed_nodes[SIZE_DUMP];

  ptr1 = read_input();
  ptr2 = read_input();

  dump[0] = read_input();
  while (dump[length].valid && length < SIZE_DUMP) {
    length++;
    dump[length] = read_input();
    printf("dump: %u\n", dump[length].address);
  }
  quicksort(dump, 0, length - 1);


  start = binary_search(dump, ptr1.prev, length);
  end = binary_search(dump, ptr2.next, length);
  printf("end: %u\n", end.address);

  read_node = ptr1;
  while (read_node.next != end.address && i < 15) {
    removed_nodes[i] = read_node.address;
    printf("removed: %u\n", removed_nodes[i]);
    i++;
    read_node = binary_search(dump, read_node.next, length - 1);
    printf("read node: %u\n", read_node.address);
  }
  printf("size i = %d\n", i);

  return 0;
}
