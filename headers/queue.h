#ifndef stack_h
#define stack_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct qNode qNode;
typedef struct queue queue;

queue* createQueue();
qNode* createNode(int data);
void qpush(queue* queue, int data);
void qpop(queue* queue);
int qfront(queue* queue);
int qgetSize(queue* queue);
bool qisEmpty(queue* queue);
void deleteQueue(queue* queue);

#endif
