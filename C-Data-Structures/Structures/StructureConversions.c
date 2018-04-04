/*
 * StructureConversions.c
 *
 * Author: Leonardo Vencovsky
 * Created on 02/04/2018
 *
 * Structure Conversions in C
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
/*
Status convert_sll_to_array(SinglyLinkedList *sll, Array **arr)
{
	if (!sll)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *head = sll->head;

	if (head == NULL)
		return DS_ERR_INVALID_OPERATION;

	int list_size = sll_get_length(sll);
	
	if (list_size < 0)
		return DS_ERR_OPERATION_FAILED;

	(*arr) = getCArray(list_size);

	if (!(*arr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < list_size; i++) {
		if (head == NULL)
			return DS_ERR_ITER;
		(*arr)->array[i] = head->data;
		head = head->next;
	}

	if ((*arr)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status convert_sll_to_darray(SinglyLinkedList *sll, DArray **darr)
{
	if (!sll)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *head = sll->head;
	
	if (head == NULL)
		return DS_ERR_INVALID_OPERATION;

	int list_size = getListSizeSLL(&sll);

	if (list_size < 0)
		return DS_ERR_OPERATION_FAILED;

	(*darr) = getDArray(list_size);

	if (!(*darr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < list_size; i++) {
		if (head == NULL)
			return DS_ERR_ITER;
		pushValueDArray(darr, head->data);
		head = head->next;
	}

	if ((*darr)->size != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            DAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_darray_to_sll(DArray *darr, SinglyLinkedList **sll)
{
	if (!darr)
		return DS_ERR_NULL_POINTER;

	if (darr->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	// TODO implement functions with status errors
	initListSLL(sll);

	if (!(*sll))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < darr->size; i++) {
		insertTailSLL(sll, darr->array[i]);
	}

	if ((*sll)->length != darr->size)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            AAR -> X                                             |
// +-------------------------------------------------------------------------------------------------+

Status convert_array_to_darray(Array *arr, DArray **darr)
{
	if (!arr)
		return DS_ERR_NULL_POINTER;

	if (arr->size <= 0)
		return DS_ERR_INVALID_OPERATION;

	// TODO implement functions with status errors
	initDArray(darr, arr->size);

	if (!(*darr))
		return DS_ERR_ALLOC;

	int i;
	for (i = 0; i < arr->size; i++) {
		pushValueDArray(darr, arr->array[i]);
	}

	if ((*darr)->size != arr->size)
		return DS_ERR_OPERATION_FAILED;

	return DS_OK;
}
*/