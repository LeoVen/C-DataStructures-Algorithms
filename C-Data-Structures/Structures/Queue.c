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

	(*node)->data = NULL;

	(*node)->before = NULL;

	return DS_OK;
}

//Queue * que_get_queue()
//QueueNode * que_get_node(int value)

Status que_make_node(QueueNode **node, int value)
{
	(*node) = malloc(sizeof(QueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = value;

	(*node)->before = NULL;

	return DS_OK;
}

//Status que_get_length(Queue *que, size_t *result)

//Status que_enqueue(Queue *sll, int value)
//Status que_enqueue_node(Queue *sll, QueueNode *node)

//Status que_dequeue(Queue *sll)
//Status que_dequeue_node(Queue *sll, QueueNode **node)

//Status que_delete_node(QueueNode **node)
//Status que_delete_queue(Queue **sll)
//Status que_erase_queue(Queue **sll)
