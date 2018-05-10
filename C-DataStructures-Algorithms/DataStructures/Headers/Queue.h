/**
 * @file Queue.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Header file for @c Queue implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Core.h"

	/**
	 * A @c QueueNode is what a @c Queue is composed of. It has an integer as
	 * its data and only one pointer to the @c QueueNode before it or simply
	 * NULL when it is the last inserted element in the @c Queue.
	 *
	 */
	typedef struct QueueNode {
		int data;                           /*!< Node's data */
		struct QueueNode *before;           /*!< Pointer to the previous node in the @c Queue */
	} QueueNode;

	/**
	 * A @c Queue is much like a @c SinglyLinkedList but with FIFO operations,
	 * that is, First-in First-out, so the first item added is the first one to
	 * be removed. This way, two pointer are needed. One to the beggining of
	 * the @c Queue and another to the end of it.
	 *
	 * @b Advantages over @c SinglyLinkedList
	 * - Its functionality is restricted to attend only FIFO operations
	 *
	 * @b Drawbacks
	 * - Restricted operations may cause some functions to be not available
	 *
	 * @b Functions
	 *
	 * @c Queue.c
	 *
	 */
	typedef struct Queue {
		size_t length;                      /*!< Total @c Queue length */
		struct QueueNode *front;            /*!< Where @c QueueNode are removed */
		struct QueueNode *rear;             /*!< Where @c QueueNode are inserted */
	} Queue;

	Status que_init_queue(Queue **que);
	Status que_init_node(QueueNode **node);

	Queue * que_get_queue();
	QueueNode * que_get_node(int value);

	Status que_make_node(QueueNode **node, int value);

	Status que_get_length(Queue *que, size_t *result);

	Status que_enqueue(Queue *que, int value);
	Status que_enqueue_node(Queue *que, QueueNode *node);
   
	Status que_dequeue(Queue *que);
	Status que_dequeue_node(Queue *que, QueueNode **result);

	Status que_display(Queue *que);
	Status que_display_raw(Queue *que);

	Status que_delete_node(QueueNode **node);
	Status que_delete_queue(Queue **que); // Erases and sets to NULL
	Status que_erase_queue(Queue **que);  // Erases and inits

	Status que_peek_front(Queue *que, int *result);
	Status que_peek_rear(Queue *que, int *result);

	bool que_is_empty(Queue *que);

#ifdef __cplusplus
}
#endif;
