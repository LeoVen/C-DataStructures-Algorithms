/**
 * @file DequeArray.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 08/10/2018
 *
 * @brief Source file for @c DequeArray implementations in C
 *
 */

#include "DequeArray.h"

 // +-------------------------------------------------------------------------------------------------+
 // |                                          Initializers                                           |
 // +-------------------------------------------------------------------------------------------------+

Status dqa_init(DequeArray **dqa)
{
	(*dqa) = malloc(sizeof(DequeArray));

	if (!(*dqa))
		return DS_ERR_ALLOC;

	(*dqa)->buffer = malloc(sizeof(int) * DEQUE_ARRAY_INIT_SIZE);

	if (!((*dqa)->buffer))
		return DS_ERR_ALLOC;

	(*dqa)->capacity = DEQUE_ARRAY_INIT_SIZE;
	(*dqa)->growth_rate = DEQUE_ARRAY_GROW_RATE;

	(*dqa)->size = 0;

	(*dqa)->front = 0;
	(*dqa)->rear = 0;

	return DS_OK;
}

Status dqa_create(DequeArray **dqa, size_t initial_capacity, size_t growth_rate)
{
	if (initial_capacity == 0 || growth_rate <= 100)
		return DS_ERR_INVALID_ARGUMENT;

	(*dqa) = malloc(sizeof(DequeArray));

	if (!(*dqa))
		return DS_ERR_ALLOC;

	(*dqa)->buffer = malloc(sizeof(int) * initial_capacity);

	if (!((*dqa)->buffer))
		return DS_ERR_ALLOC;

	(*dqa)->capacity = initial_capacity;
	(*dqa)->growth_rate = growth_rate;

	(*dqa)->size = 0;

	(*dqa)->front = 0;
	(*dqa)->rear = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status dqa_get_length(DequeArray *dqa, size_t *result)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	*result = dqa->size;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status dqa_enqueue_front(DequeArray *dqa, int value)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_full(dqa))
	{
		Status st = dqa_realloc(dqa);

		if (st != DS_OK)
			return st;
	}

	dqa->front = (dqa->front == 0) ? dqa->capacity - 1 : dqa->front - 1;

	dqa->buffer[dqa->front] = value;

	(dqa->size)++;

	return DS_OK;
}

Status dqa_enqueue_rear(DequeArray *dqa, int value)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_full(dqa))
	{
		Status st = dqa_realloc(dqa);

		if (st != DS_OK)
			return st;
	}

	dqa->buffer[dqa->rear] = value;

	dqa->rear = (dqa->rear == dqa->capacity - 1) ? 0 : dqa->rear + 1;

	(dqa->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status dqa_dequeue_front(DequeArray *dqa, int *value)
{
	*value = 0;

	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_empty(dqa))
		return DS_ERR_INVALID_OPERATION;

	*value = dqa->buffer[dqa->front];

	dqa->front = (dqa->front == dqa->capacity - 1) ? 0 : dqa->front + 1;

	(dqa->size)--;

	return DS_OK;
}

Status dqa_dequeue_rear(DequeArray *dqa, int *value)
{
	*value = 0;

	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_empty(dqa))
		return DS_ERR_INVALID_OPERATION;

	dqa->rear = (dqa->rear == 0) ? dqa->capacity - 1 : dqa->rear - 1;

	*value = dqa->buffer[dqa->rear];

	(dqa->size)--;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status dqa_display(DequeArray *dqa)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_empty(dqa))
	{

		printf("\nDequeArray\n[ empty ]\n");

		return DS_OK;
	}

	printf("\nDequeArray\n[ ");

	size_t i, j;
	for (i = dqa->front, j = 0; j < dqa->size - 1; i = (i + 1) % dqa->capacity, j++)
	{
		printf("%d, ", dqa->buffer[i]);
	}

	size_t real_rear = (dqa->rear == 0) ? dqa->capacity - 1 : dqa->rear - 1;

	printf("%d ]\n", dqa->buffer[real_rear]);

	return DS_OK;
}

Status dqa_display_raw(DequeArray *dqa)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (dqa_is_empty(dqa))
		return DS_OK;

	size_t i, j;
	for (i = dqa->front, j = 0; j < dqa->size; i = (i + 1) % dqa->capacity, j++)
	{
		printf("%d ", dqa->buffer[i]);
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status dqa_delete(DequeArray **dqa)
{
	if ((*dqa) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*dqa)->buffer);

	free(*dqa);

	*dqa = NULL;

	return DS_OK;
}

Status dqa_erase(DequeArray **dqa)
{
	if ((*dqa) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = dqa_delete(dqa);

	if (st != DS_OK)
		return st;

	st = dqa_init(dqa);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status dqa_peek_front(DequeArray *dqa, int *result)
{
	*result = 0;

	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_empty(dqa))
		return DS_ERR_INVALID_OPERATION;

	*result = dqa->buffer[dqa->front];

	return DS_OK;
}

Status dqa_peek_rear(DequeArray *dqa, int *result)
{
	*result = 0;

	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	if (dqa_is_empty(dqa))
		return DS_ERR_INVALID_OPERATION;

	size_t real_rear = (dqa->rear == 0) ? dqa->capacity - 1 : dqa->rear - 1;

	*result = dqa->buffer[real_rear];

	return DS_OK;
}

size_t dqa_size(DequeArray *dqa)
{
	if (dqa == NULL)
		return 0;

	return dqa->size;
}

size_t dqa_capacity(DequeArray *dqa)
{
	if (dqa == NULL)
		return 0;

	return dqa->capacity;
}

bool dqa_is_empty(DequeArray *dqa)
{
	return dqa->size == 0;
}

bool dqa_is_full(DequeArray *dqa)
{
	return dqa->size == dqa->capacity;
}

bool dqa_fits(DequeArray *dqa, size_t size)
{
	return (dqa->size + size) <= dqa->capacity;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

Status dqa_copy(DequeArray *dqa, DequeArray **result)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = dqa_create(result, dqa->capacity, dqa->growth_rate);

	if (st != DS_OK)
		return st;

	if (dqa_is_empty(dqa))
		return DS_OK;

	size_t i;
	for (i = 0; i < dqa->capacity; i++)
	{
		(*result)->buffer[i] = dqa->buffer[i];
	}

	(*result)->front = dqa->front;
	(*result)->rear = dqa->rear;

	(*result)->size = dqa->size;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Buffer                                               |
// +-------------------------------------------------------------------------------------------------+

Status dqa_realloc(DequeArray *dqa)
{
	if (dqa == NULL)
		return DS_ERR_NULL_POINTER;

	size_t old_capacity = dqa->capacity;

	dqa->capacity *= (size_t)((double)(dqa->growth_rate) / 100.0);

	int *new_buffer = realloc(dqa->buffer, sizeof(int) * dqa->capacity);

	if (!new_buffer)
	{
		dqa->capacity = old_capacity;

		return DS_ERR_ALLOC;
	}

	dqa->buffer = new_buffer;

	size_t real_rear = (dqa->rear == 0) ? dqa->capacity - 1 : dqa->rear - 1;

	if (dqa->front > real_rear)
	{
		size_t i, j, distance = old_capacity - dqa->front;
		for (i = old_capacity - 1, j = dqa->capacity - 1; i >= dqa->front; i--, j--)
		{
			dqa->buffer[j] = dqa->buffer[i];
		}

		dqa->front = dqa->capacity - distance;
	}

	return DS_OK;
}
