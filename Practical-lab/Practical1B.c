//   B.	Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n == 0) {
        printf("NULL\n");
        return -1; 
    }
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Checking middle value: %d (Index: %d)\n", arr[mid], mid);
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return mid;
        }
        else if (key > arr[mid]) {
            printf("Adjusting start to mid + 1, new start index: %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Adjusting end to mid - 1, new end index: %d\n", mid - 1);
            end = mid - 1;
        }
    }
    printf("Element not found in the list.\n");
    return -1;
}
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    binarySearch(arr, n, key);
    return 0;
}
