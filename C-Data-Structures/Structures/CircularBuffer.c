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

//CircularBuffer * cbf_get()

//Status cbf_get_length(CircularBuffer *cbf, size_t *result)

//Status cbf_add(CircularBuffer *cbf, int value)

//Status cbf_remove(CircularBuffer *cbf, int *value)

//Status cbf_delete(CircularBuffer **cbf)
//Status cbf_erase(CircularBuffer **cbf)

/**
 * This allows the buffer to be circular. The insertion point wraps around
 * its end and check if the first position is available. It can also be
 * used during iteration to change the insertion point.
 *
 */
//Status cbf_wrap(CircularBuffer **cbf)

//bool cbf_is_empty(CircularBuffer *cbf)
//bool cbf_is_full(CircularBuffer *cbf)