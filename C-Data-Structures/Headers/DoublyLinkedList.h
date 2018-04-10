/*
 * @file DoublyLinkedList.h
 *
 * @author Leonardo Vencovsky
 * @date 18/03/2018
 *
 * @brief Header for Doubly Linked List implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	/**
	 * A @c DoublyLinkedNode is what a @c DoublyLinkedList is composed of. It
	 * has an integer as its data and two pointers to other @c DoublyLinkedList
	 * with one pointing to the next element and another to the one before it.
	 * Nodes in both ends have either the @c *prev pointer or the @c *next
	 * pointer pointing to @c NULL symbolizing the end of the list.
	 *
	 * @b Advantages over @c SinglyLinkedList
	 * - Can be traversed both ways
	 * - No need for the pointer immediately before the node to be removed
	 *
	 * @b Drawbacks
	 * - No random access
	 * - Extra memory for yet another pointer on each element
	 */
	typedef struct DoublyLinkedNode {
		int data;                           /*!< Node's data */
		struct DoublyLinkedNode *next;      /*!< Pointer to the next node on the list */
		struct DoublyLinkedNode *prev;      /*!< Pointer to the previous node on the list */
	} DoublyLinkedNode;

	/*
	 * A Doubly Linked List is a linear structure like @c SinglyLinkedList
	 * but its nodes have two pointers. One pointing forward and another
	 * pointing backwards. The structure is composed of two pointers, one to
	 * the first @c DoublyLinkedNode and another to the last one. This way
	 * insertions at both ends are simplified. Also this structure holds a
	 * length variable that keeps track of the structure's length, allowing for
	 * checking empty lists or position parameters that are higher than the
	 * total structure length.
	 *
	 * @b Functions
	 * 
	 * @c DoublyLinkedList.c
	 */
	typedef struct DoublyLinkedList {
		size_t length;                      /*!< List length */
		struct DoublyLinkedNode *head;      /*!< Pointer to the first Node on the list */
		struct DoublyLinkedNode *tail;      /*!< Pointer to the last Node on the list */
	} DoublyLinkedList;

	Status dll_init_list(DoublyLinkedList **dll);
	Status dll_init_node(DoublyLinkedNode **node);

	DoublyLinkedList * dll_get_list();
	DoublyLinkedNode * dll_get_node(int value);

	Status dll_make_node(DoublyLinkedNode **node, int value);

	Status dll_get_length(DoublyLinkedList *dll, size_t *result);

	//Status dll_get_node_data(DoublyLinkedList *dll, size_t position, int *result);
	//Status dll_update_node_data(DoublyLinkedList *dll, int value, size_t position);

	Status dll_insert_head(DoublyLinkedList *dll, int value);
	//Status dll_insert_at(DoublyLinkedList *dll, int value, size_t position);
	Status dll_insert_tail(DoublyLinkedList *dll, int value);

	//Status dll_insert_node_head(DoublyLinkedList *dll, DoublyLinkedList *node);
	//Status dll_insert_node_at(DoublyLinkedList *dll, DoublyLinkedList *node, size_t position);
	//Status dll_insert_node_tail(DoublyLinkedList *dll, DoublyLinkedList *node);

	Status dll_remove_head(DoublyLinkedList *dll);
	//Status dll_remove_at(DoublyLinkedList *dll, size_t position);
	Status dll_remove_tail(DoublyLinkedList *dll);

	//Status dll_remove_node_head(DoublyLinkedList *dll, DoublyLinkedList **node);
	//Status dll_remove_node_at(DoublyLinkedList *dll, DoublyLinkedList **node, size_t position);
	//Status dll_remove_node_tail(DoublyLinkedList *dll, DoublyLinkedList **node);

	Status dll_display(DoublyLinkedList *dll);
	Status dll_display_raw(DoublyLinkedList *dll);

	Status dll_delete_node(DoublyLinkedNode **node);
	Status dll_delete_list(DoublyLinkedList **dll); // Erases and sets to NULL
	Status dll_erase_list(DoublyLinkedList **dll); // Erases and inits

	Status dll_frequency(DoublyLinkedList *dll, int key, size_t *frequency);

	Status dll_contains(DoublyLinkedList *dll, int key, bool *result);
	bool dll_exists(DoublyLinkedList *dll, int key);

	bool dll_is_empty(DoublyLinkedList *dll);

	Status dll_find_max(DoublyLinkedList *dll, int *result);
	Status dll_find_min(DoublyLinkedList *dll, int *result);

	//Status dll_occurrance_list(DoublyLinkedList *dll, DoublyLinkedList **result, int key);

	//Status dll_find_occurrance_first(DoublyLinkedList *dll, int key, size_t *position);
	//Status dll_find_occurrance_last(DoublyLinkedList *dll, int key, size_t *position);

	//Status dll_link_head(DoublyLinkedList *dll1, DoublyLinkedList *dll2);
	//Status dll_link_at(DoublyLinkedList *dll1, DoublyLinkedList *dll2, size_t position);
	//Status dll_link_tail(DoublyLinkedList *dll1, DoublyLinkedList *dll2);

	//Status dll_slice_head(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position);
	//Status dll_slice_sublist(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position1, size_t position2);
	//Status dll_slice_tail(DoublyLinkedList *dll, DoublyLinkedList **result, size_t position);
	
	//Status dll_copy_list(DoublyLinkedList *dll, DoublyLinkedList **result);
	//Status dll_copy_node(DoublyLinkedList *node, DoublyLinkedList **result);

	//Status dll_reverse(DoublyLinkedList *dll);

	//Status dll_switch_nodes(DoublyLinkedList *dll, size_t position1, size_t position2);
	//Status dll_switch_head(DoublyLinkedList *dll, size_t position);
	//Status dll_switch_tail(DoublyLinkedList *dll, size_t position);
	//Status dll_switch_ends(DoublyLinkedList *dll);

	//Status dll_sort_bubble(DoublyLinkedList *dll);
	//Status dll_sort_slection(DoublyLinkedList *dll);
	//Status dll_sort_insertion(DoublyLinkedList *dll);

	//Status dll_merge_sorted(DoublyLinkedList *dll1, DoublyLinkedList *dll2, DoublyLinkedList **result);


#ifdef __cplusplus
}
#endif

