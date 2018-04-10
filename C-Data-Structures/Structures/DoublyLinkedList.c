/*
 * @file DoublyLinkedList.c
 *
 * @author Leonardo Vencovsky
 * @date 18/03/2018
 *
 * @brief Doubly Linked List implementations in C
 *
 */

 /*
    Return Codes

   -1 - List Erased
    0 - Success
    1 - List not Initialized or locked
    2 - Invalid Position
    3 - List is Empty
    4 - Only one node -> won't reverse list

  */

#include "..\Headers\DoublyLinkedList.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status dll_init_list(DoublyLinkedList **dll)
{
	(*dll) = malloc(sizeof(DoublyLinkedList));

	if (!(*dll))
		return DS_ERR_ALLOC;

	(*dll)->length = 0;
	(*dll)->head = NULL;
	(*dll)->tail = NULL;

	return DS_OK;
}

Status dll_init_node(DoublyLinkedNode **node)
{
	(*node) = malloc(sizeof(DoublyLinkedNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = NULL;
	(*node)->next = NULL;
	(*node)->prev = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

DoublyLinkedList * dll_get_list()
{
	DoublyLinkedList *dll = malloc(sizeof(DoublyLinkedList));

	dll->length = 0;
	dll->head = NULL;
	dll->tail = NULL;

	return dll;
}

DoublyLinkedNode * dll_get_node(int value)
{
	DoublyLinkedNode *node = malloc(sizeof(DoublyLinkedNode));

	node->data = value;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

Status dll_make_node(DoublyLinkedNode **node, int value)
{
	(*node) = malloc(sizeof(DoublyLinkedNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->next = NULL;
	(*node)->prev = NULL;
	(*node)->data = value;

	return DS_OK;
}

Status dll_get_length(DoublyLinkedList *dll, size_t *result)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	DoublyLinkedNode *scan = dll->head;

	*result = 0;

	while (scan != NULL)
	{
		scan = scan->next;
		(*result)++;
	}

	if ((*result) != dll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                              Node                                               |
// +-------------------------------------------------------------------------------------------------+

//Status dll_get_node_data(DoublyLinkedList *dll, size_t position, int *result)
//Status dll_update_node_data(DoublyLinkedList *dll, int value, size_t position)

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status dll_insert_head(DoublyLinkedList *dll, int value)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	DoublyLinkedNode *node;

	Status st = dll_make_node(&node, value);

	if (st != DS_OK)
		return st;

	if (!node)
		return DS_ERR_ALLOC;

	if (dll->length == 0 || dll->head == NULL) {
		
		dll->head = node;
		dll->tail = node;
	
	}
	else {

		node->next = dll->head;

		dll->head->prev = node;

		dll->head = node;

	}

	(dll->length)++;

	return DS_OK;
}

//Status dll_insert_at(DoublyLinkedList *dll, int value, size_t position);

Status dll_insert_tail(DoublyLinkedList *dll, int value)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	DoublyLinkedNode *node;

	Status st = dll_make_node(&node, value);

	if (st != DS_OK)
		return st;

	if (!node)
		return DS_ERR_ALLOC;

	if (dll->length == 0 || dll->head == NULL) {

		dll->head = node;
		dll->tail = node;

	}
	else {

		dll->tail->next = node;

		node->prev = dll->tail;

		dll->tail = node;

	}

	(dll->length)++;

	return DS_OK;
}

//Status dll_insert_node_head(DoublyLinkedList *dll, DoublyLinkedList *node);
//Status dll_insert_node_at(DoublyLinkedList *dll, DoublyLinkedList *node, size_t position);
//Status dll_insert_node_tail(DoublyLinkedList *dll, DoublyLinkedList *node);

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status dll_remove_head(DoublyLinkedList *dll)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;

	DoublyLinkedNode *node = dll->head;

	dll->head = dll->head->next;

	if (dll->head == NULL)
		dll->tail == NULL;
	else
		dll->head->prev = NULL;

	free(node);

	(dll->length)--;

	return DS_OK;
}

//Status dll_remove_at(DoublyLinkedList *dll, size_t position);

Status dll_remove_tail(DoublyLinkedList *dll)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;

	DoublyLinkedNode *before = NULL;
	DoublyLinkedNode *curr = dll->head;

	while (curr->next != NULL)
	{
		before = curr;
		curr = curr->next;
	}

	if (before == NULL) {

		free(curr);

		dll->head = NULL;
		dll->tail = NULL;

	}
	else {

		before->next = NULL;
		dll->tail = before;

		free(curr);

	}

	(dll->length)--;

	return DS_OK;
}

//Status dll_remove_node_head(DoublyLinkedList *dll, DoublyLinkedList **node);
//Status dll_remove_node_at(DoublyLinkedList *dll, DoublyLinkedList **node, size_t position);
//Status dll_remove_node_tail(DoublyLinkedList *dll, DoublyLinkedList **node);

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status dll_display(DoublyLinkedList *dll)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll)) {

		printf("\nDoubly Linked List\n[ empty ]\n");
		return DS_OK;

	}

	DoublyLinkedNode *scan = dll->head;

	printf("\nDoubly Linked List\n");

	while (scan != NULL)
	{
		printf(" %d ->", scan->data);
		scan = scan->next;
	}

	printf(" NULL\n");

	return DS_OK;
}

Status dll_display_raw(DoublyLinkedList *dll)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;

	DoublyLinkedNode *scan = dll->head;

	printf("\n");

	while (scan != NULL)
	{
		printf("%d ", scan->data);
		scan = scan->next;
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status dll_delete_node(DoublyLinkedNode **node)
{
	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status dll_delete_list(DoublyLinkedList **dll)
{
	if ((*dll) == NULL)
		return DS_ERR_NULL_POINTER;

	DoublyLinkedNode *prev = (*dll)->head;

	while ((*dll)->head != NULL)
	{
		(*dll)->head = (*dll)->head->next;
		free(prev);
		prev = (*dll)->head;
	}

	free((*dll));

	(*dll) = NULL;

	return DS_OK;
}

Status dll_erase_list(DoublyLinkedList **dll)
{
	if ((*dll) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = dll_delete_list(dll);

	if (st != DS_OK)
		return st;

	st = dll_init_list(dll);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status dll_frequency(DoublyLinkedList *dll, int key, size_t *frequency)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;

	DoublyLinkedNode *scan = dll->head;

	*frequency = 0;

	while (scan != NULL)
	{
		if (scan->data == key)
			(*frequency)++;

		scan = scan->next;
	}

	return DS_OK;
}

Status dll_contains(DoublyLinkedList *dll, int key, bool *result)
{
	*result = false;

	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_NOT_FOUND;

	DoublyLinkedNode *scan = dll->head;

	while (scan != NULL)
	{
		if (scan->data == key) {

			result = true;
			break;

		}

		scan = scan->next;
	}

	return DS_OK;
}

bool dll_exists(DoublyLinkedList *dll, int key)
{
	if (dll == NULL)
		return false;

	if (sll_is_empty(dll))
		return false;

	DoublyLinkedNode *scan = dll->head;

	while (scan != NULL)
	{
		if (scan->data == key)
			return true;

		scan = scan->next;
	}

	return false;
}

bool dll_is_empty(DoublyLinkedList *dll)
{
	if (dll->length == 0 || dll->head == NULL)
		return true;
	else
		return false;
}

Status dll_find_max(DoublyLinkedList *dll, int *result)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;


	DoublyLinkedNode *scan = dll->head;

	int max = scan->data;
	while (scan != NULL)
	{
		if (scan->data > max)
			max = scan->data;

		scan = scan->next;
	}

	*result = max;

	return DS_OK;
}

Status dll_find_min(DoublyLinkedList *dll, int *result)
{
	if (dll == NULL)
		return DS_ERR_NULL_POINTER;

	if (dll_is_empty(dll))
		return DS_ERR_INVALID_OPERATION;


	DoublyLinkedNode *scan = dll->head;

	int min = scan->data;
	while (scan != NULL)
	{
		if (scan->data < min)
			min = scan->data;

		scan = scan->next;
	}

	*result = min;

	return DS_OK;
}

//Status dll_occurrance_list(DoublyLinkedList *dll, DoublyLinkedList **result, int key);

//Status dll_find_occurrance_first(DoublyLinkedList *dll, int key, size_t *position);
//Status dll_find_occurrance_last(DoublyLinkedList *dll, int key, size_t *position);

// +-------------------------------------------------------------------------------------------------+
// |                                         Slice / Link                                            |
// +-------------------------------------------------------------------------------------------------+

//Status dll_link_head(DoublyLinkedList *dll1, DoublyLinkedList *dll2);
//Status dll_link_at(DoublyLinkedList *dll1, DoublyLinkedList *dll2, size_t position);
//Status dll_link_tail(DoublyLinkedList *dll1, DoublyLinkedList *dll2);

//Status dll_slice_head(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position);
//Status dll_slice_sublist(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position1, size_t position2);
//Status dll_slice_tail(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position);

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

//Status dll_copy_list(DoublyLinkedList *dll, DoublyLinkedList **result);
//Status dll_copy_node(DoublyLinkedList *node, DoublyLinkedList **result);

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

//Status dll_switch_nodes(DoublyLinkedList *dll, size_t position1, size_t position2);
//Status dll_switch_head(DoublyLinkedList *dll, size_t position);
//Status dll_switch_tail(DoublyLinkedList *dll, size_t position);
//Status dll_switch_ends(DoublyLinkedList *dll);

//Status dll_sort_bubble(DoublyLinkedList *dll);
//Status dll_sort_slection(DoublyLinkedList *dll);
//Status dll_sort_insertion(DoublyLinkedList *dll);

//Status dll_merge_sorted(DoublyLinkedList *dll1, DoublyLinkedList *dll2, DoublyLinkedList **result);