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

	printf("\n");
	return 0;
}