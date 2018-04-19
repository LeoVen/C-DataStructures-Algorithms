/**
 * @file Queue.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c StaticQueue implementations in C
 *
 */

#include "..\Headers\StaticQueue.h"

Status que_stc_init(StaticQueue **squ, size_t length)
{
	(*squ) = malloc(sizeof(StaticQueue));

	if (!(*squ))
		return DS_ERR_ALLOC;

	(*squ)->buffer = malloc(length * sizeof(int));
	
	if (!((*squ)->buffer))
		return DS_ERR_ALLOC;

	(*squ)->length = length;

	(*squ)->front = 0;
	(*squ)->rear = 0;

	return DS_OK;
}

//Queue * que_stc_get()

//Status que_stc_get_length(StaticQueue *squ, size_t *result)

//Status que_stc_enqueue(Queue *squ, int value)

//Status que_stc_dequeue(Queue *squ, int *value)

//Status que_stc_delete(Queue **squ)
//Status que_stc_erase(Queue **squ)

/*
 * This allows the queue to be circular. The insertion point wraps around
 * its end and check if the first position is available. It can also be
 * used during iteration to change the insertion point.
 *
 */
//Status que_stc_check_circularity(StaticQueue **squ)
