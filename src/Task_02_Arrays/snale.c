#include <stdio.h>
#include <stdlib.h>

int digits_counter(int number) {
  int counter = 1;
  while (number = (int)(number / 10)) counter++;
  return counter;
}

int **matrix(int N) {
  int **result = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) result[i] = (int *)malloc(N * sizeof(int));
  return result;
}

void fill_row(int *row, int *start, int left, int right) {
  for (int i = left; i <= right; i++) {
    row[i] = (*start)++;
  }
}

void fill_column(int **M, int col, int *start, int top, int bottom) {
  for (int i = top; i <= bottom; i++) {
    M[i][col] = (*start)++;
  }
}

void fill_row_reverse(int *row, int *start, int left, int right) {
  for (int i = right; i >= left; i--) {
    row[i] = (*start)++;
  }
}

void fill_column_reverse(int **M, int col, int *start, int top, int bottom) {
  for (int i = bottom; i >= top; i--) {
    M[i][col] = (*start)++;
  }
}

void fill_matrix(int **matrix, int N) {
  int start = 1;
  int top = 0, bottom = N - 1;
  int left = 0, right = N - 1;

  while (left <= right && top <= bottom) {
    fill_row(matrix[top], &start, left, right);
    top++;

    fill_column(matrix, right, &start, top, bottom);
    right--;

    if (top <= bottom) {
      fill_row_reverse(matrix[bottom], &start, left, right);
      bottom--;
    }

    if (left <= right) {
      fill_column_reverse(matrix, left, &start, top, bottom);
      left++;
    }
  }
}

void print_matrix(int **matrix, int N) {
  int space_for_digits = digits_counter(N * N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%*d", space_for_digits, matrix[i][j]);
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
  scanf("%d", &N);
  int **M = matrix(N);
  fill_matrix(M, N);
  print_matrix(M, N);
  free_matrix(M, N);
  return 0;
}