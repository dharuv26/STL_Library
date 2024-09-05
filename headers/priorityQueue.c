#include "priorityQueue.h"

// ----------------Priority Queue Definition--------------------

struct priority_queue {
	int* array;
	int size;
	int capacity;
	int (*compare)(int, int);
};

// ----------------Comparison Functions-------------------------

int maxCmp(int a, int b) {
	return a > b;  // parent > child
}

int minCmp(int a, int b) {
	return a < b;  // parent < child
}

// ----------------Priority Queue Initialization----------------

priority_queue* createPriorityQueue(int capacity, int (*compare)(int, int)) {
	priority_queue* pq = (priority_queue*)malloc(sizeof(priority_queue));
	pq->array = (int*)malloc(sizeof(int) * capacity + 1);
	pq->size = 0;
	pq->capacity = capacity + 1;
	if (compare == NULL) pq->compare = maxCmp;
	else pq->compare = compare;
	return pq;
}

// ----------------Resize PQ------------------------------------

void pqresize(priority_queue* pq, int newCapacity) {
	pq->array = (int*)realloc(pq->array, sizeof(int) * newCapacity);
	pq->capacity = newCapacity;
}

// ----------------Push element to PQ---------------------------

void pqpush(priority_queue* pq, int data) {
	// Increase size of array
	if (pq->size == pq->capacity) {
		pqresize(pq, pq->capacity * 2);
	}

	pq->array[++pq->size] = data;
	int i = pq->size;

	// Swim Operation
	while (i > 1 && !pq->compare(pq->array[i / 2], pq->array[i])) {
		int temp = pq->array[i / 2];
		pq->array[i / 2] = pq->array[i];
		pq->array[i] = temp;
		i = i / 2; 
	}
}

// ----------------Pop element from PQ--------------------------

void pqpop(priority_queue* pq) {
	if (pqisEmpty(pq)) {
		printf("Priority Queue is empty.\n");
		return;
	}

	pq->array[1] = pq->array[pq->size--];

	// Sink Operation
	int i = 1;
	while (2 * i <= pq->size) {
		int j = 2 * i;
		if(j < pq->size && !pq->compare(pq->array[j], pq->array[j+1])) j++;
		if(pq->compare(pq->array[i], pq->array[j]) || pq->array[i] == pq->array[j]) break;

		int temp = pq->array[i];
		pq->array[i] = pq->array[j];
		pq->array[j] = temp;

		i = j;
	}

	// Decrease size of array
	if (pq->size > 0 && pq->size <= pq->capacity / 4) {
		pqresize(pq, pq->capacity / 2);
	}
}

// ----------------Top-most element of PQ-----------------------

int pqtop(priority_queue* pq) {
	if (pqisEmpty(pq)) {
		printf("Priority Queue is empty.\n");
		return -1;
	}
	return pq->array[1];
}

// ----------------Get size of PQ-------------------------------

int pqgetSize(priority_queue* pq) {
	return pq->size - 1;
}

// ----------------Check if PQ is empty-------------------------

bool pqisEmpty(priority_queue* pq) {
	return pq->size == 0;
}

// ----------------Delete Priority Queue------------------------

void deletePriorityQueue(priority_queue* pq) {
	free(pq->array);
	free(pq);
}
