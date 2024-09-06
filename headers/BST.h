#ifndef BST_h
#define BST_h

#include <stdlib.h>
#include <stdio.h>

typedef struct BST BST;

BST* createBST(int data);
BST* tinsert(BST* root, int data);
BST* tsearch(BST* root, int key);
BST* tdeleteNode(BST* root, int key);
BST* tfindMin(BST* root);
void tinorderTraversal(BST* root);
void deleteBST(BST* root);

#endif
