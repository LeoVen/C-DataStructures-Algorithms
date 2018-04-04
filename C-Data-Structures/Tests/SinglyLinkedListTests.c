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
		printf("\n%u", len);

	double a = 3.14;

	print_status_repr(sll_insert_head(sll, &a));
	print_status_repr(sll_insert_head(sll, &len));

	if (sll_get_length(sll, &len) == DS_OK)
		printf("\n%u", len);

	void *res;

	print_status_repr(sll_get_node_data(sll, 1, &res));

	printf("\n%s", res);

	printf("\n");
	return 0;
}