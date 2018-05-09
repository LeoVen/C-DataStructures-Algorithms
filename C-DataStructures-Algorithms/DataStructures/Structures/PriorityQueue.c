/**
 * @file PriorityQueue.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 08/05/2018
 *
 * @brief Source file for @c PriorityQueue implementations in C
 *
 */

#include "..\Headers\PriorityQueue.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status pqe_init_queue(PriorityQueue **pqe)
{
	(*pqe) = malloc(sizeof(PriorityQueue));

	if (!(*pqe))
		return DS_ERR_ALLOC;

	(*pqe)->front = NULL;
	(*pqe)->rear = NULL;

	(*pqe)->length = 0;

	return DS_OK;
}

Status pqe_init_node(PriorityQueueNode **node)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = NULL;
	(*node)->priority = NULL;
	
	(*node)->before = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

PriorityQueue * pqe_get_queue()
{
	PriorityQueue *pqe = malloc(sizeof(PriorityQueue));

	pqe->front = NULL;
	pqe->rear = NULL;

	pqe->length = 0;

	return pqe;
}

PriorityQueueNode * pqe_get_node(int value, int priority)
{
	PriorityQueueNode *node = malloc(sizeof(PriorityQueueNode));

	node->before = NULL;

	node->data = value;
	node->priority = priority;

	return node;
}

Status pqe_make_node(PriorityQueueNode **node, int value, int priority)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->before = NULL;

	(*node)->data = value;
	(*node)->priority = priority;

	return DS_OK;
}

Status pqe_get_length(PriorityQueue *pqe, size_t *result)
{
	*result = 0;

	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = pqe->front;

	while (scan != NULL)
	{
		(*result)++;

		scan = scan->before;
	}

	if ((*result) != pqe->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

//Status pqe_enqueue(PriorityQueue *pqe, int value)
//Status pqe_enqueue_node(PriorityQueue *pqe, PriorityQueueNode *node)

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status pqe_dequeue(PriorityQueue *pqe)
//Status pqe_dequeue_node(PriorityQueue *pqe, PriorityQueueNode **result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

//Status pqe_display(PriorityQueue *pqe)
//Status pqe_display_raw(PriorityQueue *pqe)

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status pqe_delete_node(PriorityQueueNode **node)
//Status pqe_delete_queue(PriorityQueue **pqe)
//Status pqe_erase_queue(PriorityQueue **pqe)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status pqe_peek_front(PriorityQueue *pqe, int *result)
//Status pqe_peek_rear(PriorityQueue *pqe, int *result)

bool pqe_is_empty(PriorityQueue *pqe)
{
	return (pqe->length == 0 || pqe->rear == NULL);
}

//Status pqe_priority_highest(PriorityQueue *pqe, int *result)
//Status pqe_priority_lowest(PriorityQueue *pqe, int *result)