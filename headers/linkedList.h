#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

LinkedList* createLinkedList();
Node* createNode(int data);
void push_front(LinkedList* list, int data);
void push_back(LinkedList* list, int data);
void pop_front(LinkedList* list);
void pop_back(LinkedList* list);
void setElement(LinkedList* list, int i, int data);
void removeElement(LinkedList* list, int i);
int getElement(LinkedList* list, int i);
int getSize(LinkedList* list);
int isEmpty(LinkedList* list);
void printList(LinkedList* list);
void deleteList(LinkedList* list);

#endif
