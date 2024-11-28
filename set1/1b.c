#include <stdio.h>
int binarySearch(int arr[], int size, int key, int *comparisons) {
    int left = 0, right = size - 1, mid;
    *comparisons = 0;
    while (left <= right) {
        (*comparisons)++;
        mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    int n, key, result, comparisons;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    result = binarySearch(arr, n, key, &comparisons);
    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");
    printf("Number of comparisons: %d\n", comparisons);
    printf("Time complexity: O(log2(n)) where n = %d\n", n);
    return 0;
}