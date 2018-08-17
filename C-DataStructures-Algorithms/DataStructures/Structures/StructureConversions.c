/**
 * @file StructureConversions.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/04/2018
 *
 * @brief Source file for Structure Conversion implementations in C
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

#include "StructureConversions.h"

// +-------------------------------------------------------------------------------------------------+
// |                                            SLL -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_sll_to_arr(SinglyLinkedList *sll, Array **arr)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *scan = sll->head;

	size_t list_size = 0;

	Status st = sll_get_length(sll, &list_size);

	if (st != DS_OK)
		return st;

	st = arr_init(arr, list_size);

	if (st != DS_OK)
		return st;

	if (!(*arr))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < list_size; i++)
	{

		if (scan == NULL)
			return DS_ERR_ITER;

		(*arr)->buffer[i] = scan->data;

		scan = scan->next;
	}

	if ((*arr)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status convert_sll_to_darr(SinglyLinkedList *sll, DynamicArray **dar)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *scan = sll->head;

	size_t list_size = 0;

	Status st = sll_get_length(sll, &list_size);

	if (st != DS_OK)
		return st;

	st = dar_init(dar);

	if (st != DS_OK)
		return st;

	if (!(*dar))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < list_size; i++)
	{

		if (scan == NULL)
			return DS_ERR_ITER;

		dar_insert_back((*dar), scan->data);

		scan = scan->next;
	}

	if ((*dar)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status convert_sll_to_dll(SinglyLinkedList *sll, DoublyLinkedList **dll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *scan = sll->head;

	size_t list_size = 0;

	Status st = sll_get_length(sll, &list_size);

	if (st != DS_OK)
		return st;

	st = dll_init_list(dll);

	if (st != DS_OK)
		return st;

	if (!(*dll))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < list_size; i++)
	{

		st = dll_insert_tail(*dll, scan->data);

		if (st != DS_OK)
			return st;

		scan = scan->next;
	}

	if (sll->length != (*dll)->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            DAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_darr_to_sll(DynamicArray **dar, SinglyLinkedList **sll)
{
	if ((*dar) == NULL)
		return DS_ERR_NULL_POINTER;

	if ((*dar)->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	Status st = sll_init_list(sll);

	if (st != DS_OK)
		return st;

	if (!(*sll))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < (*dar)->size; i++)
	{

		st = sll_insert_tail((*sll), (*dar)->buffer[i]);

		if (st != DS_OK)
			return st;
	}

	if ((*sll)->length != (*dar)->size)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            AAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_arr_to_dar(Array *arr, DynamicArray **dar)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	Status st = dar_init(dar);

	if (st != DS_OK)
		return st;

	if (!(*dar))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < arr->size; i++)
	{

		st = dar_insert_back((*dar), arr->buffer[i]);

		if (st != DS_OK)
			return st;
	}

	if ((*dar)->size != arr->size)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}
