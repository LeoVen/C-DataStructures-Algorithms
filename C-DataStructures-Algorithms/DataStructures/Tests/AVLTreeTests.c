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
	printf(" |              C AVL Tree             |\n");
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
	avl_display_wrapper(avl, -1);
	printf("\n\nTotal elements: %zu\n", avl->size);

	avl_traversal_wrapper(avl, -1);
	avl_traversal_wrapper(avl, 0);
	avl_traversal_wrapper(avl, 1);
	printf("\nLeaves\n");
	avl_traversal_leaves(avl->root);

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
	avl_display_wrapper(avl, -1);
	printf("\n\nTotal elements: %zu\n", avl->size);

	avl_traversal_wrapper(avl, -1);
	avl_traversal_wrapper(avl, 0);
	avl_traversal_wrapper(avl, 1);
	printf("\nLeaves\n");
	avl_traversal_leaves(avl->root);
	
	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	avl_insert(avl, 8);
	avl_insert(avl, 10);
	avl_insert(avl, 9);

	printf("\n\n\n");
	avl_display_wrapper(avl, 0);
	
	st = avl_erase(&avl);

	if (st != DS_OK)
		return st;

	avl_insert(avl, 8);
	avl_insert(avl, 10);
	avl_insert(avl, 9);

	printf("\n\n\n");
	avl_display_wrapper(avl, 0);
	
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
	avl_display_wrapper(avl, 1);

	avl_traversal_wrapper(avl, -1);
	avl_traversal_wrapper(avl, 0);
	avl_traversal_wrapper(avl, 1);
	printf("\nLeaves\n");
	avl_traversal_leaves(avl->root);
	
	avl_delete(&avl);

	printf("\n\n");

	AVLTree *tree;

	int max1 = 0, max2 = 0, temp, j;

	if (avl_init_tree(&tree) == DS_OK)
	{
		for (int i = 0; i < 100; i++)
		{
			temp = rand() % 193;

			max1 += temp;

			if (avl_insert(tree, temp) != DS_OK)
			{
				print_status_repr(st);

				break;
			}
		}

		while (!avl_is_empty(tree))
		{
			st = avl_pop(tree, &j);

			if (st != DS_OK)
			{
				print_status_repr(st);

				break;
			}

			max2 += j;
		}

		printf("\nTotal inserted values : %d", max1);
		printf("\nTotal removed values  : %d", max2);
	}

	avl_delete(&tree);

	if (avl_init_tree(&avl) == DS_OK)
	{
		for (i = 0; i < 100; i++)
		{
			st = avl_insert(avl, i);

			if (st != DS_OK)
			{
				print_status_repr(st);

				break;
			}
		}

		for (int i = 99; i >= 0; i--)
		{
			printf("\n\n");
			avl_display_wrapper(avl, 1);
			printf("\n\n");

			st = avl_remove(avl, i);

			if (st != DS_OK)
			{
				print_status_repr(st);

				break;
			}
		}

		printf("\n\nAVL Tree Size: %zu", avl->size);
	}

	avl_delete(&avl);

	printf("\n");
	return 0;
}