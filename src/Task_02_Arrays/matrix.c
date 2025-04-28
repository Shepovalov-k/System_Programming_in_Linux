#include <stdio.h>

void print_matrix(unsigned int number) {
    int value = 1;
    for(int i=0; i<number; i++) {
        for(int j=0; j<number; j++) {
            printf("%d", value);
            if (j < (number-1))
            {
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