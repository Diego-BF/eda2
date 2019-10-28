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
    unsig_vec.valid = 0;
  } else {
    unsig_vec.address = -1;
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


int binary_search(node *vector, unsigned target, int size) {
  int start = 0, end = size - 1, mid = 0;

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (vector[mid].address == target) {
      return mid;
    }

    if (target < vector[mid].address) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1;
}


int main() {
  node ptr1, ptr2, dump[SIZE_DUMP];
  int length = 0, i = 0, end = -1, pos_node = -1;
  unsigned removed_nodes[SIZE_DUMP];

  dump[0] = read_input();
  while (dump[length].address != -1 && length < SIZE_DUMP) {
    length++;
    dump[length] = read_input();
  }
  ptr1 = dump[0];
  ptr2 = dump[1];
  quicksort(dump, 0, length);

  pos_node = binary_search(dump, ptr1.address, length);
  end = binary_search(dump, ptr2.next, length);
  while (pos_node != -1 && pos_node != end) {
    removed_nodes[i] = dump[pos_node].address;
    i++;
    pos_node = binary_search(dump, dump[pos_node].next, length);
  }

  pos_node = binary_search(dump, ptr1.prev, length);
  while (pos_node != -1) {
    dump[pos_node].valid = 1;
    if (dump[pos_node].prev) {
      pos_node = binary_search(dump, dump[pos_node].prev, length);
    } else {
      pos_node = -1;
    }
  }

  pos_node = binary_search(dump, ptr2.next, length);
  while (pos_node != -1 && dump[pos_node].next) {
    dump[pos_node].valid = 1;
    if (dump[pos_node].next) {
      pos_node = binary_search(dump, dump[pos_node].next, length);
    } else {
      pos_node = -1;
    }
  }

  for (int w = 0; w < length; w++) {
    if(dump[w].valid) {
      printf("%x %x %x\n", dump[w].address, dump[w].prev, dump[w].next);
    }
  }
  printf("\n");
  for (int z = 0; z < i; z++) {
    printf("%x\n", removed_nodes[z]);
  }
  return 0;
}
