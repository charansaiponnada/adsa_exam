#include <stdio.h>
struct Pair {
    int min, max;
};
struct Pair findMinMax(int arr[], int low, int high) {
    if (low == high) return (struct Pair){arr[low], arr[low]};
    if (high == low + 1) 
        return arr[low] > arr[high] ? (struct Pair){arr[high], arr[low]} : (struct Pair){arr[low], arr[high]};
    
    int mid = (low + high) / 2;
    struct Pair left = findMinMax(arr, low, mid), right = findMinMax(arr, mid + 1, high);
    
    return (struct Pair){left.min < right.min ? left.min : right.min, left.max > right.max ? left.max : right.max};
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Pair result = findMinMax(arr, 0, n - 1);
    printf("Min: %d, Max: %d\n", result.min, result.max);
    return 0;
}
