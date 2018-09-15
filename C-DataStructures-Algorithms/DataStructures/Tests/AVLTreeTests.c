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
#include "Random.h"

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
	for (i = 101; i < 356; i++)
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
	printf("\n\nTotal elements: %zu\n", avl->size);

	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	for (i = -101; i > -356; i--)
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
	printf("\n\nTotal elements: %zu\n", avl->size);
	
	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	avl_insert(avl, 8);
	avl_insert(avl, 10);
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

	int avl_min = 101, avl_max = 355;

	for (i = 0; i < 2000; i++)
	{
		st = avl_insert(avl, randint(avl_min, avl_max));

		if (st != DS_OK)
		{
			print_status_repr(st);
			break;
		}
	}

	printf("\n\n\n");
	avl_display_raw(avl->root, 0);
	
	avl_delete(&avl);

	printf("\n");
	return 0;
}