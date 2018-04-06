/*
 * Stack.h
 *
 * Author: Leonardo Vencovsky
 * Created on 31/03/2018
 *
 * Header for Stack in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct StackBox {
		int data;
		struct StackBox *below;
	} StackBox;

	typedef struct Stack {
		int height;
		StackBox *top;
	} Stack;


	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes Stack. Obligatory! Or your application will crash.
	 *
	 * @see getCStack() as an alternative
	 *
	 * @Param [ Stack **Stack ] Reference to stack
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int initCStack(Stack **stk);

	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+

	int pushCStack(Stack **stk, int value);

	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+

	StackBox * popCStack(Stack **stk);

	int sliceCStack(Stack **stk);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	
	int displayCStack(Stack **stk);

	int peekCStack(Stack **stk);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	bool isEmptyCStack(Stack **stk);
	// Is full

	// +-------------------------------------+
	// |               Getters               |
	// +-------------------------------------+
	/* Get a new Stack
	 *
	 * @Returns [ Stack * ] Pointer to new Stack
	 */
	Stack * getCStack();

	/* Gets a new stack box
	 *
	 * @Param [ int value ] value of new Box
	 *
	 * @Returns [ StackBox * ] Pointer to new Stack Box
	 */
	StackBox * getCStackBox(int value);

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+

#ifdef __cplusplus
}
#endif;