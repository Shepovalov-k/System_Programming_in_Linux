#include <stdio.h>

void print_matrix(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", ((i + j + 1) < N) ? 0 : 1);
      if (j < (N - 1)) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }
}

int main() {
  int N;
  printf("Введите размерность матрицы: ");
  scanf("%u", &N);
  print_matrix(N);
  return 0;
}
