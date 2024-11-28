#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    }    
    if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, high, key);
    }
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    return 0;
}
