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
  char* start = buffer;

  if (number == 0) {
    *buffer++ = '0';
    *buffer = '\0';
    return;
  }

  while (number != 0) {
    *buffer++ = '0' + (number & 1);
    number >>= 1;
  }
  *buffer = '\0';

  strrev(start);
}

int main() {
  unsigned int number;
  char buffer[100];

  scanf("%u", &number);

  decimal2strbinary(buffer, number);

  printf("%s", buffer);
  return 0;
}