/*
 * @file SinglyLinkedList.h
 *
 * @author Leonardo Vencovsky
 * @date 14/03/2018
 *
 * Header for Singly Linked List Implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	/**
	 * A Singly Linked Node is what a <code>SinglyLinkedList</code> is composed
	 * of. It has a void pointer to its data and only one pointer to the next
	 * <code>SinglyLinkedNode</code> of the list or simply NULL when it is the
	 * last element.
	 */
	typedef struct SinglyLinkedNode {
		int data;                          /*!< Pointer to node's content */
		struct SinglyLinkedNode *next;      /*!< Pointer to the next node on the list */
	} SinglyLinkedNode;

	/**
	 * A Singly Linked List is a linear structure that is capable of constant
	 * insertion and removal. In this case, the structure is composed of two
	 * pointers, one to the first <code>SinglyLinkedNode</code> and another to
	 * the last one. This way insertions at both ends are simplified. Also this
	 * structure holds a length variable that keeps track of the structure's
	 * length, allowing for checking empty lists or position parameters that are
	 * higher than the total structure length.
	 */
	typedef struct SinglyLinkedList {
		size_t length;                      /*!< List length */
		struct SinglyLinkedNode *head;      /*!< Pointer to the first Node */
		struct SinglyLinkedNode *tail;      /*!< Pointer to the last Node */
	} SinglyLinkedList;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	
	Status sll_init_list(SinglyLinkedList **sll);
	Status sll_init_node(SinglyLinkedNode **sln);

	// +-------------------------------------+
	// |               Getters               |
	// +-------------------------------------+

	SinglyLinkedList * sll_get_list();
	SinglyLinkedNode * sll_get_node(int value);

	Status sll_make_node(int value, SinglyLinkedNode **sln);
	Status sll_get_length(SinglyLinkedList *sll, size_t *length);

	Status sll_get_node_data(SinglyLinkedList *sll, size_t position, int *result);
	
	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+
	
	Status sll_insert_head(SinglyLinkedList *sll, int value);
	Status sll_insert_at(SinglyLinkedList *sll, int value, size_t position);
	Status sll_insert_tail(SinglyLinkedList *sll, int value);
	
	//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node);
	//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node, size_t position);
	//Status sll_insert_node_tail(SinglyLinkedList *sll, SinglyLinkedNode *node);
	
	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+

	Status sll_remove_head(SinglyLinkedList *sll);
	Status sll_remove_at(SinglyLinkedList *sll, size_t position);
	Status sll_remove_tail(SinglyLinkedList *sll);

	
	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	
	int sll_display(SinglyLinkedList *sll);

	Status sll_display_raw(SinglyLinkedList *sll);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+
	
	/* Delets list completely
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int deleteListSLL(SinglyLinkedList **SinglyLinkedList);
	
	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	//Status sll_find_occurrance_first(SinglyLinkedList *sll, int key, size_t *position);
	//Status sll_find_occurrance_last(SinglyLinkedList *sll, int key, size_t *position);

	//Status sll_frequency(SinglyLinkedList *sll, int key, size_t *frequency);

	/* Searches for data and returns how many were found
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be searched
	 *
	 * @Returns [ int ] The frequency count of that value
	 */
	//int frequencyCountSLL(SinglyLinkedList **SinglyLinkedList, int value);
	
	/* Returns true if a certain value exists
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be searched
	 *
	 * @Returns [ bool ] True if the value is in the list, else returns false
	 */
	//bool containsValueSLL(SinglyLinkedList **SinglyLinkedList, int value);
	
	/* Returns a list with the positions of searched value
	 *
	 *
	 */
	// TODO Get array with positions of matched values
	
	/* Gets the highest value in the list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Minimum value
	 */
	//int findMin(SinglyLinkedList **SinglyLinkedList);
	
	/* Gets the highest value in the list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Maximum value
	 */
	//int findMax(SinglyLinkedList **SinglyLinkedList);
	
	
	
	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+
	
	/* Get copy of a SLL Node
	 *
	 * @Param [ CSinglyLinkedNode *node ] Node to be copied
	 *
	 * @Returns [ CSinglyLinkedNode * ] Pointer to new node with data
	 */
	//SinglyLinkedNode * copyCSinglyLinkedNode(SinglyLinkedNode *node);
	
	/* Get copy of a list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] List to be copied
	 *
	 * @Returns [ CSinglyLinkedList * ] Pointer to new copied list
	 */
	//SinglyLinkedList * copyCSinglyLinkedList(SinglyLinkedList **SinglyLinkedList);
	
	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	/* Reverse list using three pointers method
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] List to be reversed
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int reverseListSLL(SinglyLinkedList **SinglyLinkedList);
	
	/* Switch two nodes given their position
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int position1 ] Position of node 1
	 * @Param [ int position2 ] Position of node 2
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int switchNodesSLL(SinglyLinkedList **SinglyLinkedList, int position1, int position2);
	
	/* Switch the first node with node of given position
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int position ] Position of node to be switched with head
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int switchNodeWithHead(SinglyLinkedList **SinglyLinkedList, int position);
	
	/* Switch the last node with node of given position
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int position ] Position of node to be switched with tail
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int switchNodeWithTail(SinglyLinkedList **SinglyLinkedList, int position);
	
	/* Switch head node with tail node
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int switchNodeHeadTail(SinglyLinkedList **SinglyLinkedList);
	
	/* Uses BubbleSort-like algorithm to sort list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	//int bubbleSortSLL(SinglyLinkedList **SinglyLinkedList);
	
	/*
	 *
	 *
	 */
	// TODO SelectionSort
	
	/*
	 *
	 *
	 */
	// TODO InsertionSort

#ifdef __cplusplus
}
#endif

