#include "stack.h"

//-----------------Stack Node definition------------------------

struct sNode {
	int data;
	struct sNode* next;
};

//-----------------Stack definition-----------------------------

struct stack {
	sNode* top;
	int size;
};

//-----------------Stack Initialization-------------------------

stack* createStack() {
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->top = NULL;
	newStack->size = 0;
	return newStack;
}

//-----------------Stack Node Initialization--------------------

sNode* createNode(int data) {
	sNode* newNode = (sNode*)malloc(sizeof(sNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//-----------------Push element to stack------------------------

void spush(stack* stack, int data) {
	sNode* newNode = createNode(data);
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
}

//-----------------Pop element from stack-----------------------

void spop(stack* stack) {
	if (stack->top == NULL) {
		printf("Stack is empty.\n");
		return;
	}
	sNode* temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
}

//-----------------return element on top of stack---------------

int stop(stack* stack) {
	if (stack->top == NULL) {
		printf("Stack is empty.\n");
		return -1;
	}
	return stack->top->data;
}

//-----------------get size of stack----------------------------

int sgetSize(stack* stack) {
	return stack->size;
}

//-----------------Check if stack is empty----------------------

bool sisEmpty(stack* stack) {
	return stack->size == 0;
}

//-----------------Delete stack---------------------------------

void sdeleteStack(stack* stack) {
	while (!sisEmpty(stack)) {
		spop(stack);
	}
	free(stack);
}

