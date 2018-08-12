/**
 * @file SinglyLinkedListTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/03/2018
 *
 * @brief Test Cases for @c SinglyLinkedList implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "SinglyLinkedList.h"

int SLL_IO_TESTS();

int SinglyLinkedListTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Singly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	//SLL_IO_TESTS();

	SinglyLinkedList *sll;
	if (sll_init_list(&sll) != DS_OK)
		printf("\nError");

	SinglyLinkedNode *node;
	if (sll_init_node(&node) != DS_OK)
		printf("\nError");

	node->data = 1;

	size_t len;

	if (sll_get_length(sll, &len) == DS_OK)
		printf("\nLength: %ld", (long)len);

	print_status_repr(sll_insert_head(sll, 2));
	print_status_repr(sll_insert_head(sll, 3));
	print_status_repr(sll_insert_head(sll, 4));

	if (sll_get_length(sll, &len) == DS_OK)
		printf("\nLength: %ld", (long)len);

	int res;

	print_status_repr(sll_get_node_data(sll, 1, &res));

	int i;
	size_t z;
	if (sll_get_length(sll, &z) == DS_OK)
	{
		for (i = 0; i < z; i++)
		{
			sll_get_node_data(sll, i, &res);
			printf("\nData of node at position %d = %d", i, res);
		}
	}

	print_status_repr(sll_insert_tail(sll, 3));
	print_status_repr(sll_insert_tail(sll, 4));
	print_status_repr(sll_insert_tail(sll, 5));

	print_status_repr(sll_insert_head(sll, 5));

	sll_display(sll);

	print_status_repr(sll_insert_at(sll, 2, 3));
	print_status_repr(sll_insert_at(sll, 1, 4));
	print_status_repr(sll_insert_at(sll, 1, 4));

	sll_display_raw(sll);

	int k;
	do
	{
		sll_get_node_data(sll, 0, &k);
		sll_remove_head(sll);
	} while (k != 1);

	sll_display(sll);

	size_t l;
	sll_get_length(sll, &l);
	while (l > 0)
	{
		sll_remove_tail(sll);
		sll_get_length(sll, &l);
	}

	sll_display(sll);

	for (i = 0; i < 100; i++)
	{
		sll_insert_tail(sll, i);
	}

	sll_display_raw(sll);

	k = 0;
	size_t p = 52;
	while (k < 70)
	{
		sll_get_node_data(sll, p, &k);
		sll_remove_at(sll, p);
	}

	sll_display_raw(sll);

	sll_delete_list(&sll);

	if (sll == NULL)
		printf("\nOK");

	sll_init_list(&sll);

	for (i = 0; i < 10; i++)
		sll_insert_tail(sll, i);

	sll_display(sll);

	sll_erase_list(&sll);

	sll_display(sll);

	for (i = 0; i < 100; i++)
		sll_insert_tail(sll, rand() % 10);

	size_t f;
	for (i = -10; i < 20; i++)
	{
		if (sll_exists(sll, i))
		{
			sll_frequency(sll, i, &f);
			printf("\nData %d frequency : %zu", i, f);
		}
		else
		{
			printf("\nData %d is not in the list", i);
		}
	}

	sll_erase_list(&sll);

	for (i = 0; i < 100; i++)
	{
		sll_insert_tail(sll, i);
	}

	SinglyLinkedList *sll_even = NULL, *sll_odd = NULL;

	int data;

	if (sll_init_list(&sll_odd) == DS_OK && sll_init_list(&sll_even) == DS_OK)
	{
		sll_get_length(sll, &len);
		for (i = 0; i < len; i++)
		{
			sll_get_node_data(sll, 0, &data);
			if (data % 2 == 0)
			{
				sll_remove_node_head(sll, &node);
				sll_insert_node_tail(sll_even, node);
			}
			else
			{
				sll_remove_node_head(sll, &node);
				sll_insert_node_tail(sll_odd, node);
			}
		}
	}

	printf("\n");
	sll_display(sll);
	sll_display(sll_even);
	sll_display(sll_odd);

	sll_erase_list(&sll);

	for (i = 0; i < 20; i++)
		sll_insert_head(sll, rand());

	int min, max;
	sll_find_max(sll, &max);
	sll_find_min(sll, &min);

	sll_display(sll);

	printf("\nMax value: %d\nMin value: %d\n", max, min);

	sll_erase_list(&sll);

	int val = 5;
	SinglyLinkedList *sll_result;

	for (i = 0; i < 100; i++)
		sll_insert_tail(sll, rand() % 10);

	printf("\nOccurrance list for value %d\n", val);

	sll_occurrance_list(sll, &sll_result, val);

	sll_display(sll_result);

	sll_get_length(sll_result, &f);

	for (l = 0; l < f; l++)
	{
		sll_get_node_data(sll_result, l, &i);
		sll_get_node_data(sll, (size_t)i, &data); // Not cool
		printf("\nNode at position %d has a value of %d", i, data);
	}

	sll_delete_list(&sll_result);

	printf("\n");

	sll_copy_list(sll_odd, &sll_result);

	sll_reverse(sll_result);

	sll_display(sll_result);

	sll_erase_list(&sll);

	// Test cases

	print_status_repr(sll_insert_head(sll, 1)); //DS_OK
	print_status_repr(sll_remove_head(sll));	//DS_OK

	print_status_repr(sll_insert_head(sll, 1)); //DS_OK
	print_status_repr(sll_remove_tail(sll));	//DS_OK

	print_status_repr(sll_insert_head(sll, 1)); //DS_OK
	print_status_repr(sll_remove_at(sll, 0));   //DS_OK

	print_status_repr(sll_insert_tail(sll, 1)); //DS_OK
	print_status_repr(sll_remove_head(sll));	//DS_OK

	print_status_repr(sll_insert_tail(sll, 1)); //DS_OK
	print_status_repr(sll_remove_tail(sll));	//DS_OK

	print_status_repr(sll_insert_tail(sll, 1)); //DS_OK
	print_status_repr(sll_remove_at(sll, 0));   //DS_OK

	print_status_repr(sll_insert_at(sll, 1, 0)); //DS_OK
	print_status_repr(sll_remove_head(sll));	 //DS_OK

	print_status_repr(sll_insert_at(sll, 1, 0)); //DS_OK
	print_status_repr(sll_remove_tail(sll));	 //DS_OK

	print_status_repr(sll_insert_at(sll, 1, 0)); //DS_OK
	print_status_repr(sll_remove_at(sll, 0));	//DS_OK

	print_status_repr(sll_remove_head(sll));  // DS_ERR_INVALID_OPERATION
	print_status_repr(sll_remove_tail(sll));  // DS_ERR_INVALID_OPERATION
	print_status_repr(sll_remove_at(sll, 0)); // DS_ERR_INVALID_OPERATION

	sll_display(sll); // Empty

	sll_delete_list(&sll);

	print_status_repr(sll_insert_head(sll, 1));  //DS_ERR_NULL_POINTER
	print_status_repr(sll_insert_at(sll, 1, 0)); //DS_ERR_NULL_POINTER
	print_status_repr(sll_insert_tail(sll, 1));  //DS_ERR_NULL_POINTER

	print_status_repr(sll_remove_head(sll));  //DS_ERR_NULL_POINTER
	print_status_repr(sll_remove_at(sll, 0)); //DS_ERR_NULL_POINTER
	print_status_repr(sll_remove_tail(sll));  //DS_ERR_NULL_POINTER

	// Occurrance
	sll_find_occurrance_first(sll_even, 16, &l);
	sll_remove_at(sll_even, l);

	sll_find_occurrance_first(sll_even, 32, &l);
	sll_remove_at(sll_even, l);

	sll_display(sll_even);

	sll_get_length(sll_even, &l);

	for (z = 0; z < l; z++)
	{
		sll_update_node_data(sll_even, z, 0);
	}

	sll_display(sll_even);

	sll_find_occurrance_last(sll_even, 0, &l);
	sll_update_node_data(sll_even, l, 9);

	sll_find_occurrance_last(sll_even, 0, &l);
	print_status_repr(sll_update_node_data(sll_even, l, 8));

	sll_display(sll_even);

	// Link and unlink
	sll_init_list(&sll);

	for (i = 110; i > 100; i--)
	{
		if (i % 2 != 0)
			sll_insert_tail(sll, i);
	}

	sll_display(sll);

	print_status_repr(sll_link(sll_even, sll_odd));

	sll_display(sll_even);
	print_status_repr(sll_get_length(sll_even, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	sll_erase_list(&sll_even);
	sll_erase_list(&sll_odd);
	sll_erase_list(&sll_result);

	for (i = 0; i > -5; i--)
		sll_insert_tail(sll_result, i);

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			sll_insert_tail(sll_even, i);
		else
			sll_insert_tail(sll_odd, i);
	}

	sll_display(sll_even);
	sll_display(sll_odd);

	// Link even to odd making even list empty
	sll_link(sll_odd, sll_even);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_even);
	print_status_repr(sll_get_length(sll_even, &len));
	printf("\nLength: %zu\n", len);

	// Unlink at first occurrance of a key
	sll_find_occurrance_first(sll_odd, 2, &len);

	sll_unlink(sll_odd, sll_even, len);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_even);
	print_status_repr(sll_get_length(sll_even, &len));
	printf("\nLength: %zu\n", len);

	// Link back at the first occurrence of a key
	sll_find_occurrance_first(sll_odd, 3, &len);

	// After key number
	sll_link_at(sll_odd, sll_even, len + 1);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_even);
	print_status_repr(sll_get_length(sll_even, &len));
	printf("\nLength: %zu\n", len);

	// Link at the beggining
	sll_link_at(sll_odd, sll, 0);

	sll_display(sll);
	print_status_repr(sll_get_length(sll, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	// Link at the end
	sll_get_length(sll_result, &len);

	sll_link_at(sll_result, sll_odd, len);

	sll_display(sll_odd);
	print_status_repr(sll_get_length(sll_odd, &len));
	printf("\nLength: %zu\n", len);

	sll_display(sll_result);
	print_status_repr(sll_get_length(sll_result, &len));
	printf("\nLength: %zu\n", len);

	// Free memory
	sll_delete_list(&sll);
	sll_delete_list(&sll_even);
	sll_delete_list(&sll_odd);
	sll_delete_list(&sll_result);

	sll_init_list(&sll);

	for (i = 0; i < 10; i++)
		sll_insert_tail(sll, i);

	sll_get_length(sll, &len);

	for (l = 0; l < len; l++)
	{
		sll_display(sll);

		sll_switch_ends(sll);

		sll_display(sll);

		sll_remove_tail(sll);
	}

	for (i = 0; i < 10; i++)
		sll_insert_tail(sll, i);

	sll_get_length(sll, &len);

	sll_display(sll);

	for (i = 0; i < 100; i++)
	{

		l = rand() % len;

		printf("\nSwitch head with %zu", l);
		sll_switch_head(sll, l);

		sll_display(sll);
	}

	for (i = 0; i < 100; i++)
	{

		l = rand() % len;

		printf("\nSwitch tail with %zu", l);
		sll_switch_tail(sll, l);

		sll_display(sll);
	}

	for (i = 0; i < 1000; i++)
	{

		l = rand() % len;
		f = rand() % len;

		if (sll_switch_nodes(sll, l, f) == DS_OK)
		{
			printf("\nSwitch nodes %zu with %zu", l, f);
			sll_display(sll);
		}
	}

	sll_delete_list(&sll);

	printf("\n---------- ---------- ---------- ---------- ----------");
	printf("\n---------- ---------- Bubble Sort --------- ----------");
	printf("\n---------- ---------- ---------- ---------- ----------");

	sll_init_list(&sll);

	for (i = 0; i < 10; i++)
	{
		sll_insert_tail(sll, i);
	}

	sll_get_length(sll, &len);

	for (k = 0; k < 10; k++)
	{

		printf("\nScramble: ");

		for (i = 0; i < 20; i++)
		{

			l = rand() % len;
			f = rand() % len;

			sll_switch_nodes(sll, l, f);
		}

		sll_display(sll);

		printf("\nSorting: ");

		sll_sort_bubble(sll);

		sll_display(sll);
	}

	sll_delete_list(&sll);

	sll_init_list(&sll);

	for (i = 0; i < 1000; i++)
		sll_insert_tail(sll, rand());

	sll_display(sll);

	Status st = sll_sort_bubble(sll);

	print_status_repr(st);

	sll_display(sll);

	bool r;
	sll_is_sorted(sll, &r);
	printf("\nNow SLL %s", (r) ? "is sorted" : "not sorted");

	sll_delete_list(&sll);

	/**************************************************
	 *
	 * SET FUNCTIONS
	 *
	 **************************************************/

	SinglyLinkedList *sll1, *sll2;

	sll_init_list(&sll1);

	sll_init_list(&sll2);

	for (i = 0; i < 8; i++)
	{
		sll_insert_head(sll1, rand() % 10);
		sll_insert_head(sll2, rand() % 10);
	}

	sll_display(sll1);
	sll_display(sll2);

	sll_is_set_wrapper(sll1, &r);
	printf("\nSLL1 is %s", (r) ? "a set" : "not a set");

	sll_is_set_wrapper(sll2, &r);
	printf("\nSLL2 is %s", (r) ? "a set" : "not a set");

	st = sll_set_make(sll1);
	print_status_repr(st);
	st = sll_set_make(sll2);
	print_status_repr(st);

	sll_is_set_wrapper(sll1, &r);
	printf("\nNow SLL1 is %s", (r) ? "a set" : "not a set");

	sll_is_set_wrapper(sll2, &r);
	printf("\nNow SLL2 is %s", (r) ? "a set" : "not a set");

	sll_display(sll1);
	sll_display(sll2);

	sll_is_disjoint_wrapper(sll1, sll2, &r);
	printf("\nSLL1 and SLL2 are %s", (r) ? "disjoint" : "not disjoint");

	// Union operation
	printf("\n ---------- Union:\n");
	sll_set_union(sll1, sll2, &sll);

	sll_display(sll);
	sll_delete_list(&sll);

	// Intersection operation
	printf("\n ---------- Intersection\n");
	sll_set_intersection(sll1, sll2, &sll);

	sll_display(sll);
	sll_delete_list(&sll);

	sll_delete_list(&sll1);
	sll_delete_list(&sll2);

	printf("\n");
	return 0;
}

int SLL_IO_TESTS()
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- --------- Begin tests --------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	SinglyLinkedNode *node = NULL;
	SinglyLinkedList *sll;

	sll_init_list(&sll);

	size_t len, length = 0, l_max = 6, position = 0;
	int i, j, k, c, max, value = 0;
	max = 100;
	k = 0;
	for (i = 0; i < 10000; i++)
	{
		printf("\n---------- ---------- ---------- ---------- ----------");

		j = rand();
		k = rand();
		c = rand() % 3;

		sll_get_length(sll, &length);
		len = 0;

		if (j % 2 == 0 && length < l_max)
		{
			// Insert
			if (k % 2 == 0)
			{
				// Insert
				if (c == 0)
				{
					// Head
					printf("\nsll_insert_head()");
					sll_insert_head(sll, rand() % max);
				}
				else if (c == 1)
				{
					// Middle
					printf("\nsll_insert_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					sll_insert_at(sll, rand() % max, len);
				}
				else
				{
					// Tail
					printf("\nsll_insert_tail()");
					sll_insert_tail(sll, rand() % max);
				}
			}
			else
			{
				// Push
				if (c == 0)
				{
					// Head
					printf("\nsll_insert_node_head()");
					sll_make_node(&node, rand() % max);
					sll_insert_node_head(sll, node);
				}
				else if (c == 1)
				{
					// Middle
					printf("\nsll_insert_node_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					sll_make_node(&node, rand() % max);
					sll_insert_node_at(sll, node, len);
				}
				else
				{
					// Tail
					printf("\nsll_insert_node_tail()");
					sll_make_node(&node, rand() % max);
					sll_insert_node_tail(sll, node);
				}
			}
			// End
		}
		else
		{
			// Remove
			if (k % 2 == 0)
			{
				// Slice
				if (c == 0)
				{
					// Head
					printf("\nsll_remove_head()");
					sll_remove_head(sll);
				}
				else if (c == 1)
				{
					// Middle
					printf("\nsll_remove_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					sll_remove_at(sll, len);
				}
				else
				{
					// Tail
					printf("\nsll_remove_tail()");
					sll_remove_tail(sll);
				}
			}
			else
			{
				// Pop
				if (c == 0)
				{
					// Head
					printf("\nsll_remove_node_head()");
					sll_remove_node_head(sll, &node);
					free(node);
				}
				else if (c == 1)
				{
					// Middle
					printf("\nsll_remove_node_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					sll_remove_node_at(sll, &node, len);
					free(node);
				}
				else
				{
					// Tail
					printf("\nsll_remove_node_tail()");
					sll_remove_node_tail(sll, &node);
					free(node);
				}
			}
			// End
		}

		node = NULL;

		sll_display(sll);

		sll_find_max(sll, &value);
		sll_find_max_pos(sll, &position);
		printf("\nMaximum value: %d at position %zu", value, position);
		sll_find_min(sll, &value);
		sll_find_min_pos(sll, &position);
		printf("\nMinimum value: %d at position %zu", value, position);

		printf("\n---------- ---------- ---------- ---------- ----------");
	}

	printf("\nFinal list size: %zu", sll->length);

	sll_delete_list(&sll);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");
}