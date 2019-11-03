#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_places = 0, num_Juliano = 0, num_visit = 0, **neighbours, index_n = 0, *visited = 0, *to_visit = 0;
  int i = 0, j = 0;

  scanf("%d %d %d", &num_places, &num_Juliano, &num_visit);

  neighbours = (int**) malloc(num_places * sizeof(int*));
  for (i = 0; i < num_places; i++) {
    neighbours[i] = (int*) malloc(num_places * sizeof(int));
  }

  visited = (int*) malloc(num_Juliano * sizeof(int));
  to_visit = (int*) malloc(j * sizeof(int));

  for (i = 0; i < num_places; i++) {
    scanf("%d", &index_n);

    for (j = 0; j < index_n; j++) {
      scanf("%d", &neighbours[i][j]);
    }
    neighbours[i][j] = -1;
  }

  for (i = 0; i < num_Juliano; i++) {
    scanf("%d", &visited[i]);
  }

  for (i = 0; i < num_visit; i++) {
    scanf("%d", &to_visit[i]);
  }

  // free alocated memory
  for (i = 0; i < num_places; i++) {
    free(neighbours[i]);
  }
  free(neighbours);
  free(visited);
  free(to_visit);

  return 0;
}
