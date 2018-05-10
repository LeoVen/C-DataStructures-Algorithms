/**
 * @file PriorityQueue.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 08/05/2018
 *
 * @brief Header file for @c PriorityQueue implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Core.h"

	/**
	 * A @c PriorityQueueNode is what a @c PriorityQueue is composed of. It has an
	 * integer as its data, a priority integer that decides where that node will be
	 * placed and one pointer to the @c PriorityQueueNode before it or simply NULL
	 * when it is the last inserted  element in the @c PriorityQueue.
	 *
	 */
	typedef struct PriorityQueueNode {
		int data;                           /*!< Node's data */
		int priority;                       /*!< Node's priority */
		struct PriorityQueueNode *before;   /*!< Pointer to the previous node in the @c PriorityQueue */
	} PriorityQueueNode;

	/**
	 * A @c PriorityQueue is much like a @c Queue but with a priority indicator
	 * at each node. This priority decides if a node will be inserted after
	 * certain elements that have a lower priority allowing this newly inserted
	 * Node to be removed earlier.
	 *
	 * @b Advantages over @c Queue
	 * - Each Node has a priority value. This priority can be very useful when
	 * that node must be removed of the Queue sooner.
	 *
	 * @b Drawbacks
	 * - None
	 *
	 * @b Functions
	 *
	 * @c PriorityQueue.c
	 *
	 */
	typedef struct PriorityQueue {
		size_t length;                      /*!< Total @c Queue length */
		struct PriorityQueueNode *front;    /*!< Where @c PriorityQueueNode are removed */
		struct PriorityQueueNode *rear;     /*!< Where @c PriorityQueueNode are inserted */
	} PriorityQueue;

	Status prq_init_queue(PriorityQueue **prq);
	Status prq_init_node(PriorityQueueNode **node);

	PriorityQueue * prq_get_queue();
	PriorityQueueNode * prq_get_node(int value, int priority);

	Status prq_make_node(PriorityQueueNode **node, int value, int priority);

	Status prq_get_length(PriorityQueue *prq, size_t *result);

	Status prq_enqueue(PriorityQueue *prq, int value, int priority);
	Status prq_enqueue_node(PriorityQueue *prq, PriorityQueueNode *node);

	Status prq_dequeue(PriorityQueue *prq);
	Status prq_dequeue_node(PriorityQueue *prq, PriorityQueueNode **result);

	Status prq_display(PriorityQueue *prq);
	Status prq_display_raw(PriorityQueue *prq);

	Status prq_delete_node(PriorityQueueNode **node);
	Status prq_delete_queue(PriorityQueue **prq); // Erases and sets to NULL
	Status prq_erase_queue(PriorityQueue **prq);  // Erases and inits

	Status prq_peek_front(PriorityQueue *prq, int *result);
	Status prq_peek_rear(PriorityQueue *prq, int *result);

	bool prq_is_empty(PriorityQueue *prq);

	Status prq_priority_highest(PriorityQueue *prq, int *result);
	Status prq_priority_lowest(PriorityQueue *prq, int *result);


#ifdef __cplusplus
}
#endif