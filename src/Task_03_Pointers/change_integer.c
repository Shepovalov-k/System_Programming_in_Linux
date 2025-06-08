#include <stdio.h>

int main() {
  int number;
  printf("Введите число: ");
  scanf("%d", &number);

  printf("Введите новое значения 3 байта: ");
  unsigned char new_byte;
  scanf("%hhd", &new_byte);

  unsigned char *byte_ptr = (unsigned char *)&number;

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  byte_ptr[2] = new_byte;
#else
  byte_ptr[1] = new_byte;
#endif

  printf("Новое число: %d\n", number);
  return 0;
}