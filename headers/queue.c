#include "queue.h"

//-----------------Queue Node definition------------------------

struct qNode {
    int data;
    struct qNode* next;
};

//-----------------Queue definition-----------------------------

struct queue {
    struct qNode* front;
    struct qNode* rear;
    int size;
};

//-----------------Queue Initialization-------------------------

queue* createQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

//-----------------Queue Node Initialization--------------------

qNode* createNode(int data) {
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//-----------------Push element to queue------------------------

void qpush(queue* queue, int data) {
    qNode* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

//-----------------Pop element from queue-----------------------

void qpop(queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    qNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
}

//-----------------Front element of queue-----------------------

int qfront(queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

//-----------------Get size of queue----------------------------

int qgetSize(queue* queue) {
    return queue->size;
}

//-----------------Check if queue is empty----------------------

bool qisEmpty(queue* queue) {
    return queue->size == 0;
}

//-----------------Delete queue---------------------------------

void deleteQueue(queue* queue) {
    while (!qisEmpty(queue)) {
        qpop(queue);
    }
    free(queue);
}
