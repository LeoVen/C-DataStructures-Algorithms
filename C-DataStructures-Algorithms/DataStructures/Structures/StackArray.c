/**
* @file StackArray.c
*
* @author Leonardo Vencovsky (https://github.com/LeoVen)
* @date 04/08/2018
*
* @brief Source file for @c StackArray implementations in C
*
*/

#include "StackArray.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status sta_init(StackArray **sta)
{
	(*sta) = malloc(sizeof(StackArray));

	if (!(*sta))
		return DS_ERR_ALLOC;

	(*sta)->buffer = malloc(sizeof(int) * _STACK_ARRAY_INIT_SIZE);

	if (!((*sta)->buffer))
		return DS_ERR_ALLOC;

	(*sta)->capacity = _STACK_ARRAY_INIT_SIZE;
	(*sta)->growth_rate = _STACK_ARRAY_GROW_RATE;

	(*sta)->height = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status sta_get_height(StackArray *sta, size_t *result)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	*result = sta->height;

	return DS_OK;
}

size_t sta_height(StackArray *sta)
{
	return sta->height;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status sta_push(StackArray *sta, int value)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	if (sta_is_full(sta))
	{
		Status st = sta_realloc(sta);

		if (st != DS_OK)
			return st;
	}

	sta->buffer[sta->height] = value;

	(sta->height)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status sta_slice(StackArray *sta)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	if (sta_is_empty(sta))
		return DS_ERR_INVALID_OPERATION;

	(sta->height)--;

	return DS_OK;
}

Status sta_pop(StackArray *sta, int *value)
{
	*value = 0;

	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	if (sta_is_empty(sta))
		return DS_ERR_INVALID_OPERATION;

	(sta->height)--;

	*value = sta->buffer[sta->height];

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status sta_display(StackArray *sta)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\nStackArray\n");

	if (sta_is_empty(sta))
	{
		printf("[ empty ]");

		return DS_OK;
	}

	size_t i;
	for (i = 0; i < sta->height; i++)
	{
		printf("\n|%10d |", sta->buffer[i]);
	}

	printf("\n");

	return DS_OK;
}

Status sta_display_raw(StackArray *sta)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (sta_is_empty(sta))
		return DS_OK;

	size_t i;
	for (i = 0; i < sta->height; i++)
		printf(" %d", sta->buffer[i]);

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status sta_delete(StackArray **sta)
{
	if ((*sta) == NULL)
		return DS_ERR_INVALID_OPERATION;

	free((*sta)->buffer);

	free(*sta);

	*sta = NULL;

	return DS_OK;
}

Status sta_erase(StackArray **sta)
{
	if ((*sta) == NULL)
		return DS_ERR_INVALID_OPERATION;

	Status st = sta_delete(sta);

	if (st != DS_OK)
		return st;

	st = sta_init(sta);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status sta_look(StackArray *sta, int *result)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	if (sta_is_empty(sta))
		return DS_ERR_INVALID_OPERATION;

	*result = sta->buffer[sta->height - 1];

	return DS_OK;
}

int sta_peek(StackArray *sta)
{
	return sta->buffer[sta->height - 1];
}

bool sta_is_empty(StackArray *sta)
{
	return (sta->height == 0);
}

bool sta_is_full(StackArray *sta)
{
	return (sta->height == sta->capacity);
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

//Status sta_copy(StackArray *sta, StackArray **result)

// +-------------------------------------------------------------------------------------------------+
// |                                            Buffer                                               |
// +-------------------------------------------------------------------------------------------------+

Status sta_realloc(StackArray *sta)
{
	if (sta == NULL)
		return DS_ERR_NULL_POINTER;

	sta->capacity *= sta->growth_rate;

	int *new_buffer = realloc(sta->buffer, sizeof(int) * sta->capacity);

	if (!new_buffer)
	{
		sta->capacity /= sta->growth_rate;

		return DS_ERR_ALLOC;
	}

	sta->buffer = new_buffer;

	return DS_OK;
}
