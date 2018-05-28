/**
 * @file DoublyLinkedListTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/03/2018
 *
 * @brief Test Cases for @c DoublyLinkedLists implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "DoublyLinkedList.h"

int DoublyLinkedListTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Doubly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	DoublyLinkedList *dll;

	dll_init_list(&dll);

	// Test cases

	print_status_repr(dll_insert_head(dll, 1));  //DS_OK
	print_status_repr(dll_remove_head(dll));     //DS_OK

	print_status_repr(dll_insert_head(dll, 1));  //DS_OK
	print_status_repr(dll_remove_tail(dll));     //DS_OK

	print_status_repr(dll_insert_head(dll, 1));  //DS_OK
	print_status_repr(dll_remove_at(dll, 0));    //DS_OK

	print_status_repr(dll_insert_tail(dll, 1));  //DS_OK
	print_status_repr(dll_remove_head(dll));     //DS_OK

	print_status_repr(dll_insert_tail(dll, 1));  //DS_OK
	print_status_repr(dll_remove_tail(dll));     //DS_OK

	print_status_repr(dll_insert_tail(dll, 1));  //DS_OK
	print_status_repr(dll_remove_at(dll, 0));    //DS_OK

	print_status_repr(dll_insert_at(dll, 1, 0)); //DS_OK
	print_status_repr(dll_remove_head(dll));     //DS_OK

	print_status_repr(dll_insert_at(dll, 1, 0)); //DS_OK
	print_status_repr(dll_remove_tail(dll));     //DS_OK

	print_status_repr(dll_insert_at(dll, 1, 0)); //DS_OK
	print_status_repr(dll_remove_at(dll, 0));    //DS_OK

	print_status_repr(dll_remove_head(dll));     // DS_ERR_INVALID_OPERATION
	print_status_repr(dll_remove_tail(dll));     // DS_ERR_INVALID_OPERATION
	print_status_repr(dll_remove_at(dll, 0));    // DS_ERR_INVALID_OPERATION

	dll_display(dll);                            // Empty

	dll_delete_list(&dll);

	print_status_repr(dll_insert_head(dll, 1));  //DS_ERR_NULL_POINTER
	print_status_repr(dll_insert_at(dll, 1, 0)); //DS_ERR_NULL_POINTER
	print_status_repr(dll_insert_tail(dll, 1));  //DS_ERR_NULL_POINTER

	print_status_repr(dll_remove_head(dll));     //DS_ERR_NULL_POINTER
	print_status_repr(dll_remove_at(dll, 0));    //DS_ERR_NULL_POINTER
	print_status_repr(dll_remove_tail(dll));     //DS_ERR_NULL_POINTER
	
	dll_init_list(&dll);

	size_t len;
	int i;
	for (i = 0; i < 100; i++) {
		dll_insert_tail(dll, i);
	}

	DoublyLinkedList *dll_even = NULL, *dll_odd = NULL;
	DoublyLinkedNode *node;
	int data;
	if (dll_init_list(&dll_odd) == DS_OK && dll_init_list(&dll_even) == DS_OK) {
		dll_get_length(dll, &len);
		for (i = 0; i < len; i++) {
			dll_get_node_data(dll, 0, &data);
			if (data % 2 == 0) {
				dll_remove_node_head(dll, &node);
				dll_insert_node_tail(dll_even, node);
			}
			else {
				dll_remove_node_head(dll, &node);
				dll_insert_node_tail(dll_odd, node);
			}
		}
	}

	printf("\n");
	dll_display(dll);
	dll_display(dll_even);
	dll_display(dll_odd);
	
	dll_delete_list(&dll);
	dll_delete_list(&dll_even);
	dll_delete_list(&dll_odd);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- --------- Begin tests --------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	node = NULL;

	dll_init_list(&dll);

	size_t length = 0, l_max = 6, position = 0;
	int j, k, c, max = 100, value = 0;
	for (i = 0; i < 10000; i++)
	{
		printf("\n---------- ---------- ---------- ---------- ----------");

		j = rand();
		k = rand();
		c = rand() % 3;

		dll_get_length(dll, &length);
		len = 0;

		if (j % 2 == 0 && length < l_max) {
			// Insert
			if (k % 2 == 0) {
				// Insert
				if (c == 0) {
					// Head
					printf("\ndll_insert_head()");
					dll_insert_head(dll, rand() % max);
				}
				else if (c == 1) {
					// Middle
					printf("\ndll_insert_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					dll_insert_at(dll, rand() % max, len);
				}
				else {
					// Tail
					printf("\ndll_insert_tail()");
					dll_insert_tail(dll, rand() % max);
				}
			}
			else {
				// Push
				if (c == 0) {
					// Head
					printf("\ndll_insert_node_head()");
					dll_make_node(&node, rand() % max);
					dll_insert_node_head(dll, node);
				}
				else if (c == 1) {
					// Middle
					printf("\ndll_insert_node_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					dll_make_node(&node, rand() % max);
					dll_insert_node_at(dll, node, len);
				}
				else {
					// Tail
					printf("\ndll_insert_node_tail()");
					dll_make_node(&node, rand() % max);
					dll_insert_node_tail(dll, node);
				}
			}
		// End
		}
		else {
			// Remove
			if (k % 2 == 0) {
				// Slice
				if (c == 0) {
					// Head
					printf("\ndll_remove_head()");
					dll_remove_head(dll);
				}
				else if (c == 1) {
					// Middle
					printf("\ndll_remove_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					dll_remove_at(dll, len);
				}
				else {
					// Tail
					printf("\ndll_remove_tail()");
					dll_remove_tail(dll);
				}
			}
			else {
				// Pop
				if (c == 0) {
					// Head
					printf("\ndll_remove_node_head()");
					dll_remove_node_head(dll, &node);
					free(node);
				}
				else if (c == 1) {
					// Middle
					printf("\ndll_remove_node_at()");
					if (length != 0)
						len = rand() % length;
					printf(" position %zu", len);
					dll_remove_node_at(dll, &node, len);
					free(node);
				}
				else {
					// Tail
					printf("\ndll_remove_node_tail()");
					dll_remove_node_tail(dll, &node);
					free(node);
				}
			}
		// End
		}

		node = NULL;

		dll_display(dll);

		dll_find_max(dll, &value);
		dll_find_max_pos(dll, &position);
		printf("\nMaximum value: %d at position %zu", value, position);
		dll_find_min(dll, &value);
		dll_find_min_pos(dll, &position);
		printf("\nMinimum value: %d at position %zu", value, position);

		printf("\n---------- ---------- ---------- ---------- ----------");

	}

	printf("\nFinal list size: %zu", dll->length);

	dll_delete_list(&dll);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	printf("\n");
	return 0;
}