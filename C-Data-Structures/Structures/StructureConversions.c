/**
 * @file StructureConversions.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/04/2018
 *
 * @brief Source file for Structure Conversions in C
 *
 * Functions that can convert one structure to another exchanging integers
 *
 * There are two structures in each function: the source and the target
 * - Source is passed by single pointer
 * - Target is passed by double pointer to be modified (not initialized)
 *
 * Checks:
 * - If source is NULL
 * - If source is empty
 * - If implemented methods failed
 * - If memory allocation succeeded
 * - Safeguards in for loops
 * - In case of linear structures check if sizes match
 *
 */

#include "..\Headers\StructureConversions.h"

// +-------------------------------------------------------------------------------------------------+
// |                                            SLL -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_sll_to_arr(SinglyLinkedList *sll, Array **arr)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *head = sll->head;

	size_t list_size = 0;

	Status st = sll_get_length(sll, &list_size);
	
	if (st != DS_OK)
		return st;

	st = arr_init(arr, list_size);

	if (st != DS_OK)
		return st;

	if (!(*arr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < list_size; i++) {

		if (head == NULL)
			return DS_ERR_ITER;
		
		(*arr)->buffer[i] = head->data;
		
		head = head->next;
	}

	if ((*arr)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status convert_sll_to_darr(SinglyLinkedList *sll, DynamicArray **darr)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *head = sll->head;

	size_t list_size = 0;

	Status st = sll_get_length(sll, &list_size);

	if (st != DS_OK)
		return st;

	st = arr_init(darr, list_size);

	if (st != DS_OK)
		return st;

	if (!(*darr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < list_size; i++) {

		if (head == NULL)
			return DS_ERR_ITER;

		darr_push(darr, head->data);

		head = head->next;
	}

	if ((*darr)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            DAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_darr_to_sll(DynamicArray *darr, SinglyLinkedList **sll)
{
	if (darr == NULL)
		return DS_ERR_NULL_POINTER;

	if (darr->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	Status st = sll_init_list(sll);

	if (st != DS_OK)
		return st;

	if (!(*sll))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < darr->size; i++) {

		sll_insert_tail((*sll), darr->buffer[i]);
	}

	if ((*sll)->length != darr->size)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            AAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_arr_to_darr(Array *arr, DynamicArray **darr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	Status st = darr_init(darr, arr->size);

	if (st != DS_OK)
		return st;

	if (!(*darr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < arr->size; i++) {

		darr_push(darr, arr->buffer[i]);
	}

	if ((*darr)->size != arr->size)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}
