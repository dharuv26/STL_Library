#ifndef priorityQuueue_h
#define priorityQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct priority_queue priority_queue;

int maxCmp(int a, int b);
int minCmp(int a, int b);
priority_queue* createPriorityQueue(int capacity, int (*compare)(int, int));
void pqresize(priority_queue* pq, int newCapacity);
void pqpush(priority_queue* pq, int data);
void pqpop(priority_queue* pq);
int pqtop(priority_queue* pq);
int pqgetSize(priority_queue* pq);
bool pqisEmpty(priority_queue* pq);
void deletePriorityQueue(priority_queue* pq);

#endif