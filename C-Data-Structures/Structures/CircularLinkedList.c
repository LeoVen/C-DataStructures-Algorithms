/*
 * @file CircularList.c
 *
 * @author Leonardo Vencovsky
 * @date 05/04/2018
 *
 * Source file for Circular List implementations in C
 *
 */

#include "..\Headers\CircularLinkedList.h"

// Accessory functions
Status cll_insert_first(CircularLinkedList *cll, int value);
Status cll_remove_last(CircularLinkedList *cll);


Status cll_init_list(CircularLinkedList **cll)
{
	(*cll) = malloc(sizeof(CircularLinkedList));

	if (!cll)
		return DS_ERR_ALLOC;

	(*cll)->curr = NULL;
	(*cll)->length = 0;

	return DS_OK;
}

Status cll_init_node(CircularLinkedNode **cln)
{
	(*cln) = malloc(sizeof(CircularLinkedNode));

	if (!cln)
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

	if (!cln)
		return DS_ERR_ALLOC;

	(*cln)->next = NULL;
	(*cln)->data = value;

	return DS_OK;
}






Status cll_insert_first(CircularLinkedList *cll, int value)
{

}

Status cll_remove_last(CircularLinkedList *cll)
{

}