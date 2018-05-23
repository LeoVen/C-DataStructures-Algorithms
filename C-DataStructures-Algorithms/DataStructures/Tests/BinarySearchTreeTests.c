/**
 * @file BinarySearchTreeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 17/05/2018
 *
 * @brief Test Cases for @c BinarySearchTree implementations in C
 *
 */

#include "..\Headers\BinarySearchTree.h"

int BinarySearchTreeTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Binary Search Tree        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	BinarySearchTree *bst;

	bst_init_tree(&bst);

	print_status_repr(bst_insert(bst, 100));
	print_status_repr(bst_insert(bst, 20));
	print_status_repr(bst_insert(bst, 150));
	print_status_repr(bst_insert(bst, 10));
	print_status_repr(bst_insert(bst, 30));
	print_status_repr(bst_insert(bst, 149));
	print_status_repr(bst_insert(bst, 160));

	printf("\n");

	bst_display(bst);
	printf("\n ---------- ---------- ---------- ----------\n");
	bst_traversal_wrapper(bst, 0);

	int i;
	for (i = 0; i < 100; i++)
	{
		bst_insert(bst, rand() % 200);
	}

	bst_display(bst);
	printf("\n ---------- ---------- ---------- ----------\n");
	bst_traversal_wrapper(bst, 0);

	//bst_delete(&bst);

	BinarySearchTree *b;
	bst_init_tree(&b);

	for (i = 0; i < 50; i++)
		bst_insert(b, rand() % 50);
	
	bst_display(b);

	bst_traversal_wrapper(b,-1); // preorder
	printf("\n\n");
	bst_traversal_wrapper(b, 0); // inorder
	printf("\n\n");
	bst_traversal_wrapper(b, 1); // postorder
	
	printf("\nLeaves: \n");
	bst_traversal_leaves(b->root);

	printf("\nTree depth: %zu", b->depth);

	//bst_delete(&b);

	printf("\n");
	return 0;
}