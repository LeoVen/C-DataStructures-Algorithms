/**
 * @file Queue.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Source file for @c Queue implementations in C
 *
 */

#include "..\Headers\Queue.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status que_init_queue(Queue **que)
{
	(*que) = malloc(sizeof(Queue));

	if (!(*que))
		return DS_ERR_ALLOC;

	(*que)->length = 0;

	(*que)->front = NULL;
	(*que)->rear = NULL;

	return DS_OK;
}

Status que_init_node(QueueNode **node)
{
	(*node) = malloc(sizeof(QueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = 0;

	(*node)->before = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Queue * que_get_queue(void)
{
	Queue *que = malloc(sizeof(Queue));

	que->front = NULL;
	que->rear = NULL;

	que->length = 0;

	return que;
}

QueueNode * que_get_node(int value)
{
	QueueNode *node = malloc(sizeof(QueueNode));

	node->before = NULL;

	node->data = value;

	return node;
}

Status que_make_node(QueueNode **node, int value)
{
	(*node) = malloc(sizeof(QueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = value;

	(*node)->before = NULL;

	return DS_OK;
}

Status que_get_length(Queue *que, size_t *result)
{
	*result = 0;

	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	if (que_is_empty(que))
		return DS_ERR_INVALID_OPERATION;

	QueueNode *scan = que->front;

	while (scan != NULL)
	{
		(*result)++;

		scan = scan->before;
	}

	if ((*result) != que->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status que_enqueue(Queue *que, int value)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	QueueNode *node;

	que_make_node(&node, value);

	if (!node)
		return DS_ERR_ALLOC;

	if (que_is_empty(que)) {

		que->rear = node;
		que->front = node;

	}
	else {

		que->rear->before = node;
		que->rear = node;

	}

	(que->length)++;

	return DS_OK;
}

Status que_enqueue_node(Queue *que, QueueNode *node)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	node->before = NULL;

	if (que_is_empty(que)) {

		que->rear = node;
		que->front = node;

	}
	else {

		que->rear->before = node;
		que->rear = node;

	}

	(que->length)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status que_dequeue(Queue *que)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	if (que_is_empty(que))
		return DS_ERR_INVALID_OPERATION;

	QueueNode *node = que->front;

	que->front = que->front->before;

	free(node);

	(que->length)--;

	if (que->length == 0)
		que->rear = NULL;

	return DS_OK;
}

Status que_dequeue_node(Queue *que, QueueNode **result)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	if (que_is_empty(que))
		return DS_ERR_INVALID_OPERATION;

	(*result) = que->front;

	que->front = que->front->before;

	(*result)->before = NULL;

	(que->length)--;

	if (que->length == 0)
		que->rear = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status que_display(Queue *que)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	if (que_is_empty(que)) {

		printf("\nQueue\n[ empty ]\n");
		return DS_OK;

	}

	QueueNode *scan = que->front;

	printf("\nQueue\nfront <-");

	while (scan != NULL)
	{
		printf(" %d <-", scan->data);
		scan = scan->before;
	}

	printf(" rear\n");

	return DS_OK;
}

Status que_display_raw(Queue *que)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	if (que_is_empty(que))
		return DS_ERR_INVALID_OPERATION;

	QueueNode *scan = que->front;

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

Status que_delete_node(QueueNode **node)
{
	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status que_delete_queue(Queue **que)
{
	if ((*que) == NULL)
		return DS_ERR_NULL_POINTER;

	QueueNode *prev = (*que)->front;

	while ((*que)->front != NULL)
	{
		(*que)->front = (*que)->front->before;

		free(prev);

		prev = (*que)->front;
	}

	free((*que));

	(*que) = NULL;

	return DS_OK;
}

Status que_erase_queue(Queue **que)
{
	if ((*que) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = que_delete_queue(que);

	if (st != DS_OK)
		return st;

	st = que_init_queue(que);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status que_peek_front(Queue *que, int *result)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	*result = que->front->data;

	return DS_OK;
}

Status que_peek_rear(Queue *que, int *result)
{
	if (que == NULL)
		return DS_ERR_NULL_POINTER;

	*result = que->rear->data;

	return DS_OK;
}

bool que_is_empty(Queue *que)
{
	return (que->length == 0 || que->rear == NULL);
}