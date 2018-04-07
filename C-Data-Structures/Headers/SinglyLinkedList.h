/*
 * @file SinglyLinkedList.h
 *
 * @author Leonardo Vencovsky
 * @date 14/03/2018
 *
 * Header file for Singly Linked List implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	/**
	 * A @c SinglyLinkedNode is what a @c SinglyLinkedList is composed of. It
	 * has an integer as its data and only one pointer to the next @c
	 * SinglyLinkedNode of the list or simply NULL when it is the last element.
	 */
	typedef struct SinglyLinkedNode {
		int data;                           /*!< Pointer to node's content */
		struct SinglyLinkedNode *next;      /*!< Pointer to the next node on the list */
	} SinglyLinkedNode;

	/**
	 * A Singly Linked List is a linear structure that is capable of constant
	 * insertion and removal. In this case, the structure is composed of two
	 * pointers, one to the first @c SinglyLinkedNode and another to the last
	 * one. This way insertions at both ends are simplified. Also this
	 * structure holds a length variable that keeps track of the structure's
	 * length, allowing for checking empty lists or position parameters that are
	 * higher than the total structure length.
	 */
	typedef struct SinglyLinkedList {
		size_t length;                      /*!< List length */
		struct SinglyLinkedNode *head;      /*!< Pointer to the first Node */
		struct SinglyLinkedNode *tail;      /*!< Pointer to the last Node */
	} SinglyLinkedList;
	
	Status sll_init_list(SinglyLinkedList **sll);
	Status sll_init_node(SinglyLinkedNode **sln);

	SinglyLinkedList * sll_get_list();
	SinglyLinkedNode * sll_get_node(int value);

	Status sll_make_node(SinglyLinkedNode **sln, int value);

	Status sll_get_length(SinglyLinkedList *sll, size_t *result);
	Status sll_get_node_data(SinglyLinkedList *sll, size_t position, int *result);
	
	Status sll_insert_head(SinglyLinkedList *sll, int value);
	Status sll_insert_at(SinglyLinkedList *sll, int value, size_t position);
	Status sll_insert_tail(SinglyLinkedList *sll, int value);
	
	//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node);
	//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node, size_t position);
	//Status sll_insert_node_tail(SinglyLinkedList *sll, SinglyLinkedNode *node);

	Status sll_remove_head(SinglyLinkedList *sll);
	Status sll_remove_at(SinglyLinkedList *sll, size_t position);
	Status sll_remove_tail(SinglyLinkedList *sll);
	
	Status sll_display(SinglyLinkedList *sll);
	Status sll_display_raw(SinglyLinkedList *sll);

	Status sll_delete_list(SinglyLinkedList **sll); // Erases and sets to NULL
	Status sll_erase_list(SinglyLinkedList **sll); // Erases and inits
	
	//Status sll_find_occurrance_first(SinglyLinkedList *sll, int key, size_t *position);
	//Status sll_find_occurrance_last(SinglyLinkedList *sll, int key, size_t *position);
	
	//Status sll_find_max(SinglyLinkedList *sll);
	//Status sll_find_min(SinglyLinkedList *sll);

	Status sll_frequency(SinglyLinkedList *sll, int key, size_t *frequency);
	
	Status sll_contains(SinglyLinkedList *sll, int key, bool *result);
	bool sll_exists(SinglyLinkedList *sll, int key);
	
	//Status sll_slice(SinglyLinkedList *sll, SinglyLinkedList **result, size_t position);
	//Status sll_slice_sublist(SinglyLinkedList *sll, SinglyLinkedList **result, size_t position1, size_t position2);

	//Status sll_pop_head(SinglyLinkedList *sll, SinglyLinkedNode **result);
	//Status sll_pop_tail(SinglyLinkedList *sll, SinglyLinkedNode **result);
	//Status sll_pop_at(SinglyLinkedList *sll, SinglyLinkedNode **result, size_t position);
	
	//Status sll_copy_list(SinglyLinkedList *sll, SinglyLinkedList **result);
	//Status sll_copy_node(SinglyLinkedList *sll, SinglyLinkedNode **result);
	
	//Status sll_reverse(SinglyLinkedList *SinglyLinkedList);
	
	//Status sll_switch_nodes(SinglyLinkedList *sll, size_t position1, size_t position2);
	//Status sll_switch_head(SinglyLinkedList *sll, size_t position);
	//Status sll_switch_tail(SinglyLinkedList *sll, size_t position);
	//Status sll_switch_ends(SinglyLinkedList *sll);
	
	//Status sll_sort_bubble(SinglyLinkedList *sll);
	//Status sll_sort_slection(SinglyLinkedList *sll);
	//Status sll_sort_insertion(SinglyLinkedList *sll);

#ifdef __cplusplus
}
#endif

