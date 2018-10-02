/**
 * @file Stack.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 31/03/2018
 *
 * @brief Source file for @c Stack implementations in C
 *
 */

#include "Stack.h"

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
	(*box)->data = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

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

Status stk_slice(Stack *stk)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	if (stk->height == 0 || stk->top == NULL)
		return DS_ERR_INVALID_OPERATION;

	StackBox *kill = stk->top;

	stk->top = stk->top->below;

	Status st = stk_delete_box(&kill);

	if (st != DS_OK)
		return st;

	(stk->height)--;

	return DS_OK;
}

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

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status stk_display(Stack *stk)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	if (stk->height == 0 || stk->top == NULL)
	{

		printf("\nStack\n[ empty]\n");

		return DS_OK;
	}

	StackBox *scan = stk->top;

	printf("\nStack");

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

Status stk_delete_box(StackBox **box)
{
	free(*box);

	*box = NULL;

	return DS_OK;
}

Status stk_delete_stack(Stack **stk)
{
	if ((*stk) == NULL)
		return DS_ERR_INVALID_OPERATION;

	StackBox *prev = (*stk)->top;

	Status st;

	while ((*stk)->top != NULL)
	{
		(*stk)->top = (*stk)->top->below;

		st = stk_delete_box(&prev);

		if (st != DS_OK)
			return st;
		
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

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

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

size_t stk_height(Stack *stk)
{
	if (stk == NULL)
		return 0;

	return stk->height;
}

bool stk_is_empty(Stack *stk)
{
	return (stk->top == NULL || stk->height == 0);
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Extras                                              |
// +-------------------------------------------------------------------------------------------------+

Status stk_check_balanced_brackets(const char *string, bool *result)
{
	size_t i, height, str_len = strlen(string);

	*result = false;

	if (str_len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	Stack *stk;
	StackBox *box;

	st = stk_init_stack(&stk);

	if (st != DS_OK)
		return st;

	for (i = 0; i < str_len; i++)
	{

		if (string[i] == '{' || string[i] == '(' || string[i] == '[')
			stk_put(stk, string[i]);

		if (string[i] == '}' || string[i] == ')' || string[i] == ']')
		{

			stk_get_height(stk, &height);

			if (height == 0)
				return DS_OK; // False

			stk_pop(stk, &box);

			if ((box->data == '(' && string[i] == ')') ||
				(box->data == '{' && string[i] == '}') ||
				(box->data == '[' && string[i] == ']'))
				continue;
			else
				return DS_OK;
		}
	}

	stk_get_height(stk, &height);

	if (height == 0)
		*result = true;

	return DS_OK;
}

//Status stk_hanoi(size_t pieces)
