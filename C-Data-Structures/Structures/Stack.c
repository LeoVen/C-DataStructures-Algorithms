/*
 * CStack.c
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

int initCStack(CStack **Stack)
{
	(*Stack) = malloc(sizeof(CStack));
	(*Stack)->height = 0;
	(*Stack)->top = NULL;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

CStack * getCStack()
{
	CStack *stack = malloc(sizeof(CStack));
	stack->height = 0;
	stack->top = NULL;
	return stack;
}

CStackBox * getCStackBox(int value)
{
	CStackBox *box = malloc(sizeof(CStackBox));
	box->below = NULL;
	box->data = value;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

int pushCStack(CStack **Stack, int value)
{
	CStackBox *newBox = getCStackBox(value);
	if ((*Stack)->top == NULL) {
		(*Stack)->top = newBox;
	}
	else {
		newBox->below = (*Stack)->top;
		(*Stack)->top = newBox;
	}
	return 0; // OK
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

CStackBox * popCStack(CStack **Stack)
{
	// TODO
	//
	//
}

int sliceCStack(CStack **Stack)
{
	if (!isEmptyCStack(Stack)) {
		CStackBox *kill = (*Stack)->top;
		(*Stack)->top = (*Stack)->top->below;
		free(kill);
	}
	return 1; // Stack is empty
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayCStack(CStack **Stack)
{
	if (!isEmptyCStack(Stack)) {
		CStackBox *scanner = (*Stack)->top;
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

int displayRawCStack(CStack **Stack)
{
	if (!isEmptyCStack(Stack)) {
		CStackBox *scanner = (*Stack)->top;
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



int peekCStack(CStack **Stack)
{
	return (*Stack)->top->data;
}

bool isEmptyCStack(CStack **Stack)
{
	if ((*Stack)->top == NULL)
		return true;
	else
		return false;
}