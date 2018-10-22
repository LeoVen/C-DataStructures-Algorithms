/**
 * @file CircularLinkedListTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/04/2018
 *
 * @brief Test Cases for @c CircularLinkedList implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "CircularLinkedList.h"

int CLL_IO_TESTS(void);

int CircularLinkedListTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |        C Circular Linked List       |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CLL_IO_TESTS();

	CircularLinkedList *cll;

	cll_init_list(&cll);

	int i, j;
	for (i = 0; i < 20; i++)
	{
		cll_insert_after(cll, i);
	}

	cll_display(cll);

	for (i = 0; i < 10; i++)
	{
		cll_remove_after(cll, &j);
	}

	cll_display(cll);

	size_t n = 40, k = 13, result; // 14
	if (cll_josephus(n, k, &result) == DS_OK)
		printf("\n Josephus (%zu, %zu) = %zu\n", n, k, result);

	n = 1390, k = 33; // 1187
	if (cll_josephus(n, k, &result) == DS_OK)
		printf("\n Josephus (%zu, %zu) = %zu\n", n, k, result);

	n = 122, k = 244; // 44
	if (cll_josephus(n, k, &result) == DS_OK)
		printf("\n Josephus (%zu, %zu) = %zu\n", n, k, result);

	n = 8873, k = 652; // 6911
	if (cll_josephus(n, k, &result) == DS_OK)
		printf("\n Josephus (%zu, %zu) = %zu\n", n, k, result);

	cll_iter_prev(cll, 1);
	cll_display(cll);

	cll_iter_prev(cll, 1);
	cll_display(cll);

	cll_iter_prev(cll, 1);
	cll_display(cll);

	size_t cll_len = cll_length(cll);

	for (i = 0; i < cll_len; i++)
	{
		print_status_repr(cll_remove_current(cll, &j));
		cll_display(cll);
	}

	cll_delete_list(&cll);

	printf("\n");
	return 0;
}

int CLL_IO_TESTS(void)
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- --------- Begin tests --------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	CircularLinkedList *cll;

	Status st = cll_init_list(&cll);

	if (st != DS_OK)
		return st;

	size_t len, length = 0, l_max = 8, position = 0;
	int i, j, node, oper, place, max = 100, value = 0;
	for (i = 0; i < 1000; i++)
	{
		printf("\n---------- ---------- ---------- ---------- ----------");

		node = rand();
		oper = rand();
		place = rand() % 3;

		len = 0;

		if (oper % 2 == 0 && cll_length(cll) < l_max)
		{
			// Insert
			if (/*node % 2 == 0*/ 1)
			{
				// Insert
				if (place == 1)
				{
					// Before
					printf("\ncll_insert_before()");
					st = cll_insert_before(cll, rand() % max);

				}
				else
				{
					// After
					printf("\ncll_insert_after()");
					st = cll_insert_after(cll, rand() % max);
					
				}
			}
			/*
			else
			{
				// Node
			}
			*/
		}
		else
		{
			// Remove
			if (/*node % 2 == 0*/ 1)
			{
				// Remove
				if (place == 0)
				{
					// Before
					printf("\ncll_remove_before()");
					st = cll_remove_before(cll, &j);
					printf(" -> %d", j);
				}
				else if (place == 1)
				{
					// Current
					printf("\ncll_remove_current()");
					st = cll_remove_current(cll, &j);
					printf(" -> %d", j);
					
				}
				else
				{
					// After
					printf("\ncll_remove_after()");
					st = cll_remove_after(cll, &j);
					printf(" -> %d", j);
					
				}
			}
			/*
			else
			{
				// Node
			}
			*/
			// End
		}

		cll_display(cll);

		cll_find_max(cll, &value);
		printf("\nMaximum value: %d", value);
		cll_find_min(cll, &value);
		printf("\nMinimum value: %d", value);

		printf("\n---------- ---------- ---------- ---------- ----------");
	}

	printf("\nFinal list size: %zu", cll->length);

	cll_delete_list(&cll);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

}