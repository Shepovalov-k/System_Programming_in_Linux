#include <stdio.h>

int digits_counter(int number) {
  int counter = 1;
  while (number = (int)(number / 10)) counter++;
  return counter;
}

void print_matrix(unsigned int number) {
  int value = 1;
  int num_of_digits = digits_counter(number * number);
  for (int i = 0; i < number; i++) {
    for (int j = 0; j < number; j++) {
      printf("%*d", num_of_digits, value);
      if (j < (number - 1)) {
        printf(" ");
      } else {
        printf("\n");
      }
      value++;
    }
  }
}

int main() {
  unsigned int number;
  printf("Enter the size of your matrix: ");
  scanf("%u", &number);
  print_matrix(number);
  return 0;
}