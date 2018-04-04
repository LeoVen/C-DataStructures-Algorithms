/*
 * CDoublyLinkedList.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header for Doubly Linked List Implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct DoublyLinkedNode {
		int data;
		struct DoublyLinkedNode *next;
		struct DoublyLinkedNode *prev;
	} DoublyLinkedNode;

	typedef struct DoublyLinkedList {
		bool initialized;
		int length;
		DoublyLinkedNode *head;
		DoublyLinkedNode *tail;
	} DoublyLinkedList;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes List. Obligatory! Or your application will crash.
	 *
	 * @see getCDoublyLinkedList() as an alternative
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int initListDLL(DoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |              Getters                |
	// +-------------------------------------+
	/* Get a new Doubly Linked List
	 *
	 * @Returns [ CDoublyLinkedList * ] Pointer to new Doubly Linked List
	 */
	DoublyLinkedList * getCDoublyLinkedList();

	/* Get a DLL Node
	 *
	 * @Param [ int value ] Node value
	 *
	 * @Returns [ CDoublyLinkedNode * ] Pointer to new node with data
	 */
	DoublyLinkedNode * getCDoublyLinkedNode(int value);

	/* Gets length of a list
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] List length
	 */
	int getListSizeDLL(DoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+
	/* Inserts new node at the first position
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertHeadDLL(DoublyLinkedList **DoublyLinkedList, int value);

	/* Inserts node at chosen position
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 * @Param [ int position ] Position for new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertMiddleDLL(DoublyLinkedList **DoublyLinkedList, int value, int position);

	/* Inserts node at the last position
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertTailDLL(DoublyLinkedList **DoublyLinkedList, int value);

	/*
	 * TODO insert pre-made node
	 *
	 */
	int insertNodeDLL(DoublyLinkedList **DoublyLinkedList, DoublyLinkedNode *node, int position);

	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+
	/* Removes first node
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeHeadDLL(DoublyLinkedList **DoublyLinkedList);

	/* Removes chosen node
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int position ] Node at position to be removed
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeMiddleDLL(DoublyLinkedList **DoublyLinkedList, int position);

	/* Removes last node
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeTailDLL(DoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	/* Displays list in console
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayListDLL(DoublyLinkedList **DoublyLinkedList);

	/* Displays raw list in console
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayRawListDLL(DoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+
	/*
	 * Utility function to reposition head and tail whenever needed
	 *
	 * @Param [ CDoublyLinkedList *DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ void ]
	 */
	void resetHeadTail(DoublyLinkedList *DoublyLinkedList);

	/* Delets list completely
	 *
	 * @Param [ CDoublyLinkedList *DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	// TODO int deleteListDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	/*
	 *
	 *
	 */
	// TODO int searchValueDLL(CDoublyLinkedList **DoublyLinkedList, int value);

	/* Gets the smallest value in the list
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Minimum value
	 */
	// TODO int findMinDLL(CDoublyLinkedList **DoublyLinkedList);

	/* Gets the highest value in the list
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Maximum value
	 */
	// TODO int findMaxDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	// Copy List
	// Copy Node

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	/*
	 *
	 *
	 */
	// Reverse List

	/*
	 *
	 *
	 */
	// BubbleSort

	/*
	 *
	 *
	 */
	// SelectionSort

	/*
	 *
	 *
	 */
	// InsertionSort


#ifdef __cplusplus
}
#endif

