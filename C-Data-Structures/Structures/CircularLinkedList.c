/**
 * @file CircularLinkedList.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/04/2018
 *
 * @brief Source file for @c CircularLinkedList implementations in C
 *
 */

#include "..\Headers\CircularLinkedList.h"

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

	(*cln)->data = NULL;
	(*cln)->next = NULL;

	return DS_OK;
}

CircularLinkedList * cll_get_list()
{
	CircularLinkedList *cll = malloc(sizeof(CircularLinkedList));

	cll->curr = NULL;
	cll->length = 0;

	return cll;
}

CircularLinkedNode * cll_get_node(int value)
{
	CircularLinkedNode *cln = malloc(sizeof(CircularLinkedNode));

	cln->data = value;
	cln->next = NULL;

	return cln;
}

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

	if (cll->length == 0) {

		Status st = cll_insert_first(cll, value);

		if (st != DS_OK)
			return st;

	}
	else {

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

//Status cll_insert_before(CircularLinkedList *cll, int value);

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status cll_remove_after(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	if (cll->length == 1) {
		
		Status st = cll_remove_last(cll);
		
		if (st != DS_OK)
			return st;

	}
	else {

		CircularLinkedNode *kill = cll->curr->next;

		cll->curr->next = kill->next;

		free(kill);

		(cll->length)--;

	}

	return DS_OK;
}

//Status cll_remove_current(CircularLinkedList *cll);
//Status cll_remove_before(CircularLinkedList *cll);

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

	int i;
	for (i = 0; i < positions; i++) {
		cll->curr = cll->curr->next;
	}

	return DS_OK;
}

//Status cll_iter_before(CircularLinkedList *cll);

Status cll_display(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL) {

		printf("\nCircular Linked List\n[ empty ]\n");

		return DS_OK;
	}

	CircularLinkedNode *scan = cll->curr;

	/* For visual purposes only so the last node inserted is printed last */
	scan = scan->next;

	printf("\nCircular Linked List\n ->");

	int i;
	for (i = 0; i < cll->length; i++) {

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
	for (i = 0; i < cll->length; i++) {

		printf(" %d", scan->data);

		scan = scan->next;

	}

	printf("\n");

	return DS_OK;
}

/**
 * People are standing in a circle waiting to be executed. Counting begins at a
 * specified point in the circle and proceeds around the circle in a specified
 * direction. After a specified number of people are skipped, the next person
 * is executed. The procedure is repeated with the remaining people, starting
 * with the next person, going in the same direction and skipping the same
 * number of people, until only one person remains, and is freed.
 *
 * The problem — given the number of people, starting point, direction, and
 * number to be skipped — is to choose the position in the initial circle to
 * avoid execution.
 */
Status cll_josephus(CircularLinkedList **cll, size_t n, size_t k, size_t *result)
{
	cll_init_list(cll);

	if (!(*cll))
		return DS_ERR_ALLOC;

	int i;
	for (i = 1; i <= n; i++) {

		cll_insert_after(*cll, i);

	}

	while ((*cll)->length > 1)
	{
		cll_iter(*cll, k - 1);
		cll_remove_after(*cll);
	}

	if ((*cll)->length == 1) {
		*result = (size_t)(*cll)->curr->data;
	}
	else
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}