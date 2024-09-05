#include "BST.h"

//-----------------BST definition-------------------------------

struct BST {
	int data;
	struct BST* left;
	struct BST* right;
};

//-----------------Create a New Node----------------------------

BST* createBST(int data) {
	BST* newNode = (BST*)malloc(sizeof(BST));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//-----------------Insert a Node in BST-------------------------

BST* tinsert(BST* root, int data) {
	if (root == NULL) {
		return createBST(data);
	}

	if (data < root->data) {
		root->left = tinsert(root->left, data);
	} else if (data > root->data) {
		root->right = tinsert(root->right, data);
	}

	return root;
}

//-----------------Search a Node in BST-------------------------

BST* tsearch(BST* root, int key) {
	if (root == NULL || root->data == key) {
		return root;
	}

	if (key < root->data) {
		return tsearch(root->left, key);
	}

	return tsearch(root->right, key);
}

//-----------------Find Minimum Value Node----------------------

BST* tfindMin(BST* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

//-----------------Delete Node from BST-------------------------

BST* tdeleteNode(BST* root, int key) {
	if (root == NULL) {
		return root;
	}

	if (key < root->data) {
		root->left = tdeleteNode(root->left, key);
	} else if (key > root->data) {
		root->right = tdeleteNode(root->right, key);
	} else {
		if (root->left == NULL) {
			BST* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			BST* temp = root->left;
			free(root);
			return temp;
		}
		BST* temp = tfindMin(root->right);
		root->data = temp->data;
		root->right = tdeleteNode(root->right, temp->data);
	}
	return root;
}

//-----------------In-order Traversal---------------------------

void tinorderTraversal(BST* root) {
	if (root != NULL) {
		tinorderTraversal(root->left);
		printf("%d ", root->data);
		tinorderTraversal(root->right);
	}
}

//------------------Delete Tree---------------------------------

void deleteBST(BST* root) {
	if (root == NULL) return;

	deleteBST(root->left);
	deleteBST(root->right);
	free(root);
}