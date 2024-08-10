#include <iostream>

// Function to heapify the array
void MaxHeapPercolateDown(int index, int arr[], int size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        MaxHeapPercolateDown(largest, arr, size);
    }
}

// Heapsort function
void Heapsort(int numbers[], int numbersSize) {
    // Build max heap
    for (int i = numbersSize / 2 - 1; i >= 0; i--) {
        MaxHeapPercolateDown(i, numbers, numbersSize);
    }

    // Heap sort
    for (int i = numbersSize - 1; i > 0; i--) {
        std::swap(numbers[0], numbers[i]);
        MaxHeapPercolateDown(0, numbers, i);
    }
}

int main() {
    int numbers[] = {12, 11, 13, 5, 6, 7};
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    Heapsort(numbers, numbersSize);

    std::cout << "Sorted array: ";
    for (int i = 0; i < numbersSize; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
