/**
 * @file DynamicArray.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Source file for @c DynamicArray implementations in C
 *
 * Dynamic Array grows and shrinks as you add and remove values
 *
 */

#include "DynamicArray.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status darr_init(DynamicArray **darr, size_t size)
{
	(*darr) = malloc(sizeof(DynamicArray));

	if (!(*darr))
		return DS_ERR_ALLOC;

	(*darr)->buffer = calloc(size, sizeof(int));

	if (!(*darr)->buffer)
		return DS_ERR_ALLOC;

	(*darr)->size = 0;
	(*darr)->threshold = false;
	(*darr)->maxSize = size;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Getters                                             |
// +-------------------------------------------------------------------------------------------------+

DynamicArray * darr_get(size_t size)
{
	if (size < 0) {
		printf("\nFATAL ERROR\n");
		return NULL;
	}

	DynamicArray *newArr = malloc(sizeof(DynamicArray));

	newArr->buffer = calloc(size, sizeof(int));

	newArr->size = 0;
	newArr->threshold = false;
	newArr->maxSize = size;

	return newArr;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status darr_push(DynamicArray **darr, int value)
{
	Status st = darr_resize(darr);

	if (st != DS_OK)
		return st;

	(*darr)->buffer[(*darr)->size] = value;
	((*darr)->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status darr_pop(DynamicArray **darr)
{
	Status st = darr_resize(darr);

	if (st != DS_OK)
		return st;

	(*darr)->buffer[(*darr)->size] = 0;
	((*darr)->size)--;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status darr_display(DynamicArray *darr)
{
	if (darr == NULL)
		return DS_ERR_NULL_POINTER;

	int i;

	if (darr->size == 0) {

		printf("\n[ Empty ] \n");

		return DS_OK;
	}

	printf("\nDynamic Array\n[ ");

	for (i = 0; i < darr->size; i++) {

		printf("%d, ", darr->buffer[i]);
	}

	printf("nil ]\n");

	return DS_OK;
}

Status darr_display_raw(DynamicArray *darr)
{
	if (darr == NULL)
		return DS_ERR_NULL_POINTER;

	int i;

	if (darr->size == 0) {

		printf("\n[ Empty ] \n");
		
		return DS_OK;
	}

	printf("\n");

	for (i = 0; i < darr->size; i++) {

		printf("%d ", darr->buffer[i]);
	}

	printf("\n");
	
	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status darr_erase(DynamicArray *darr)
{
	if (darr == NULL)
		return DS_ERR_NULL_POINTER;

	int i;

	for (i = 0; i < darr->size; i++) {

		darr->buffer[i] = 0;
	}

	return DS_OK;
}

Status darr_delete(DynamicArray **darr)
{
	if (*darr == NULL)
		return DS_ERR_NULL_POINTER;

	free((*darr)->buffer);
	free((*darr));

	(*darr) = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Dynamic                                             |
// +-------------------------------------------------------------------------------------------------+

Status darr_resize(DynamicArray **darr)
{
	if ((*darr) == NULL)
		return DS_ERR_NULL_POINTER;

	if ((*darr)->size > (*darr)->maxSize / 2)
		(*darr)->threshold = true;

	if ((*darr)->size >= (*darr)->maxSize - 1)
		return darr_grow(darr);

	else if ((*darr)->threshold && (*darr)->size < (*darr)->maxSize / 2)
		return darr_shrink(darr);

	return DS_OK;
}

Status darr_shrink(DynamicArray **darr)
{
	if ((*darr) == NULL)
		return DS_ERR_NULL_POINTER;

	DynamicArray *nArray;

	Status st = darr_init(&nArray, (*darr)->maxSize / 2 + 1);

	if (st != DS_OK)
		return st;
	
	DynamicArray *kill = (*darr);

	int i;
	for (i = 0; i < (*darr)->size; i++) {

		nArray->buffer[i] = (*darr)->buffer[i];

	}

	nArray->size = (*darr)->size;
	nArray->threshold = false;
	
	(*darr) = nArray;

	st = darr_delete(&kill);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status darr_grow(DynamicArray **darr)
{
	if (*darr == NULL)
		return DS_ERR_NULL_POINTER;

	DynamicArray *nArray;

	Status st = darr_init(&nArray, (*darr)->maxSize * 2);

	if (st != DS_OK)
		return st;

	DynamicArray *kill = (*darr);

	int i;
	for (i = 0; i < (*darr)->size; i++) {

		nArray->buffer[i] = (*darr)->buffer[i];

	}

	nArray->size = (*darr)->size;
	nArray->threshold = false;

	(*darr) = nArray;

	st = darr_delete(&kill);

	if (st != DS_OK)
		return st;

	return DS_OK;
}