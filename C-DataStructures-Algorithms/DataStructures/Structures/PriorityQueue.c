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

Status pqe_enqueue(PriorityQueue *pqe, int value, int priority)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *node;

	pqe_make_node(&node, value, priority);

	if (!node)
		return DS_ERR_ALLOC;

	if (pqe->rear == NULL) {

		pqe->rear = node;
		pqe->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = pqe->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = pqe->front;

			pqe->front = node;

		}
		else {

			node->before = curr;

			prev->before = node;

		}

	}

	(pqe->length)++;

	return DS_OK;
}

Status pqe_enqueue_node(PriorityQueue *pqe, PriorityQueueNode *node)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	node->before = NULL;

	if (pqe->rear == NULL) {

		pqe->rear = node;
		pqe->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = pqe->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = pqe->front;
			pqe->front = node;

		}
		else {

			node->before = curr;
			prev->before = node;

		}

	}

	(pqe->length)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status pqe_dequeue(PriorityQueue *pqe)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *node = pqe->front;

	pqe->front = pqe->front->before;

	free(node);

	(pqe->length)--;

	if (pqe->length == 0)
		pqe->rear = NULL;

	return DS_OK;
}

Status pqe_dequeue_node(PriorityQueue *pqe, PriorityQueueNode **result)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *node = pqe->front;

	pqe->front = pqe->front->before;

	(*result) = node;

	(pqe->length)--;

	if (pqe->length == 0)
		pqe->rear = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status pqe_display(PriorityQueue *pqe)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe)) {

		printf("\nPriority Queue\n[ empty ]\n");
		
		return DS_OK;
	}

	PriorityQueueNode *scan = pqe->front;

	printf("\nPriority Queue\nfront <-");

	while (scan != NULL)
	{
		printf(" %d <-", scan->data);
		scan = scan->before;
	}

	printf(" rear\n");

	return DS_OK;
}

Status pqe_display_raw(PriorityQueue *pqe)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = pqe->front;

	printf("\n");

	while (scan != NULL)
	{
		printf("%d ", scan->data);
		scan = scan->before;
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status pqe_delete_node(PriorityQueueNode **node)
{
	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status pqe_delete_queue(PriorityQueue **pqe)
{
	if ((*pqe) == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *prev = (*pqe)->front;

	while ((*pqe)->front != NULL)
	{
		(*pqe)->front = (*pqe)->front->before;
		
		free(prev);

		prev = (*pqe)->front;
	}

	free((*pqe));

	(*pqe) = NULL;

	return DS_OK;
}

Status pqe_erase_queue(PriorityQueue **pqe)
{
	if ((*pqe) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = sll_delete_list(pqe);

	if (st != DS_OK)
		return st;

	st = pqe_init_queue(pqe);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status pqe_peek_front(PriorityQueue *pqe, int *result)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	*result = pqe->front->data;

	return DS_OK;
}

Status pqe_peek_rear(PriorityQueue *pqe, int *result)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	*result = pqe->rear->data;

	return DS_OK;
}

bool pqe_is_empty(PriorityQueue *pqe)
{
	return (pqe->length == 0 || pqe->rear == NULL);
}

Status pqe_priority_highest(PriorityQueue *pqe, int *result)
{
	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = pqe->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority > *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}

Status pqe_priority_lowest(PriorityQueue *pqe, int *result)
{
	*result = 0;

	if (pqe == NULL)
		return DS_ERR_NULL_POINTER;

	if (pqe_is_empty(pqe))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = pqe->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority < *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}