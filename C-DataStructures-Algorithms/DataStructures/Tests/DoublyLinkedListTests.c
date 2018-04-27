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

	size_t len, i;
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
	return 0;
}