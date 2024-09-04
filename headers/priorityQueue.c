#include "priorityQueue.h"
struct priority_queue {
    int* array;
    int size;
    int capacity;
    int (*compare)(int, int);  // Function pointer for comparison (min-heap or max-heap)
};

// Comparison functions for min-heap and max-heap
int maxCmp(int a, int b) {
    return a > b;  // Min-heap: parent > child
}

int minCmp(int a, int b) {
    return a < b;  // Max-heap: parent < child
}

// Create a priority queue with a given capacity and comparison function
priority_queue* createPriorityQueue(int capacity, int (*compare)(int, int)) {
    priority_queue* pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->array = (int*)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    if (compare == NULL) pq->compare = maxCmp;
    else pq->compare = compare;
    return pq;
}

// Resize the priority queue array to a new capacity
void pqresize(priority_queue* pq, int newCapacity) {
    pq->array = (int*)realloc(pq->array, sizeof(int) * newCapacity);
    pq->capacity = newCapacity;
}

// Push element to the priority queue
void pqpush(priority_queue* pq, int data) {
    // Double the array size if it's full
    if (pq->size == pq->capacity) {
        pqresize(pq, pq->capacity * 2);
    }

    // Insert the new element at the end
    pq->array[pq->size] = data;
    int i = pq->size;
    pq->size++;

    // Reorder the array to maintain the priority queue property
    while (i > 0 && pq->compare(pq->array[(i - 1) / 2], pq->array[i])) {
        int temp = pq->array[(i - 1) / 2];
        pq->array[(i - 1) / 2] = pq->array[i];
        pq->array[i] = temp;
        i = (i - 1) / 2; 
    }
}

// Pop the highest/lowest priority element from the priority queue
void pqpop(priority_queue* pq) {
    if (pqisEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    // Reorder the array to maintain the priority queue property
    int i = 0;
    while (2 * i + 1 <= pq->size) {
        // int best = i;
        // int left = 2 * i + 1;
        // int right = 2 * i + 2;

        // if (left < pq->size && pq->compare(pq->array[best], pq->array[left])) {
        //     best = left;
        // }
        // if (right < pq->size && pq->compare(pq->array[best], pq->array[right])) {
        //     best = right;
        // }
        // if (best == i) {
        //     break;
        // }

        int j = 2 * i + 1;
        if(j < pq->size && pq->array[j] < pq->array[j+1]) j++;
        if(pq->array[i] >= pq->array[j]) break;

        int temp = pq->array[i];
        pq->array[i] = pq->array[j];
        pq->array[j] = temp;

        i = j;
    }

    // Halve the array size if the number of elements is 1/4th of the capacity
    if (pq->size > 0 && pq->size <= pq->capacity / 4) {
        pqresize(pq, pq->capacity / 2);
    }
}

// Peek at the highest/lowest priority element
int pqtop(priority_queue* pq) {
    if (pqisEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return pq->array[0];
}

// Get the size of the priority queue
int pqgetSize(priority_queue* pq) {
    return pq->size;
}

// Check if the priority queue is empty
bool pqisEmpty(priority_queue* pq) {
    return pq->size == 0;
}

// Delete the priority queue
void deletePriorityQueue(priority_queue* pq) {
    free(pq->array);
    free(pq);
}
