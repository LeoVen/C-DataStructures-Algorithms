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

Status prq_init_queue(PriorityQueue **prq)
{
	(*prq) = malloc(sizeof(PriorityQueue));

	if (!(*prq))
		return DS_ERR_ALLOC;

	(*prq)->front = NULL;
	(*prq)->rear = NULL;

	(*prq)->length = 0;

	return DS_OK;
}

Status prq_init_node(PriorityQueueNode **node)
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

PriorityQueue * prq_get_queue()
{
	PriorityQueue *prq = malloc(sizeof(PriorityQueue));

	prq->front = NULL;
	prq->rear = NULL;

	prq->length = 0;

	return prq;
}

PriorityQueueNode * prq_get_node(int value, int priority)
{
	PriorityQueueNode *node = malloc(sizeof(PriorityQueueNode));

	node->before = NULL;

	node->data = value;
	node->priority = priority;

	return node;
}

Status prq_make_node(PriorityQueueNode **node, int value, int priority)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->before = NULL;

	(*node)->data = value;
	(*node)->priority = priority;

	return DS_OK;
}

Status prq_get_length(PriorityQueue *prq, size_t *result)
{
	*result = 0;

	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	while (scan != NULL)
	{
		(*result)++;

		scan = scan->before;
	}

	if ((*result) != prq->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status prq_enqueue(PriorityQueue *prq, int value, int priority)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *node;

	prq_make_node(&node, value, priority);

	if (!node)
		return DS_ERR_ALLOC;

	if (prq_is_empty(prq)) {

		prq->rear = node;
		prq->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = prq->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = prq->front;

			prq->front = node;

		}
		else {

			node->before = curr;

			prev->before = node;

		}

	}

	(prq->length)++;

	return DS_OK;
}

Status prq_enqueue_node(PriorityQueue *prq, PriorityQueueNode *node)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	node->before = NULL;

	if (prq_is_empty(prq)) {

		prq->rear = node;
		prq->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = prq->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = prq->front;
			prq->front = node;

		}
		else {

			node->before = curr;
			prev->before = node;

		}

	}

	(prq->length)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status prq_dequeue(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *node = prq->front;

	prq->front = prq->front->before;

	free(node);

	(prq->length)--;

	if (prq->length == 0)
		prq->rear = NULL;

	return DS_OK;
}

Status prq_dequeue_node(PriorityQueue *prq, PriorityQueueNode **result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	(*result) = prq->front;

	prq->front = prq->front->before;

	(*result)->before = NULL;

	(prq->length)--;

	if (prq->length == 0)
		prq->rear = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status prq_display(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq)) {

		printf("\nPriority Queue\n[ empty ]\n");
		
		return DS_OK;
	}

	PriorityQueueNode *scan = prq->front;

	printf("\nPriority Queue\nfront <-");

	while (scan != NULL)
	{
		printf(" %d <-", scan->data);
		scan = scan->before;
	}

	printf(" rear\n");

	return DS_OK;
}

Status prq_display_raw(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

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

Status prq_delete_node(PriorityQueueNode **node)
{
	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status prq_delete_queue(PriorityQueue **prq)
{
	if ((*prq) == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *prev = (*prq)->front;

	while ((*prq)->front != NULL)
	{
		(*prq)->front = (*prq)->front->before;
		
		free(prev);

		prev = (*prq)->front;
	}

	free((*prq));

	(*prq) = NULL;

	return DS_OK;
}

Status prq_erase_queue(PriorityQueue **prq)
{
	if ((*prq) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = sll_delete_list(prq);

	if (st != DS_OK)
		return st;

	st = prq_init_queue(prq);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status prq_peek_front(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	*result = prq->front->data;

	return DS_OK;
}

Status prq_peek_rear(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	*result = prq->rear->data;

	return DS_OK;
}

bool prq_is_empty(PriorityQueue *prq)
{
	return (prq->length == 0 || prq->rear == NULL);
}

Status prq_priority_highest(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority > *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}

Status prq_priority_lowest(PriorityQueue *prq, int *result)
{
	*result = 0;

	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority < *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}