/*
 * CStack.h
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

	typedef struct CStackBox {
		int data;
		struct CStackBox *below;
	} CStackBox;

	typedef struct CStack {
		int height;
		CStackBox *top;
	} CStack;


	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes Stack. Obligatory! Or your application will crash.
	 *
	 * @see getCStack() as an alternative
	 *
	 * @Param [ CStack **Stack ] Reference to stack
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int initCStack(CStack **Stack);

	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+

	int pushCStack(CStack **Stack, int value);

	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+

	CStackBox * popCStack(CStack **Stack);

	int sliceCStack(CStack **Stack);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	
	int displayCStack(CStack **Stack);

	int peekCStack(CStack **Stack);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	bool isEmptyCStack(CStack **Stack);
	// Is full

	// +-------------------------------------+
	// |               Getters               |
	// +-------------------------------------+
	/* Get a new Stack
	 *
	 * @Returns [ CStack * ] Pointer to new Stack
	 */
	CStack * getCStack();

	/* Gets a new stack box
	 *
	 * @Param [ int value ] value of new Box
	 *
	 * @Returns [ CStackBox * ] Pointer to new Stack Box
	 */
	CStackBox * getCStackBox(int value);

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+

#ifdef __cplusplus
}
#endif;