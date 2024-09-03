#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

// ----------------Node in LinkedList---------------------------

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// ----------------LinkedList Definition------------------------

struct LinkedList {
	Node* head;
	Node* tail;
	int size;
};

// ----------------Create LinkedList----------------------------

LinkedList* createLinkedList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

// ----------------Create Node for LinkedList-------------------

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

// ----------------Push to start of List------------------------

void push_front(LinkedList* list, int data) {
	Node* newNode = createNode(data);
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
	} else {
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	list->size++;
}

// ----------------Push to back of List-------------------------

void push_back(LinkedList* list, int data) {
	Node* newNode = createNode(data);
	if (list->tail == NULL) {
		list->head = newNode;
		list->tail = newNode;
	} else {
		newNode->prev = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->size++;
}

// ----------------Pop from front of List-----------------------

void pop_front(LinkedList* list) {
	if (list->head == NULL) {
		printf("List is empty.\n");
		return;
	}
	Node* temp = list->head;
	list->head = list->head->next;
	if (list->head != NULL) {
		list->head->prev = NULL;
	} else {
		list->tail = NULL;
	}
	free(temp);
	list->size--;
}

// ----------------Pop from back of List------------------------

void pop_back(LinkedList* list) {
	if (list->tail == NULL) {
		printf("List is empty.\n");
		return;
	}
	Node* temp = list->tail;
	list->tail = list->tail->prev;
	if (list->tail != NULL) {
		list->tail->next = NULL;
	} else {
		list->head = NULL;  // If the list becomes empty
	}
	free(temp);
	list->size--;
}

// ----------------Get element at ith index---------------------

int getElement(LinkedList* list, int index) {
	if (index >= list->size) {
		printf("Index out of bounds.\n");
		return -1;  // Return an error value or handle the error as needed
	}

	Node* temp = list->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp->data;
}

// ----------------Set element at ith index---------------------

void setElement(LinkedList* list, int index, int data) {
	if (index >= list->size) {
		printf("Index out of bounds.\n");
		return;
	}

	Node* temp = list->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	temp->data = data;
}

// ----------------Remove element from ith index----------------

void removeElement(LinkedList* list, int index) {
	if (index >= list->size) {
		printf("Index out of bounds.\n");
		return;
	}

	Node* temp = list->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}

	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	} else {
		list->head = temp->next;
	}

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	} else {
		list->tail = temp->prev;
	}

	free(temp);
	list->size--;
}

// ----------------Get size of LinkedList-----------------------

int getSize(LinkedList* list) {
	return list->size;
}

// ----------------Check if list is empty-----------------------

int isEmpty(LinkedList* list) {
	return list->size == 0;
}

// ----------------Print LinkedList-----------------------------

void printList(LinkedList* list) {
	Node* temp = list->head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// ----------------Delete LinkedList----------------------------

void deleteList(LinkedList* list) {
	Node* current = list->head;
	Node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
