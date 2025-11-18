
#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int evenSum = 0, oddSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            evenSum += arr[i];
        else
            oddSum += arr[i];
    }

    printf("\nSum of elements at even positions: %d", evenSum);
    printf("\nSum of elements at odd positions: %d", oddSum);

    return 0;
}
