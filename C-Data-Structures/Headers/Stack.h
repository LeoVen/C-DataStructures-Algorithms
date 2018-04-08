/**
 * @file Stack.h
 *
 * @author Leonardo Vencovsky
 * @date 31/03/2018
 *
 * @brief Header for Stack implementatiosn in C
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	/**
	 * 
	 *
	 */
	typedef struct StackBox {
		int data;
		struct StackBox *below;
	} StackBox;
	
	 /**
	  * A @c Stack is much like a @c SinglyLinkedList but with FIFO operations, that
	  * is, First-in First-out, so the first item added is the first one to be
	  * removed. This way, only one pointer to the top of the @c Stack is needed
	  * since all operations are made relative to the top.
	  */
	typedef struct Stack {
		int height;
		StackBox *top;
	} Stack;
	
	Status stk_init_stack(Stack **stk);
	Status stk_init_box(StackBox **box);

	Stack * stk_get_stack();
	StackBox * stk_get_box(int value);

	Status stk_make_box(StackBox **box, int value);

	Status stk_look(Stack *stk, int *result);
	int stk_peek(Stack *stk);
	Status stk_get_height(Stack *stk, size_t *result);

	Status stk_put(Stack *stk, int value);
	Status stk_push(Stack *stk, StackBox *box);

	Status stk_pop(Stack *stk, StackBox **box);

	Status stk_slice(Stack *stk);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	
	Status stk_display(Stack *stk);
	Status stk_display_raw(Stack *stk);

	Status stk_delete_stack(Stack **stk); // Erases and sets to NULL
	Status stk_erase_stack(Stack **stk); // Erases and inits

	

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	bool stk_is_empty(Stack *stk);
	// Is full

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+

#ifdef __cplusplus
}
#endif;