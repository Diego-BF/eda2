#include <stdio.h>
#include <stdlib.h>

#define SIZE_VECT 10000


typedef struct node_Struct {
  unsigned address;
  unsigned prev;
  unsigned next;
  int valid;
} node;


node* read_input() {
  char hex_input[3][9];
  int ret_scanf = 0;
  node *unsig_vec = 0;

  ret_scanf = scanf("%8s %8s %8s", hex_input[0], hex_input[1], hex_input[2]);
  if (ret_scanf == 3) {
    // convert hexadecimal to unsigned
    unsig_vec = malloc(3 * sizeof(node));
    unsig_vec->address = strtol(hex_input[0], NULL, 16);
    unsig_vec->prev = strtol(hex_input[1], NULL, 16);
    unsig_vec->next = strtol(hex_input[2], NULL, 16);
  }
  return unsig_vec;
}


node** read_dump(int *length) {
  int i = 0;
  node **dump = 0, **temp_vect = 0;

  dump = malloc(SIZE_VECT * sizeof(node*));
  dump[0] = read_input();

  while (dump[*length]) {
    *length += 1;
    if (*length % SIZE_VECT == 0) {
      // increase the size of dump
      temp_vect = dump;
      dump = malloc((*length + SIZE_VECT) * sizeof(node*));

      for (i = 0; i < *length; i++) {
        dump[i] = temp_vect[i];
      }
      free(temp_vect);
    }
    dump[*length] = read_input();
  }
  return dump;
}


void swap(node **vector, int pos_1, int pos_2) {
  node *temp = vector[pos_1];
  vector[pos_1] = vector[pos_2];
  vector[pos_2] = temp;
}


int partition(node **vector, int pos_left, int pos_right) {
  int i, j;
  unsigned pivot_value;

  pivot_value = vector[pos_right]->address;
  i = pos_left;
  for (j = pos_left; j <= pos_right; j++) {
    if (vector[j]->address < pivot_value) {
      if (i != j) {
        swap(vector, i, j);
      }
      i++;
    }
  }
  swap(vector, i, pos_right);
  return i;
}


void quicksort(node **vector, int pos_left, int pos_right) {
  if (pos_left < pos_right) {
    int pivot = partition(vector, pos_left, pos_right);
    quicksort(vector, pos_left, pivot - 1);
    quicksort(vector, pivot + 1, pos_right);
  }
}


node* binary_search(node **vector, unsigned target, int size) {
  int left = 0, right = size - 1, mid = 0;

  while (left <= right) {
    mid = (left + right) / 2;

    if (vector[mid]->address == target) {
      return vector[mid];
    }

    if (vector[mid]->address > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return 0;
}


int main() {
  int length = 0, valid_path = 1, end_loop = 0;
  unsigned prev_ptr = 0;
  node *ptr1 = 0, *ptr2 = 0, **dump = 0, *curr_ptr = 0;

  ptr1 = read_input();
  ptr2 = read_input();
  dump = read_dump(&length);

  // sort the dump by pointer address
  quicksort(dump, 0, length - 1);

  //check if the path between pointer 1 and 2 is valid (in both directions)
  curr_ptr = ptr1;
  if (curr_ptr == 0 || curr_ptr->address == 0) {
    valid_path = 0;
  } else {
    prev_ptr = curr_ptr->prev;
  }

  while (valid_path && !end_loop) {
    if (curr_ptr->next == 0 || curr_ptr->prev != prev_ptr) {
      valid_path = 0;
    } else if (curr_ptr->next == ptr2->address) {
      end_loop = 1;
    } else {
      prev_ptr = curr_ptr->address;
      // do binary search
      curr_ptr = binary_search(dump, curr_ptr->next, length);
      if (curr_ptr == 0) {
        valid_path = 0;
      }
    }
  }


  // print if the path is sane
  if (valid_path) {
    printf("sana\n");
  } else {
    printf("insana\n");
  }

  // free alocated memory
  free(ptr1);
  free(ptr2);
  for (int i = 0; i < length; i++) {
    free(dump[i]);
  }
  free(dump);

  return 0;
}
