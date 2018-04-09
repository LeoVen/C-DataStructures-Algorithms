/**
 * @file Stack.c
 *
 * @author Leonardo Vencovsky
 * @date 31/03/2018
 *
 * @brief Stack Implementations in C
 */

#include "..\Headers\Stack.h"

 /*
    Return Codes

    0 - Success
	1 - Stack is empty

 */

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status stk_init_stack(Stack **stk)
{
	(*stk) = malloc(sizeof(Stack));

	if (!(*stk))
		return DS_ERR_ALLOC;

	(*stk)->height = 0;
	(*stk)->top = NULL;

	return DS_OK;
}

Status stk_init_box(StackBox **box)
{
	(*box) = malloc(sizeof(StackBox));

	if (!(*box))
		return DS_ERR_ALLOC;

	(*box)->below = NULL;
	(*box)->data = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Stack * stk_get_stack()
{
	Stack *stk = malloc(sizeof(Stack));
	
	stk->height = 0;
	stk->top = NULL;

	return stk;
}

StackBox * stk_get_box(int value)
{
	StackBox *box = malloc(sizeof(StackBox));

	box->below = NULL;
	box->data = value;

	return box;
}

Status stk_make_box(StackBox **box, int value)
{
	(*box) = malloc(sizeof(StackBox));

	if (!(*box))
		return DS_ERR_ALLOC;

	(*box)->below = NULL;
	(*box)->data = value;

	return DS_OK;
}

Status stk_get_height(Stack *stk, size_t *result)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	StackBox *scan = stk->top;
	
	*result = 0;

	while (scan != NULL)
	{
		scan = scan->below;
		(*result)++;
	}

	if ((*result) != stk->height)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status stk_put(Stack *stk, int value)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	StackBox *box;
	stk_make_box(&box, value);

	if (!box)
		return DS_ERR_ALLOC;

	box->below = stk->top;
	stk->top = box;

	(stk->height)++;

	return DS_OK;
}

Status stk_push(Stack *stk, StackBox *box)
{
	if (stk == NULL || box == NULL)
		return DS_ERR_NULL_POINTER;

	box->below = stk->top;
	stk->top = box;

	(stk->height)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status stk_pop(Stack *stk, StackBox **box)
{
	if (stk == NULL || box == NULL)
		return DS_ERR_NULL_POINTER;

	(*box) = stk->top;
	stk->top = stk->top->below;
	(*box)->below = NULL;

	(stk->height)--;

	return DS_OK;
}

Status stk_slice(Stack *stk)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	if (stk->height == 0 || stk->top == NULL)
		return DS_ERR_INVALID_OPERATION;

	StackBox *kill = stk->top;

	stk->top = stk->top->below;

	free(kill);

	(stk->height)--;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status stk_display(Stack *stk)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	if (stk->height == 0 || stk->top == NULL) {

		printf("\nC Stack\n[ empty]\n");

		return DS_OK;
	}

	StackBox *scan = stk->top;

	printf("\nC Stack");

	while (scan != NULL)
	{
		printf("\n|%10d |", scan->data);
		scan = scan->below;
	}
	printf("\n");

	return DS_OK;
}

Status stk_display_raw(Stack *stk)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	StackBox *scan = stk->top;

	printf("\n");

	while (scan != NULL)
	{
		printf(" %d", scan->data);
		scan = scan->below;
	}
	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status stk_delete_stack(Stack **stk)
{
	if ((*stk) == NULL)
		return DS_ERR_INVALID_OPERATION;

	StackBox *prev = (*stk)->top;

	while ((*stk)->top != NULL)
	{
		(*stk)->top = (*stk)->top->below;
		free(prev);
		prev = (*stk)->top;
	}

	free(*stk);

	(*stk) = NULL;

	return DS_OK;
}

Status stk_erase_stack(Stack **stk)
{
	if ((*stk) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = stk_delete_stack(stk);

	if (st != DS_OK)
		return st;

	st = stk_init_stack(stk);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status stk_look(Stack *stk, int *result)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	if (stk->height == 0 || stk->top == NULL)
		return DS_ERR_INVALID_OPERATION;

	*result = stk->top->data;

	return DS_OK;
}

int stk_peek(Stack *stk)
{
	return stk->top->data;
}

bool stk_is_empty(Stack *stk)
{
	if (stk->top == NULL || stk->height == 0)
		return true;
	else
		return false;
}