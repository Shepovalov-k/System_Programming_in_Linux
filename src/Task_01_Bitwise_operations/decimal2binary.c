#include <stdio.h>
#include <string.h>

static void reverse_string(char* str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = temp;
  }
}

static void decimal_to_binary_string(char* buffer, unsigned int number) {
  char* buffer_start = buffer;

  if (number == 0) {
    *buffer++ = '0';
    *buffer = '\0';
    return;
  } else {
    while (number != 0) {
      *buffer++ = '0' + (number & 1);
      number >>= 1;
    }
    *buffer = '\0';

    reverse_string(buffer_start);
  }
}

int count_1_digits(int number) {
  int counter = 0;
  while (number != 0) {
    if (number & 1) {
      counter++;
    }
    number >>= 1;
  }
  return counter;
}

int main() {
  unsigned int number;
  char binary_string_buffer[100];

  printf("Enter an integer number: ");
  scanf("%u", &number);

  decimal_to_binary_string(binary_string_buffer, number);

  printf("Binary representation of the number: %s\n", binary_string_buffer);
  printf("Number of ones in the binary representation: %d\n",
         count_1_digits(number));
  if (number >= 0) {
    printf("Enter a new value for 3rd byte (0-255): ");
    unsigned char new_byte;
    scanf("%hhu", &new_byte);

    number = (number & ~(0xFF << 16)) | (new_byte << 16);

    printf("A new value for the number: %d\n", number);
  }
  return 0;
}