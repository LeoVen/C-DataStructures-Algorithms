/*
 * DoublyLinkedListTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Test Cases for Doubly Linked Lists in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\DoublyLinkedList.h"

int DoublyLinkedListTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Doubly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	DoublyLinkedList *dll = getCDoublyLinkedList();
	DoublyLinkedNode *node = getCDoublyLinkedNode(2);
	int i;
	for (i = 0; i < 10; i++) {
		insertTailDLL(&dll, i);
	}
	for (i = 0; i < 10; i++) {
		insertHeadDLL(&dll, i);
	}
	displayListDLL(&dll);
	int size = getListSizeDLL(&dll);
	for (i = 0; i < size / 2; i++) {
		removeTailDLL(&dll);
	}
	displayListDLL(&dll);
	for (i = 0; i < size / 2; i++) {
		removeHeadDLL(&dll);
	}
	displayListDLL(&dll);

	// Test cases

	insertHeadDLL(&dll, 1);
	removeHeadDLL(&dll);
	insertHeadDLL(&dll, 1);
	removeTailDLL(&dll);
	// insertHeadDLL(&dll, 1);
	// removeMiddleDLL(&dll, 0);

	insertTailDLL(&dll, 1);
	removeHeadDLL(&dll);
	insertTailDLL(&dll, 1);
	removeTailDLL(&dll);
	// insertTailDLL(&dll, 1);
	// removeMiddleDLL(&dll, 0);

	// insertMiddle(&dll, 0, 1);
	// removeHeadDLL(&dll);
	// insertMiddle(&dll, 0, 1);
	// removeTailDLL(&dll);
	// insertMiddle(&dll, 0, 1);
	// removeMiddleDLL(&dll, 0);

	removeHeadDLL(&dll);
	removeTailDLL(&dll);
	// removeMiddleDLL(&dll, 0);

	displayListDLL(&dll); // Should give Empty

	free(dll);
	printf("\n");
	return 0;
}