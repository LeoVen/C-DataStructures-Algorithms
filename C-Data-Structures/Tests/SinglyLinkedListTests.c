/*
 * SinglyLinkedListTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 14/03/2018
 *
 * Test Cases for Singly Linked Lists in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\SinglyLinkedList.h"

int SinglyLinkedListTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Singly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

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
	size_t j;
	if (sll_get_length(sll, &j) == DS_OK) {
		for (i = 0; i < j; i++) {
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
	do {
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

	for (i = 0; i < 100; i++) {
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

	printf("\n");
	return 0;
}