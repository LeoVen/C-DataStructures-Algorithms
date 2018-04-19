/**
 * @file CircularLinkedList.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/04/2018
 *
 * @brief Header file for @c CircularLinkedList implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	/**
	 * A @c CircularLinkedNode is what a @c CircularLinkedList is composed of.
	 * They are exactly the same as @c SinglyLinkedNode. The differentiation of
	 * both was made so that no structure depends on another.
	 */
	typedef struct CircularLinkedNode {
		int data;                           /*!< Pointer to node's content */
		struct CircularLinkedNode *next;    /*!< Pointer to the next node on the list */
	} CircularLinkedNode;


	/**
	 * A @c CircularLinkedList is a structure much like a @c SinglyLinkedList
	 * except that the nodes wrap around making it a circular structure. This
	 * way only one pointer is necessarry as you won't have any problems like
	 * pointing the @c *head pointer to the next node making the node before it
	 * inaccessible. But in a circular list you must be careful to not fall
	 * into an infinite loop as the list won't have a node pointing to @c NULL
	 * as if it was the end of it.
	 *
	 * @b Advantages over @c SinglyLinkedList
	 * - Can be used to many problems where a circular structure is needed
	 * - No need for a tail pointer as the list wraps around itself
	 * - No chances of loosing reference to previous Nodes if the pointer to
	 * the first element of the list moves forward
	 *
	 * @b Drawbacks
	 * - Insertions at the end of the list are much slower
	 * - The end of the list is relative and may change
	 *
	 * @b Functions
	 *
	 * @c CircularLinkedList.c
	 *
	 */
	typedef struct CircularLinkedList {
		int length;                         /*!< List length */
		struct CircularLinkedNode *curr;    /*!< Pointer to current node. Functions operate relative to this node */
	} CircularLinkedList;


	Status cll_init_list(CircularLinkedList **cli);
	Status cll_init_node(CircularLinkedNode **cln);

	CircularLinkedList * cll_get_list();
	CircularLinkedNode * cll_get_node(int value);

	Status cll_make_node(CircularLinkedNode **cln, int value);

	Status cll_insert_first(CircularLinkedList *cll, int value);
	Status cll_remove_last(CircularLinkedList *cll);

	Status cll_insert_after(CircularLinkedList *cll, int value);
	//Status cll_insert_before(CircularLinkedList *cll, int value);

	Status cll_remove_after(CircularLinkedList *cll);
	//Status cll_remove_current(CircularLinkedList *cll);
	//Status cll_remove_before(CircularLinkedList *cll);

	Status cll_iter_next(CircularLinkedList *cll);
	Status cll_iter(CircularLinkedList *cll, size_t positions);
	//Status cll_iter_before(CircularLinkedList *cll);

	Status cll_display(CircularLinkedList *cll);
	Status cll_display_raw(CircularLinkedList *cll);

	Status cll_josephus(CircularLinkedList **cll, size_t n, size_t k, size_t *result);

#ifdef __cplusplus
}
#endif