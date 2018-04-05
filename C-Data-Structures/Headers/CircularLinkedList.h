/*
 * @file CircularList.h
 *
 * @author Leonardo Vencovsky
 * @date 05/04/2018
 *
 * Header file for Circular List implementations in C
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

	//Status cll_insert_after(CircularLinkedList **cll, int value);
	//Status cll_insert_before(CircularLinkedList **cll, int value);

	//status cll_remove_before(CircularLinkedList **cll);
	//status cll_remove_current(CircularLinkedList **cll);
	//status cll_remove_after(CircularLinkedList **cll);

	//Status cll_iter_next(CircularLinkedList *cll);
	//Status cll_iter(CircularLinkedList *cll, size_t positions);
	//Status cll_iter_before(CircularLinkedList *cll);

#ifdef __cplusplus
}
#endif