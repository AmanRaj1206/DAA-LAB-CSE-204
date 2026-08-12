#include <stdio.h>

int main() {
    int N, key;
    int found = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter %d elements of array:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    for (int i = 0; i < N; i++) {
        if (Arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Element found at position %d\n", found + 1);
    } else {
        printf("Element not found in array\n");
    }

    return 0;
}
