/**
 * @file CircularBuffer.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c CircularBuffer implementations in C
 *
 */

#include "..\Headers\CircularBuffer.h"

Status cbf_init(CircularBuffer **cbf, size_t length)
{
	(*cbf) = malloc(sizeof(CircularBuffer));

	if (!(*cbf))
		return DS_ERR_ALLOC;

	(*cbf)->buffer = malloc(length * sizeof(int));
	
	if (!((*cbf)->buffer))
		return DS_ERR_ALLOC;

	(*cbf)->length = length;

	(*cbf)->start = 0;
	(*cbf)->end = 0;

	return DS_OK;
}

CircularBuffer * cbf_get(size_t length)
{
	CircularBuffer *cbf = malloc(sizeof(CircularBuffer));

	cbf->buffer = malloc(length * sizeof(int));

	cbf->length = length;

	cbf->start = 0;
	cbf->end = 0;

	return cbf;
}

//Status cbf_get_length(CircularBuffer *cbf, size_t *result)

//Status cbf_add(CircularBuffer *cbf, int value)

//Status cbf_remove(CircularBuffer *cbf, int *value)

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
	if ((*cbf) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t len = (*cbf)->length;

	Status st = cbf_delete(cbf);

	if (st != DS_OK)
		return st;

	st = cbf_init(cbf, len);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

/**
 * This allows the buffer to be circular. The insertion point wraps around
 * its end and check if the first position is available. It can also be
 * used during iteration to change the insertion point.
 *
 */
//Status cbf_wrap(CircularBuffer **cbf)

//bool cbf_is_empty(CircularBuffer *cbf)
//bool cbf_is_full(CircularBuffer *cbf)