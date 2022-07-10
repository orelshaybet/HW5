#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#include <stdlib.h>


// my functions
TreeNode* create_new_node(); 
void insert_new_node(TreeNode* root, int value);
void in_order(TreeNode* root);
void freeTree(TreeNode* root);
int change_the_order(TreeNode* root, int n, int* x);
void check_height(TreeNode* root, int n, int* x);


void initBST(BST* bst) // Q1
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value) // Q2
{
	if (bst->root == NULL)
	{
		bst->root = create_new_node();
		bst->root->element = value;
	}
	else
	{
		insert_new_node(bst->root, value);
	}
}

TreeNode* create_new_node()
{
	TreeNode* tmp;
	tmp = (TreeNode*)malloc(sizeof(TreeNode));
	CHECKNULL(&tmp);
	tmp->right = NULL;
	tmp->left = NULL;
	return tmp;
}

void insert_new_node(TreeNode* root, int value)
{
	if (value <= root->element)
	{
		if (root->left == NULL) {
			root->left = create_new_node();
			root->left->element = value;
		}
		else
		{
			insert_new_node(root->left, value);
		}
	}

	if (value > root->element)
	{
		if (root->right == NULL)
		{
			root->right = create_new_node();
			root->right->element = value;
		}
		else
		{
			insert_new_node(root->right, value);
		}
	}

}

void printTreeInorder(BST* bst) // Q3
{
	if (bst->root == NULL)
	{
		printf("--Empty tree--");
	}
	else
	{
		in_order(bst->root);
	}
}

void in_order(TreeNode* root)
{
	if (root != NULL)
	{
		in_order(root->left);
		printf("%d ", root->element);
		in_order(root->right);
	}
}

void destroyBST(BST* bst)// Q4
{
	if (bst->root == NULL)
	{
		return;
	}
	freeTree(bst->root);
}

void freeTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		root = NULL;
		return;
	}
	freeTree(root->left);
	if (root->left != NULL)
	{
		root->left = NULL;
	}
	freeTree(root->right);
	if (root->right != NULL)
	{
		root->right = NULL;
	}
}

int findIndexNFromLast(BST* bst, int N) // Q5
{
	int t;
	change_the_order(bst->root, N - 1, &t);
	return t;
}

int change_the_order(TreeNode* root, int n, int* t)
{
	if (root != NULL)
	{
		n = change_the_order(root->right, n, t);
		if (n == 0)
		{
			*t = root->element;
		}
		n = change_the_order(root->left, n - 1, t);
		if (n == 0)
		{
			*t = root->element;
		}
	}
	return n;
}

int sameHeightLeaves(BST* bst) // Q6
{
	int h = -1;
	int n = 0;
	check_height(bst->root, n, &h);
	if (h >= 0)
	{
		return 1;
	}
	else if (h == -2)
	{
		return 0;
	}
	else
	{
		printf("Empty tree");
	}
}

void check_height(TreeNode* root, int n, int* h)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (*h > 0 && *h != n)
			{
				*h = -2;
			}
			else if (*h == -1)
			{
				*h = n;
			}
			return;
		}
		check_height(root->left, n + 1, h);
		check_height(root->right, n + 1, h);
	}
}