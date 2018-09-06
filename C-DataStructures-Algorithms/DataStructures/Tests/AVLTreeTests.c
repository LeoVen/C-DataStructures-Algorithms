/**
 * @file AVLTreeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Test Cases for @c AVLTree implementations in C
 *
 */

#include "AVLTree.h"

int AVLTreeTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               AVL Tree              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	AVLTree *avl;
	Status st;

	st = avl_init_tree(&avl);

	if (st != DS_OK)
		return -1;

	int i;
	for (i = 0; i < 10; i++)
	{
		st = avl_insert(avl, i);

		if (st != DS_OK)
		{
			print_status_repr(st);
			break;
		}
	}

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);

	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	for (i = 0; i > -10; i--)
	{
		st = avl_insert(avl, i);

		if (st != DS_OK)
		{
			print_status_repr(st);
			break;
		}
	}

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);
	/*
	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	avl_insert(avl, 10);
	avl_insert(avl, 8);
	avl_insert(avl, 9);

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);

	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	avl_insert(avl, 8);
	avl_insert(avl, 10);
	avl_insert(avl, 9);

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);
	
	avl_erase(&avl);

	for (i = 0; i < 20; i++)
	{
		st = avl_insert(avl, rand() % 40);

		if (st != DS_OK)
		{
			print_status_repr(st);
			break;
		}
	}

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);
	*/
	avl_delete(&avl);

	printf("\n");
	return 0;
}