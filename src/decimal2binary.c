#include <stdio.h>
#include <string.h>

static void strrev(char* str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

static void decimal2strbinary(char* buffer, unsigned int number) {
  while (number != 0) {
    int digit = number % 2;
    number = number / 2;
    *buffer = '0' + digit;
    buffer++;
  }
  *(buffer + 1) = '\n';
  strrev(buffer);
}

int main() {
  unsigned int number;
  char buffer[100];

  scanf("%u", &number);

  decimal2strbinary(buffer, number);

  printf("%s", buffer);
  return 0;
}