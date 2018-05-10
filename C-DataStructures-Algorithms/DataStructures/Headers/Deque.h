/**
 * @file Deque.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 09/05/2018
 *
 * @brief Header file for @c Deque implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Core.h"

	/**
	 * A @c DequeNode is what a @c Deque is composed of. It has an integer as
	 * its data one pointer to the @c DequeNode before it, another to the next
	 * one, or simply NULL when it is an element at the edges of the @c Deque.
	 *
	 */
	typedef struct DequeNode {
		int data;                           /*!< Node's data */
		struct DequeNode *next;             /*!< Pointer to the next node in the @c Deque */
		struct DequeNode *prev;             /*!< Pointer to the previous node in the @c Deque */
	} DequeNode;

	/**
	 * A @c Deque (or a Double Ended Queue) is much like a @c Queue but with
	 * FIFO operations on both ends, that is, First-in First-out, so the first
	 * item added in one end is the first one to be removed at that same end.
	 * Note that in this case the @c *front and @c *rear pointers are relative
	 * and are distinct for reference only.
	 * <code>front <- next | prev -> rear</code>
	 *
	 * @b Advantages over @c Queue
	 * - Nodes can be added and removed from both ends
	 *
	 * @b Drawbacks
	 * - Extra memory space for another pointer
	 *
	 * @b Functions
	 *
	 * @c Deque.c
	 *
	 */
	typedef struct Deque {
		size_t length;                      /*!< Total @c Deque length */
		struct DequeNode *front;                   /*!< Where @c QueueNode are removed */
		struct DequeNode *rear;                    /*!< Where @c QueueNode are inserted */
	} Deque;

	Status deq_init_queue(Deque **deq);
	Status deq_init_node(DequeNode **node);

	Deque * deq_get_queue();
	DequeNode * deq_get_node(int value);

	Status deq_make_node(DequeNode **node, int value);

	Status deq_get_length(Deque *deq, size_t *result);

	Status deq_enqueue_front(Deque *deq, int value);
	Status deq_enqueue_rear(Deque *deq, int value);
	Status deq_enqueue_front_node(Deque *deq, DequeNode *node);
	Status deq_enqueue_rear_node(Deque *deq, DequeNode *node);

	Status deq_dequeue_front(Deque *deq);
	Status deq_dequeue_rear(Deque *deq);
	Status deq_dequeue_front_node(Deque *deq, DequeNode **result);
	Status deq_dequeue_rear_node(Deque *deq, DequeNode **result);

	Status deq_display(Deque *deq);
	Status deq_display_raw(Deque *deq);

	Status deq_delete_node(DequeNode **node);
	Status deq_delete_queue(Deque **deq); // Erases and sets to NULL
	Status deq_erase_queue(Deque **deq);  // Erases and inits

	Status deq_peek_front(Deque *deq, int *result);
	Status deq_peek_rear(Deque *deq, int *result);

	bool deq_is_empty(Deque *deq);

#ifdef __cplusplus
}
#endif;
