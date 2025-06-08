#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int *ptr=arr; ptr < (arr+9); ptr++) {
        printf("%d ", *ptr);
    }
    printf("%d\n", *(arr+9));
}