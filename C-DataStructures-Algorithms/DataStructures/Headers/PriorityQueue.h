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
		size_t length;                      /*!< Total Queue length */
		struct PriorityQueueNode *front;    /*!< Where @c PriorityQueueNode are removed */
		struct PriorityQueueNode *rear;     /*!< Where @c PriorityQueueNode are inserted */
	} PriorityQueue;

	Status pqe_init_queue(PriorityQueue **pqe);
	Status pqe_init_node(PriorityQueueNode **node);

	PriorityQueue * pqe_get_queue();
	PriorityQueueNode * pqe_get_node(int value, int priority);

	Status pqe_make_node(PriorityQueueNode **node, int value, int priority);

	Status pqe_get_length(PriorityQueue *pqe, size_t *result);

	Status pqe_enqueue(PriorityQueue *pqe, int value, int priority);
	Status pqe_enqueue_node(PriorityQueue *pqe, PriorityQueueNode *node);

	Status pqe_dequeue(PriorityQueue *pqe);
	Status pqe_dequeue_node(PriorityQueue *pqe, PriorityQueueNode **result);

	Status pqe_display(PriorityQueue *pqe);
	Status pqe_display_raw(PriorityQueue *pqe);

	Status pqe_delete_node(PriorityQueueNode **node);
	Status pqe_delete_queue(PriorityQueue **pqe); // Erases and sets to NULL
	Status pqe_erase_queue(PriorityQueue **pqe); // Erases and inits

	Status pqe_peek_front(PriorityQueue *pqe, int *result);
	Status pqe_peek_rear(PriorityQueue *pqe, int *result);

	bool pqe_is_empty(PriorityQueue *pqe);

	Status pqe_priority_highest(PriorityQueue *pqe, int *result);
	Status pqe_priority_lowest(PriorityQueue *pqe, int *result);


#ifdef __cplusplus
}
#endif