/*
 * @file CircularLinkedListTests.c
 *
 * @author Leonardo Vencovsky
 * @date 05/04/2018
 *
 * @brief Test Cases for @c CircularLinkedLists implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "..\Headers\CircularLinkedList.h"

int CircularLinkedListTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |        C Circular Linked List       |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CircularLinkedList *cll;

	cll_init_list(&cll);

	CircularLinkedNode *cln;

	cll_init_node(&cln);

	printf("\n");
	return 0;
}