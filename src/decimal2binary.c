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

int main() {
    unsigned int number;
    char binary_string_buffer[100];

    scanf("%u", &number);

    decimal_to_binary_string(binary_string_buffer, number);

    printf("Двоичное представление числа: %s\n", binary_string_buffer);
    return 0;
}