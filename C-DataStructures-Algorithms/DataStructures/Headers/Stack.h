/**
 * @file Stack.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 31/03/2018
 *
 * @brief Header file for @c Stack implementatiosn in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Core.h"

	/**
	 * A @c StackBox is just like a @c SinglyLinkedNode but it is part of the
	 * @c Stack implementation. The names are different for didactic purposes.
	 * The structure has an integer as its data and a @c *below pointer that
	 * points to the box underneath it, pointing to @c NULL if it is the very
	 * first box above the ground.
	 */
	typedef struct StackBox {
		int data;                           /*!< Node's data */
		struct StackBox *below;             /*!< Pointer to the box underneath it */
	} StackBox;
	
	 /**
	  * A @c Stack is much like a @c SinglyLinkedList but with LIFO operations,
	  * that is, Last-in First-out, so the last item added is the first one to
	  * be removed. This way, only one pointer to the top of the @c Stack is
	  * needed since all operations are made relative to the top.
	  *
	  * @b Advantages over @c SinglyLinkedList
	  * - Its functionality is restricted to attend only LIFO operations
	  *
	  * @b Drawbacks
	  * - Restricted operations may cause some functions to be not available
	  *
	  * @b Functions
	  *
	  * @c Stack.c
	  *
	  */
	typedef struct Stack {
		size_t height;                      /*!< @c Stack Height */
		StackBox *top;                      /*!< @c StackBox on top */
	} Stack;
	
	Status stk_init_stack(Stack **stk);
	Status stk_init_box(StackBox **box);

	Stack * stk_get_stack(void);
	StackBox * stk_get_box(int value);

	Status stk_make_box(StackBox **box, int value);

	Status stk_get_height(Stack *stk, size_t *result);

	Status stk_put(Stack *stk, int value);
	Status stk_push(Stack *stk, StackBox *box);

	Status stk_slice(Stack *stk);
	Status stk_pop(Stack *stk, StackBox **box);
	
	Status stk_display(Stack *stk);
	Status stk_display_raw(Stack *stk);

	Status stk_delete_box(StackBox **box);
	Status stk_delete_stack(Stack **stk); // Erases and sets to NULL
	Status stk_erase_stack(Stack **stk); // Erases and inits

	Status stk_look(Stack *stk, int *result);
	int stk_peek(Stack *stk);

	bool stk_is_empty(Stack *stk);

	Status stk_check_balanced_brackets(const char *string, bool *result);

#ifdef __cplusplus
}
#endif