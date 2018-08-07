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

Status dar_init(DynamicArray **dar)
{
	(*dar) = malloc(sizeof(DynamicArray));

	if (!(*dar))
		return DS_ERR_ALLOC;

	(*dar)->buffer = calloc(_DYNAMIC_ARRAY_INIT_SIZE, sizeof(int));

	if (!((*dar)->buffer))
		return DS_ERR_ALLOC;

	(*dar)->capacity = _DYNAMIC_ARRAY_INIT_SIZE;
	(*dar)->growth_rate = _DYNAMIC_ARRAY_GROW_RATE;

	(*dar)->size = 0;

	return DS_OK;
}

Status dar_make(DynamicArray **dar, int *array, size_t arr_size)
{
	Status st = dar_init(dar);

	if (st != DS_OK)
		return st;

	size_t i;
	for (i = 0; i < arr_size; i++)
	{
		st = dar_insert_back((*dar), array[i]);

		if (st != DS_OK)
			return st;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status dar_insert_front(DynamicArray *dar, int value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_full(dar))
	{
		Status st = dar_realloc(dar);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = dar->size; i > 0; i--)
	{
		dar->buffer[i] = dar->buffer[i - 1];
	}

	dar->buffer[0] = value;

	(dar->size)++;

	return DS_OK;
}

Status dar_insert_at(DynamicArray *dar, int value, size_t index)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (index > dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = dar_insert_front(dar, value);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size)
	{
		st = dar_insert_back(dar, value);

		if (st != DS_OK)
			return st;
	}
	else
	{
		if (dar_is_full(dar))
		{
			st = dar_realloc(dar);

			if (st != DS_OK)
				return st;
		}

		size_t i;
		for (i = dar->size; i > index; i--)
		{
			dar->buffer[i] = dar->buffer[i - 1];
		}

		dar->buffer[index] = value;

		(dar->size)++;
	}

	return DS_OK;
}

Status dar_insert_back(DynamicArray *dar, int value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_full(dar))
	{
		Status st = dar_realloc(dar);

		if (st != DS_OK)
			return st;
	}

	dar->buffer[dar->size] = value;

	(dar->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status dar_remove_front(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		dar->buffer[i] = dar->buffer[i + 1];
	}

	(dar->size)--;

	return DS_OK;
}

Status dar_remove_at(DynamicArray *dar, size_t index)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = dar_remove_front(dar);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size - 1)
	{
		st = dar_remove_back(dar);

		if (st != DS_OK)
			return st;
	}
	else
	{
		size_t i;
		for (i = index; i < dar->size; i++)
		{
			dar->buffer[i] = dar->buffer[i + 1];
		}

		(dar->size)--;
	}

	return DS_OK;
}

Status dar_remove_back(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	(dar->size)--;

	return DS_OK;
}

//Status dar_remove_keys(DynamicArray *dar, int value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status dar_display(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;


	if (dar->size == 0) {

		printf("\n[ Empty ] \n");

		return DS_OK;
	}

	printf("\nDynamic Array\n[ ");

	size_t i;
	for (i = 0; i < dar->size - 1; i++) {

		printf("%d, ", dar->buffer[i]);
	}

	printf("%d", dar->buffer[dar->size - 1]);

	printf(" ]\n");

	return DS_OK;
}

Status dar_display_raw(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (dar_is_empty(dar))
		return DS_OK;

	size_t i;
	for (i = 0; i < dar->size; i++) {

		printf("%d ", dar->buffer[i]);
	}

	printf("\n");
	
	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status dar_delete(DynamicArray **dar)
{
	if (*dar == NULL)
		return DS_ERR_NULL_POINTER;

	free((*dar)->buffer);
	free((*dar));

	(*dar) = NULL;

	return DS_OK;
}

Status dar_erase(DynamicArray **dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = dar_delete(dar);

	if (st != DS_OK)
		return st;

	st = dar_init(dar);

	if (st != DS_OK)
		return st;

	return DS_OK;
}


// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status dar_get(DynamicArray *dar, size_t index, int *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	*result = dar->buffer[index];

	return DS_OK;
}

size_t dar_cap(DynamicArray *dar)
{
	return dar->capacity;
}

size_t dar_size(DynamicArray *dar)
{
	return dar->size;
}

bool dar_is_empty(DynamicArray *dar)
{
	return dar->size == 0;
}

bool dar_is_full(DynamicArray *dar)
{
	return dar->size == dar->capacity;
}

Status dar_find_max(DynamicArray *dar, int *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[0];

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (dar->buffer[i] > *result)
			*result = dar->buffer[i];
	}

	return DS_OK;
}

Status dar_find_min(DynamicArray *dar, int *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[0];

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (dar->buffer[i] < *result)
			*result = dar->buffer[i];
	}

	return DS_OK;
}

Status dar_find_max_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (dar->buffer[i] > dar->buffer[(*result)])
			*result = i;
	}

	return DS_OK;
}

Status dar_find_min_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (dar->buffer[i] < dar->buffer[(*result)])
			*result = i;
	}

	return DS_OK;
}

//Status dar_frequency(DynamicArray *dar, int value, size_t *frequency)
//Status dar_contains(DynamicArray *dar, int value, bool *result)

Status dar_find_occurrance_first(DynamicArray *dar, int value, size_t *position);
Status dar_find_occurrance_last(DynamicArray *dar, int value, size_t *position);

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

//Status dar_copy(DynamicArray *dar, DynamicArray **result)

//Status dar_merge_sorted(DynamicArray *dar1, DynamicArray *dar2, DynamicArray **result);

//Status dar_append(DynamicArray *dar1, DynamicArray *dar2)
//Status dar_prepend(DynamicArray *dar1, DynamicArray *dar2)

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

//Status dar_is_sorted(DynamicArray *dar, bool *result)
//Status dar_reverse(DynamicArray *dar)
//Status dar_sort_bubble(DynamicArray *dar)
//Status dar_sort_selection(DynamicArray *dar)
//Status dar_sort_insertion(DynamicArray *dar)


// +-------------------------------------------------------------------------------------------------+
// |                                            Buffer                                               |
// +-------------------------------------------------------------------------------------------------+

Status dar_realloc(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	dar->capacity *= dar->growth_rate;

	dar->buffer = realloc(dar->buffer, sizeof(int) * dar->capacity);

	if (!(dar->buffer))
		return DS_ERR_ALLOC;

	return DS_OK;
}
