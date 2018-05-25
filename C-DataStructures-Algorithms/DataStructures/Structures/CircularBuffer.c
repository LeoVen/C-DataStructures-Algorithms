/**
 * @file CircularBuffer.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c CircularBuffer implementations in C
 *
 */

#include "CircularBuffer.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status cbf_init(CircularBuffer **cbf, size_t length)
{
	(*cbf) = malloc(sizeof(CircularBuffer));

	if (!(*cbf))
		return DS_ERR_ALLOC;

	(*cbf)->buffer = calloc(length, sizeof(int));

	if (!((*cbf)->buffer))
		return DS_ERR_ALLOC;

	(*cbf)->max_length = length;
	(*cbf)->length = 0;

	(*cbf)->is_empty = true;

	(*cbf)->start = 0;
	(*cbf)->end = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

CircularBuffer * cbf_get(size_t length)
{
	CircularBuffer *cbf = malloc(sizeof(CircularBuffer));

	cbf->buffer = calloc(length, sizeof(int));

	cbf->max_length = length;
	cbf->length = 0;

	cbf->is_empty = true;

	cbf->start = 0;
	cbf->end = 0;

	return cbf;
}

Status cbf_get_length(CircularBuffer *cbf, size_t *result)
{
	*result = 0;

	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	*result = cbf->length;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status cbf_add(CircularBuffer *cbf, int value)
{
	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	if (cbf_is_full(cbf))
		return DS_ERR_FULL;

	cbf->buffer[cbf->start] = value;

	(cbf->start)++;
	cbf_wrap(cbf);

	(cbf->length)++;

	cbf->is_empty = false;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status cbf_remove(CircularBuffer *cbf, int *value)
{
	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	if (cbf_is_empty(cbf))
		return DS_ERR_INVALID_OPERATION;

	*value = cbf->buffer[cbf->end];

	cbf->buffer[cbf->end] = 0;

	(cbf->end)++;
	cbf_wrap(cbf);

	(cbf->length)--;

	if (cbf->start == cbf->end)
		cbf->is_empty = true;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status cbf_display(CircularBuffer *cbf)
{
	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\nCircular Buffer\n[");

	size_t i;
	for (i = 0; i < cbf->max_length; i++)
		printf(" [%d]", cbf->buffer[i]);

	printf(" ]\n");

	return DS_OK;
}

Status cbf_display_raw(CircularBuffer *cbf)
{
	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	size_t i;
	for (i = 0; i < cbf->max_length; i++)
		printf(" %d", cbf->buffer[i]);

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status cbf_delete(CircularBuffer **cbf)
{
	if ((*cbf) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*cbf)->buffer);
	free(*cbf);

	*cbf = NULL;

	return DS_OK;
}

Status cbf_erase(CircularBuffer **cbf)
{
	if (cbf == NULL)
		return DS_ERR_NULL_POINTER;

	size_t len = (*cbf)->max_length;

	Status st = cbf_delete(cbf);

	if (st != DS_OK)
		return st;

	st = cbf_init(cbf, len);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool cbf_is_empty(CircularBuffer *cbf)
{
	return (cbf->start == cbf->end && cbf->is_empty);
}

bool cbf_is_full(CircularBuffer *cbf)
{
	return (cbf->start == cbf->end && !(cbf->is_empty));
}

// +-------------------------------------------------------------------------------------------------+
// |                                          Functionality                                          |
// +-------------------------------------------------------------------------------------------------+

/**
 * This allows the buffer to be circular. The insertion point wraps around its
 * end and the following insertion or removal call can be calculated repeatedly
 *
 */
Status cbf_wrap(CircularBuffer *cbf)
{
	if (cbf->start >= cbf->max_length)
		cbf->start = 0;

	if (cbf->end >= cbf->max_length)
		cbf->end = 0;
	
	return DS_OK;
}
