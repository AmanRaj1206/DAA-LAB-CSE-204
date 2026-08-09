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

    // Bubble Sort 
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (Arr[j] > Arr[j + 1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }

    printf("Array after sorting in ascending order:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", Arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    // Binary Search
    int beg = 0;
    int end = N - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;

        if (Arr[mid] == key) {
            found = mid;
            break;
        }
        else if (key < Arr[mid]) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }

    if (found != -1) {
        printf("Element found at position %d\n", found + 1);
    } else {
        printf("Element not found in array\n");
    }

    return 0;
}
