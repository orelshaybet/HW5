#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>


void main()
{
	BST t;
	initBST(&t);
	insertBST(&t, 7);
	insertBST(&t, 12);
	insertBST(&t, 5);
	insertBST(&t, 1);
	insertBST(&t, 11);
	insertBST(&t, 10);
	insertBST(&t, 6);
	insertBST(&t, 4);
	insertBST(&t, 8);


	print_ascii_tree(t.root);

	printf("\n");
	printTreeInorder(&t);
	printf("\n");
	printf("%d\n", findIndexNFromLast(&t, 4));
	
	if (sameHeightLeaves(&t))
	{
		printf("same height!\n");
	}
	else
	{
		printf("not the same height...\n");
	}
	destroyBST(&t);
}