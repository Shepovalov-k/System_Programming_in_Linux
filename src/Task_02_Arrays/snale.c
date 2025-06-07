#include <stdio.h>
#include <stdlib.h>

int **matrix(int N) {
  int **result = (int **)malloc(N * sizeof(int **));
  for (int i = 0; i < N; i++) result[i] = (int *)malloc(N * sizeof(int *));
  return result;
}

void fill_row(int *row, int start, int N) {
  for (int i = 0; i < N; i++) {
    row[i] = start + i;
  }
}

void fill_matrix(int **matrix, int N) {
  int start = 1;
  int bottom = 0;
  int top = 0;
  int left = 0;
  int right = 0;
  fill_row(matrix[top], start, N);
}

void print_matrix(int **matrix, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%*d", 3, matrix[i][j]);
      if (j < (N - 1)) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }
}

void free_matrix(int **matrix, int N) {
  for (int i = 0; i < N; i++) free(matrix[i]);
  free(matrix);
}

int main() {
  int N;
  printf("Введите размерность матрицы: ");
  scanf("%u", &N);
  int **M = matrix(N);
  fill_matrix(M, N);
  print_matrix(M, N);
  free_matrix(M, N);
  return 0;
}