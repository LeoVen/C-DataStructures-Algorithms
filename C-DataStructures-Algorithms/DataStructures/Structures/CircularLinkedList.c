/**
 * @file CircularLinkedList.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/04/2018
 *
 * @brief Source file for @c CircularLinkedList implementations in C
 *
 */

#include "CircularLinkedList.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status cll_init_list(CircularLinkedList **cll)
{
	(*cll) = malloc(sizeof(CircularLinkedList));

	if (!(*cll))
		return DS_ERR_ALLOC;

	(*cll)->curr = NULL;
	(*cll)->length = 0;

	return DS_OK;
}

Status cll_init_node(CircularLinkedNode **cln)
{
	(*cln) = malloc(sizeof(CircularLinkedNode));

	if (!(*cln))
		return DS_ERR_ALLOC;

	(*cln)->data = 0;
	(*cln)->next = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Getters                                             |
// +-------------------------------------------------------------------------------------------------+

Status cll_make_node(CircularLinkedNode **cln, int value)
{
	*cln = malloc(sizeof(CircularLinkedNode));

	if (!(*cln))
		return DS_ERR_ALLOC;

	(*cln)->next = NULL;
	(*cln)->data = value;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status cll_insert_after(CircularLinkedList *cll, int value)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0)
	{

		Status st = cll_insert_first(cll, value);

		if (st != DS_OK)
			return st;
	}
	else
	{

		CircularLinkedNode *cln;
		cll_init_node(&cln);

		if (!cln)
			return DS_ERR_ALLOC;

		cln->data = value;

		cln->next = cll->curr->next;
		cll->curr->next = cln;

		cll->curr = cll->curr->next;

		(cll->length)++;
	}

	return DS_OK;
}

//Status cll_insert_before(CircularLinkedList *cll, int value)

//Status cll_push_after(CircularLinkedList *cll, CircularLinkedNode *node)
//Status cll_push_before(CircularLinkedList *cll, CircularLinkedNode *node)

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status cll_remove_after(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	if (cll->length == 1)
	{

		Status st = cll_remove_last(cll);

		if (st != DS_OK)
			return st;
	}
	else
	{

		CircularLinkedNode *kill = cll->curr->next;

		cll->curr->next = kill->next;

		free(kill);

		(cll->length)--;
	}

	return DS_OK;
}

Status cll_remove_current(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll_is_empty(cll))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	if (cll->length == 1)
	{

		st = cll_remove_last(cll);

		if (st != DS_OK)
			return st;
	}
	else
	{

		st = cll_iter_before(cll);

		if (st != DS_OK)
			return st;

		st = cll_remove_after(cll);

		if (st != DS_OK)
			return st;
	}

	return DS_OK;
}

//Status cll_remove_before(CircularLinkedList *cll)

//Status cll_pop_after(CircularLinkedList *cll, CircularLinkedNode **result)
//Status cll_pop_current(CircularLinkedList *cll, CircularLinkedNode **result)
//Status cll_pop_before(CircularLinkedList *cll, CircularLinkedNode **result)

// +-------------------------------------------------------------------------------------------------+
// |                                          Special Cases                                          |
// +-------------------------------------------------------------------------------------------------+

Status cll_insert_first(CircularLinkedList *cll, int value)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length != 0 || cll->curr != NULL)
		return DS_ERR_INVALID_OPERATION;

	CircularLinkedNode *cln;
	cll_init_node(&cln);

	if (!cln)
		return DS_ERR_ALLOC;

	cln->data = value;

	cll->curr = cln;
	cln->next = cln;

	(cll->length)++;

	return DS_OK;
}

Status cll_remove_last(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->length > 1)
		return DS_ERR_INVALID_OPERATION;

	free(cll->curr);

	cll->curr = NULL;

	(cll->length)--;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Iteration                                            |
// +-------------------------------------------------------------------------------------------------+

Status cll_iter_next(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	cll->curr = cll->curr->next;

	return DS_OK;
}

Status cll_iter(CircularLinkedList *cll, size_t positions)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < positions; i++)
		cll->curr = cll->curr->next;

	return DS_OK;
}

Status cll_iter_before(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	int i;
	for (i = 0; i < cll->length - 1; i++)
		cll->curr = cll->curr->next;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status cll_display(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
	{

		printf("\nCircular Linked List\n[ empty ]\n");

		return DS_OK;
	}

	CircularLinkedNode *scan = cll->curr;

	/* For visual purposes only so the last node inserted is printed last */
	scan = scan->next;

	printf("\nCircular Linked List\n ->");

	int i;
	for (i = 0; i < cll->length; i++)
	{

		printf(" %d ->", scan->data);

		scan = scan->next;
	}

	printf("\n");

	return DS_OK;
}

Status cll_display_raw(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	CircularLinkedNode *scan = cll->curr;

	/* For visual purposes only so the last node inserted is printed last */
	scan = scan->next;

	printf("\n");

	int i;
	for (i = 0; i < cll->length; i++)
	{

		printf(" %d", scan->data);

		scan = scan->next;
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status cll_delete(CircularLinkedList **cll)
{
	if ((*cll) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	while ((*cll)->curr != NULL)
	{
		st = cll_remove_after(*cll);

		if (st != DS_OK)
			return st;
	}

	free(*cll);

	*cll = NULL;

	return DS_OK;
}

Status cll_erase(CircularLinkedList **cll)
{
	if ((*cll) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = cll_delete(cll);

	if (st != DS_OK)
		return st;

	st = cll_init_list(cll);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

size_t cll_length(CircularLinkedList *cll)
{
	if (cll == NULL)
		return 0;

	return cll->length;
}

//Status cll_frequency(CircularLinkedList *cll, int key, size_t *frequency)

//Status cll_contains(CircularLinkedList *cll, int key, bool *result)
//bool cll_exists(CircularLinkedList *cll, int key)

bool cll_is_empty(CircularLinkedList *cll)
{
	return (cll->length == 0 || cll->curr == NULL);
}

//Status cll_find_max(CircularLinkedList *cll, int *result)
//Status cll_find_min(CircularLinkedList *cll, int *result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Extras                                              |
// +-------------------------------------------------------------------------------------------------+

/**
 * People are standing in a circle waiting to be executed. Counting begins at a
 * specified point in the circle and proceeds around the circle in a specified
 * direction. After a specified number of people are skipped, the next person
 * is executed. The procedure is repeated with the remaining people, starting
 * with the next person, going in the same direction and skipping the same
 * number of people, until only one person remains, and is freed.
 *
 * The problem - given the number of people, starting point, direction, and
 * number to be skipped - is to choose the position in the initial circle to
 * avoid execution.
 *
 * @param[in] n Number of people
 * @param[in] k Skip value
 * @param[out] result Remaining position
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 * @return @c DS_ERR_UNEXPECTED_RESULT if the list size is not 1 by the end
 */
Status cll_josephus(size_t n, size_t k, size_t *result)
{
	CircularLinkedList *cll;

	cll_init_list(&cll);

	if (!cll)
		return DS_ERR_ALLOC;

	size_t i;
	int val = 1;
	for (i = 1; i <= n; i++)
	{

		cll_insert_after(cll, val);

		val++;
	}

	while (cll->length > 1)
	{
		cll_iter(cll, k - 1);
		cll_remove_after(cll);
	}

	if (cll->length == 1)
	{
		*result = (size_t)cll->curr->data;
	}
	else
		return DS_ERR_UNEXPECTED_RESULT;

	cll_delete(&cll);

	return DS_OK;
}