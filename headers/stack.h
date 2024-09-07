#ifndef STACK_h
#define STACK_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode sNode;
typedef struct stack stack;

stack* createStack();
sNode* createNode(int data);
void spush(stack* stack, int data);
void spop(stack* stack);
int stop(stack* stack);
int sgetSize(stack* stack);
bool sisEmpty(stack* stack);
void deleteStack(stack* stack);

#endif
