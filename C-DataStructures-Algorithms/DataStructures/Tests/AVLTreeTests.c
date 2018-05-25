/**
 * @file AVLTreeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Test Cases for @c AVLTree implementations in C
 *
 */

#include "..\Headers\AVLTree.h"

int AVLTreeTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C AVL Tree             |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	AVLTree *avl;

	avl_init_tree(&avl);

	printf("\n");
	return 0;
}