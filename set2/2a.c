#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int size;
} Heap;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapifyMin(Heap *heap, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < heap->size && heap->data[left] < heap->data[smallest]) smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap->data[i], &heap->data[smallest]);
        heapifyMin(heap, smallest);
    }
}
void heapifyMax(Heap *heap, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < heap->size && heap->data[left] > heap->data[largest]) largest = left;
    if (right < heap->size && heap->data[right] > heap->data[largest]) largest = right;
    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapifyMax(heap, largest);
    }
}
void insertMin(Heap *heap, int value) {
    heap->data[heap->size++] = value;
    int i = heap->size - 1;
    while (i > 0 && heap->data[i] < heap->data[(i - 1) / 2]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void insertMax(Heap *heap, int value) {
    heap->data[heap->size++] = value;
    int i = heap->size - 1;
    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteMin(Heap *heap) {
    heap->data[0] = heap->data[--heap->size];
    heapifyMin(heap, 0);
}
void deleteMax(Heap *heap) {
    heap->data[0] = heap->data[--heap->size];
    heapifyMax(heap, 0);
}
void displayHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++) printf("%d ", heap->data[i]);
    printf("\n");
}
int main() {
    Heap minHeap = { .size = 0 };
    Heap maxHeap = { .size = 0 };
    int choice, n, arr[MAX_SIZE];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        insertMin(&minHeap, arr[i]);
        insertMax(&maxHeap, arr[i]);
    }

    while (1) {
        printf("1. Delete from Min Heap\n2. Delete from Max Heap\n3. Display Min Heap\n4. Display Max Heap\n5. Exit\n");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
            case 1: deleteMin(&minHeap); break;
            case 2: deleteMax(&maxHeap); break;
            case 3: displayHeap(&minHeap); break;
            case 4: displayHeap(&maxHeap); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
