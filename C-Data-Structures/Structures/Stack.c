/*
 * Stack.c
 *
 * Author: Leonardo Vencovsky
 * Created on 31/03/2018
 *
 * Stack Implementations in C
 *
 */

#include "..\Headers\Stack.h"

 /*
    Return Codes

    0 - Success
	1 - Stack is empty

 */

// +-------------------------------------------------------------------------------------------------+
// |                                           Initialize                                            |
// +-------------------------------------------------------------------------------------------------+

int initCStack(Stack **stk)
{
	(*stk) = malloc(sizeof(Stack));
	(*stk)->height = 0;
	(*stk)->top = NULL;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Stack * getCStack()
{
	Stack *stack = malloc(sizeof(Stack));
	stack->height = 0;
	stack->top = NULL;
	return stack;
}

StackBox * getCStackBox(int value)
{
	StackBox *box = malloc(sizeof(StackBox));
	box->below = NULL;
	box->data = value;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

int pushCStack(Stack **stk, int value)
{
	StackBox *newBox = getCStackBox(value);
	if ((*stk)->top == NULL) {
		(*stk)->top = newBox;
	}
	else {
		newBox->below = (*stk)->top;
		(*stk)->top = newBox;
	}
	return 0; // OK
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

StackBox * popCStack(Stack **stk)
{
	// TODO
	//
	//
}

int sliceCStack(Stack **stk)
{
	if (!isEmptyCStack(stk)) {
		StackBox *kill = (*stk)->top;
		(*stk)->top = (*stk)->top->below;
		free(kill);
	}
	return 1; // Stack is empty
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayCStack(Stack **stk)
{
	if (!isEmptyCStack(stk)) {
		StackBox *scanner = (*stk)->top;
		printf("\nC Stack\n");
		// while (scanner)
		while (scanner != NULL)
		{
			printf("\n|%8d |", scanner->data);
			scanner = scanner->below;
		}
		printf("\n");
		return 0;
	}
	return 1; // Stack is Empty
}

int displayRawCStack(Stack **stk)
{
	if (!isEmptyCStack(stk)) {
		StackBox *scanner = (*stk)->top;
		printf("\n");
		while (scanner != NULL)
		{
			printf("%d ", scanner->data);
			scanner = scanner->below;
		}
		printf("\n");
		return 0;
	}
	return 1; // Stack is Empty
}



int peekCStack(Stack **stk)
{
	return (*stk)->top->data;
}

bool isEmptyCStack(Stack **stk)
{
	if ((*stk)->top == NULL)
		return true;
	else
		return false;
}