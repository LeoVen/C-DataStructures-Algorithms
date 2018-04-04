/**
 * @file SinglyLinkedList.c
 *
 * @author Leonardo Vencovsky
 * @date 14/03/2018
 *
 * @brief Singly Linked List Implementations in C
 *
 * Singly Linked List are linear structures that...
 *
 * @note A note about SLL
 *
 */

// To be removed. Kept only for reference
/*
	Return Codes

   -1 - List Erased
    0 - Success
    1 - List not Initialized or locked
    2 - Invalid Position
    3 - List is Empty
	4 - Only one node -> won't reverse/sort list

*/

#include "..\Headers\SinglyLinkedList.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

/**
 * Initializes a new <code>SinglyLinkedList</code>.
 *
 * @param[out] sll Reference to an empty list
 *
 * @return DS_OK if all operations were successful
 * @return DS_ERR_ALLOC if allocation failed
 *
 * @see sll_get_list
 */
Status sll_init_list(SinglyLinkedList **sll)
{
	(*sll) = malloc(sizeof(SinglyLinkedList));

	if (!sll)
		return DS_ERR_ALLOC;

	(*sll)->length = 0;
	(*sll)->head = NULL;
	(*sll)->tail = NULL;

	return DS_OK;
}

/**
 * @brief Initializes a new <code>SinglyLinkedNode</code>.
 *
 * This function uses malloc to allocate a new <code>SinglyLinkedNode</code>,
 * if the allocation fails #DS_ERR_ALLOC is returned.
 *
 * @param[out] sln Reference to an empty node
 *
 * @return DS_OK if all operations were successful
 * @return DS_ERR_ALLOC if allocation failed
 *
 * @see sll_get_node()
 */
Status sll_init_node(SinglyLinkedNode **sln)
{
	(*sln) = malloc(sizeof(SinglyLinkedNode));

	if (!sln)
		return DS_ERR_ALLOC;

	(*sln)->data = NULL;
	(*sln)->next = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Initializes a new <code>SinglyLinkedList</code> and returns it as a
 * result.
 *
 * This functions uses malloc to allocate a new <code>SinglyLinkedList</code>,
 * sets @c length to 0 and points @c head and @c tail to @c NULL, and finally
 * returns the new List.
 *
 * @note Avoid using this function as it does not return a status code and
 * does not check for failures. Give preference to <code>sll_init_list()</code>
 */
SinglyLinkedList * sll_get_list()
{
	SinglyLinkedList *sll = malloc(sizeof(SinglyLinkedList));
	sll->length = 0;
	sll->head = NULL;
	sll->tail = NULL;
	return sll;
}

/**
 * Initializes a new <code>SinglyLinkedNode</code> and returns it as a result.
 *
 * @param[int] value Node value
 *
 * @note Avoid using this function as it does not return a <code>Status</code>
 * code and does not check for failures. Give preference to
 * <code>sll_init_list()</code>
 */
SinglyLinkedNode * sll_get_node(void *value)
{
	SinglyLinkedNode *sln = malloc(sizeof(SinglyLinkedNode));
	sln->next = NULL;
	sln->data = value;
	return sln;
}

/**
 * Get <code>SinglyLinkedList</code> length
 *
 * @param[in] sll List reference
 * @param[out] 
 *
 * @return Returns <code>Status</code> code
 */
Status sll_get_length(SinglyLinkedList *sll, size_t *length)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *scanner = sll->head;

	int listSize = 0;

	while (scanner != NULL)
	{
		scanner = scanner->next;
		listSize++;
	}

	*length = listSize;

	return DS_OK;
}


// +-------------------------------------------------------------------------------------------------+
// |                                              TODO                                               |
// +-------------------------------------------------------------------------------------------------+


/**
 * Get a specific node data
 *
 * @param[in] value Node value
 *
 * @return Returns list length
 *
 * @note Be careful with this
 */
Status sll_get_node_data(SinglyLinkedList *sll, size_t position, void **result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0)
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	*result = sll->head->data;
	
	SinglyLinkedNode *scanner = sll->head;

	int i;
	for (i = 0; i < position; i++) {

		if (scanner == NULL)
			return DS_ERR_ITER;

		scanner = scanner->next;
	}

	*result = scanner->data;

	return DS_OK;
}


//// +-------------------------------------------------------------------------------------------------+
//// |                                            Insertion                                            |
//// +-------------------------------------------------------------------------------------------------+
//
///* INSERT
// *
// * Interval [0, size]
// * Assuming lists starts at the zeroth (0) position.
// *
// * There are three cases:
// *
// * Always:
// *     Check if structure was initialized. Initialization is obligatory!
// *
// * Insert head:
// *     Node->next = head
// *     Reposition head to new Node
// *
// * Insert tail:
// *     Insert new Node to tail->next
// *     Reposition tail to new Node
// *
// * Insert middle:
// *     Position can be the same as the size
// *     This allows you to insert at the last non-existing (yet) position
// *     if (position == 0) - Insert at head
// *     if (position == size - 1) - Insert at tail
// *     else  Insert middle with (possibly) double pointer
// *         - interval [0 , size]
// *         - Position tmp pointer one before chosen node
// *         - new Node->next = tmp->next
// *         - tmp->next = new Node
// *     reposition tail
// *
// */
//
/**
 * Inserts new <code>SinglyLinkedNode</code> at the first position
 *
 * @see getCSinglyLinkedList() as an alternative
 *
 * @param[in] sll Reference to a non-empty list
 * @param[in] value Value to be inserted
 *
 * @return DS_OK if all operations were successful
 * @return DS_ERR_ALLOC if allocation failed
 */
Status sll_insert_head(SinglyLinkedList *sll, void *value)
{
	if (sll == NULL || value == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *sln;

	if (sll_init_node(&sln) != DS_OK)
		return DS_ERR_OPERATION_FAILED;

	sln->data = value;

	if (!sln)
		return DS_ERR_ALLOC;

	if (sll->head == NULL) {
		sll->head = sln;
		sll->tail = sln;
	}
	else {
		sln->next = sll->head;
		sll->head = sln;
	}

	sll->length++;

	return DS_OK;
}
//
//int insertMiddleSLL(SinglyLinkedList **SinglyLinkedList, int value, int position)
//{
//	SinglyLinkedList *sll = *SinglyLinkedList;
//	if (sll->initialized) {
//		// [0, size]
//		if (position < 0 || position > sll->length) return 2; // Invalid Position
//		if (position == 0) {
//			// OK
//			return insertHeadSLL(SinglyLinkedList, value);
//		}
//		else if (position == sll->length) {
//			// OK
//			return insertTailSLL(SinglyLinkedList, value);
//		}
//		else {
//			int i;
//			SinglyLinkedNode *scanner = sll->head;
//			// i starts at 1 so scanner stops one before
//			for (i = 1; i < position; i++) {
//				scanner = scanner->next;
//			}
//			// Allocate memory for new Node
//			SinglyLinkedNode *sln = getCSinglyLinkedNode(value);
//			sln->next = scanner->next;
//			scanner->next = sln;
//		}
//		(sll->length)++;
//		resetTail(sll);
//		return 0; // OK
//	}
//	return 1; // List not initialized or locked
//}
//
//int insertTailSLL(SinglyLinkedList **SinglyLinkedList, int value)
//{
//	SinglyLinkedList *sll = *SinglyLinkedList;
//	if (sll->initialized) {
//		SinglyLinkedNode *sln = getCSinglyLinkedNode(value);
//		// Careful with head == NULL
//		if (sll->head == NULL) {
//			sll->head = sln; // OK
//		}
//		else {
//			(sll->tail)->next = sln;
//		}
//		(sll->length)++;
//		resetTail(sll);
//		return 0; // OK
//	}
//	return 1; // List not initialized or locked
//}
//
//int insertNodeSLL(SinglyLinkedList **SinglyLinkedList, SinglyLinkedNode *node, int position)
//{
//	SinglyLinkedList *sll = *SinglyLinkedList;
//	if (sll->initialized) {
//		// [0, size]
//		if (position < 0 || position > sll->length) return 2; // Invalid Position
//		if (sll->head == NULL) {
//			// Insert at head
//			// TODO
//			//
//		}
//		else if (position == 0) {
//			// Insert at head
//			// TODO
//			//
//		}
//		else if (position == sll->length) {
//			// Insert at tail
//			// TODO
//			//
//		}
//		else {
//			// Insert at middle
//			// TODO
//			//
//		}
//	}
//	return 1; // List not initialized or locked
//}
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                             Removal                                             |
//// +-------------------------------------------------------------------------------------------------+
//
///* REMOVE
// *
// * Interval [0, size)
// * Assuming lists starts at the zeroth (0) position.
// *
// * There are three cases:
// *
// * Always:
// *     Check if structure was initialized. Initialization is obligatory!
// *     Check if head == null or if size == 0. If yes, list is empty.
// *
// * Remove head:
// *     Get reference to head
// *     Reposition head = head->next
// *     Remove reference to head
// *
// * Remove tail:
// *     Go to one before tail
// *     Remove next node
// *     Reposition tail ()
// *
// * Remove middle:
// *     Position has to be smaller then size
// *         Because lists also start with 0!
// *     if (position == 0) - Insert at head
// *     if (position == size - 1) - Insert at tail
// *     else - Remove middle with (possibly?) double pointer
// *         - interval [0 , size)
// *         - Position tmp pointer one before chosen node
// *         - tmp->next = (tmp->next)->next // Skipps node to be removed
// *     Reposition tail
// *
// */
//
//int removeHeadSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->initialized) {
//		if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
//		SinglyLinkedNode *kill = (*SinglyLinkedList)->head;
//		(*SinglyLinkedList)->head = (*SinglyLinkedList)->head->next;
//		free(kill);
//		((*SinglyLinkedList)->length)--;
//		// resetTail(sll);
//		return 0;
//	}
//	return 1; // List not initialized or locked
//}
//
//int removeMiddleSLL(SinglyLinkedList **SinglyLinkedList, int position)
//{
//	if ((*SinglyLinkedList)->initialized) {
//		// [0, size)
//		if (position < 0 || position >(*SinglyLinkedList)->length - 1)
//			return 2; // Invalid position
//		if ((*SinglyLinkedList)->head == NULL)
//			return 3; // List is empty
//		if ((*SinglyLinkedList)->head->next == NULL || position == 0) {
//			// OK
//			removeHeadSLL(SinglyLinkedList);
//		}
//		else if (position == (*SinglyLinkedList)->length - 1) {
//			// OK
//			removeTailSLL(SinglyLinkedList);
//		}
//		else {
//			SinglyLinkedNode *previous = (*SinglyLinkedList)->head;
//			SinglyLinkedNode *after = (*SinglyLinkedList)->head->next;
//			int i;
//			// i = 1 to stop one before the node to be deleted
//			for (i = 1; i < position ; i++) {
//				previous = after;
//				after = after->next;
//			}
//			// Skip node to be removed
//			previous->next = after->next;
//			free(after);
//		}
//		((*SinglyLinkedList)->length)--;
//		resetTail((*SinglyLinkedList));
//	}
//	return 1; // List not initialized or locked
//}
//
//int removeTailSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->initialized) {
//		if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
//		if ((*SinglyLinkedList)->head->next == NULL) {
//			// Only one node to be removed. Use removeHeadSLL()
//			// to better handle the situation
//			removeHeadSLL(SinglyLinkedList);
//			return 0; // OK
//		}
//		else {
//			SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//			while (scanner->next->next != NULL)
//			{
//				scanner = scanner->next;
//			}
//			SinglyLinkedNode *kill = scanner->next;
//			scanner->next = NULL;
//			free(kill);
//		}
//		((*SinglyLinkedList)->length)--;
//		resetTail((*SinglyLinkedList));
//		return 0; // OK
//	}
//	return 1; // List not initialized or locked
//}
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                             Display                                             |
//// +-------------------------------------------------------------------------------------------------+
//
//int displayListSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->initialized) {
//		if ((*SinglyLinkedList)->head != NULL) {
//			// Get reference of first node
//			SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//			printf("\nC Singly Linked List\n");
//			while (scanner != NULL)
//			{
//				printf("%d -> ", scanner->data);
//				scanner = scanner->next;
//			}
//			printf("NULL\n");
//			return 0; // OK
//		}
//		printf("\nC Singly Linked List\n[ EMPTY ]\n");
//		return 2; // List is empty
//	}
//	return 1; // List not initialized or locked
//}
//
//int displayRawListSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->initialized) {
//		if ((*SinglyLinkedList)->head != NULL) {
//			// Get reference of first node
//			SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//			printf("\n");
//			while (scanner != NULL)
//			{
//				printf("%d ", scanner->data);
//				scanner = scanner->next;
//			}
//			return 0; // OK
//		}
//		printf("\n[ EMPTY ]\n");
//		return 2; // List is empty
//	}
//	return 1; // List not initialized or locked
//}
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                             Resets                                              |
//// +-------------------------------------------------------------------------------------------------+
//
//void resetTail(SinglyLinkedList *SinglyLinkedList)
//{
//	SinglyLinkedList->tail = SinglyLinkedList->head;
//	if (SinglyLinkedList->tail != NULL) {
//		while (SinglyLinkedList->tail->next != NULL)
//		{
//			SinglyLinkedList->tail = SinglyLinkedList->tail->next;
//		}
//	}
//}
//
//int deleteListSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	SinglyLinkedNode *kill;
//	(*SinglyLinkedList)->tail = (*SinglyLinkedList)->head;
//	while ((*SinglyLinkedList)->tail != NULL)
//	{
//		// Free memory from heap
//		kill = (*SinglyLinkedList)->tail;
//		(*SinglyLinkedList)->tail = (*SinglyLinkedList)->tail->next;
//		free(kill);
//	}
//	// If user wishes to use the list again
//	initListSLL(SinglyLinkedList);
//	return -1; // List erased
//}
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                             Search                                              |
//// +-------------------------------------------------------------------------------------------------+
//
//int frequencyCountSLL(SinglyLinkedList **SinglyLinkedList, int value)
//{
//	SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//	if ((*SinglyLinkedList)->head == NULL) return 0;
//	int count = 0;
//	while (scanner != NULL)
//	{
//		if (scanner->data == value) count++;
//		scanner = scanner->next;
//	}
//	return count;
//}
//
//bool containsValueSLL(SinglyLinkedList **SinglyLinkedList, int value)
//{
//	SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//	if ((*SinglyLinkedList)->head == NULL) return false;
//	while (scanner != NULL)
//	{
//		if (scanner->data == value) return true;
//		scanner = scanner->next;
//	}
//	return false;
//}
//
//int findMin(SinglyLinkedList **SinglyLinkedList)
//{
//	SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//	if (scanner == NULL) return 3; // List is empty
//	int min = scanner->data;
//	while (scanner != NULL)
//	{
//		if (scanner->data < min) min = scanner->data;
//		scanner = scanner->next;
//	}
//	return min;
//}
//
//int findMax(SinglyLinkedList **SinglyLinkedList)
//{
//	SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//	if (scanner == NULL) return 3; // List is empty
//	int max = scanner->data;
//	while (scanner != NULL)
//	{
//		if (scanner->data > max) max = scanner->data;
//		scanner = scanner->next;
//	}
//	return max;
//}
//
//// TODO Get array with positions of matched values
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                             Copy                                                |
//// +-------------------------------------------------------------------------------------------------+
//
//SinglyLinkedList * copyCSinglyLinkedList(SinglyLinkedList **SinglyLinkedList)
//{
//	SinglyLinkedList *sll = *SinglyLinkedList;
//	SinglyLinkedList *newList = getCSinglyLinkedList();
//	int i;
//	for (i = 0; i < (*SinglyLinkedList)->length; i++) {
//		insertTailSLL(&newList, getNodeValueSLL(&(*SinglyLinkedList), i));
//	}
//	return newList;
//}
//
//SinglyLinkedNode * copyCSinglyLinkedNode(SinglyLinkedNode *node)
//{
//	return getCSinglyLinkedNode(node->data);
//}
//
//// +-------------------------------------------------------------------------------------------------+
//// |                                           Sorting                                               |
//// +-------------------------------------------------------------------------------------------------+
//
//int reverseListSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->length == 0) return 3; // List is empty
//	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
//	SinglyLinkedNode *prev = NULL;
//	SinglyLinkedNode *curr = (*SinglyLinkedList)->head;
//	SinglyLinkedNode * next = NULL;
//	while (curr != NULL) {
//		next = curr->next;
//		curr->next = prev;
//		prev = curr;
//		curr = next;
//	}
//	(*SinglyLinkedList)->head = prev;
//	return 0;
//}
//
//int switchNodesSLL(SinglyLinkedList **SinglyLinkedList, int position1, int position2)
//{
//	if (position1 < 0 || position2 < 0
//		|| position1 >= (*SinglyLinkedList)->length
//		|| position2 >= (*SinglyLinkedList)->length)
//		return 2; // Invalid Position
//	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
//	if (position1 == position2) return 2; // Invalid Position
//	int i;
//	SinglyLinkedNode *beforeNode1 = (*SinglyLinkedList)->head;
//	SinglyLinkedNode *beforeNode2 = (*SinglyLinkedList)->head;
//	// Since nodes are already pointing to position 0 :
//	// TODO Special case for position == 0
//	// TODO Special case for position == size - 1 (last position)
//	//
//	//
//	if (position1 != 0) {
//		for (i = 0; i < position1 - 1; i++) {
//			beforeNode1 = beforeNode1->next;
//		}
//	}
//	if (position2 != 0) {
//		for (i = 0; i < position2 - 1; i++) {
//			beforeNode2 = beforeNode2->next;
//		}
//	}
//	return 0;
//}
//
//int switchNodeWithHead(SinglyLinkedList **SinglyLinkedList, int position)
//{
//	// TODO Switch node at position with first node
//	//
//	//
//}
//
//int switchNodeWithTail(SinglyLinkedList **SinglyLinkedList, int position)
//{
//	// TODO Switch node at position with first node
//	//
//	//
//}
//
//int switchNodeHeadTail(SinglyLinkedList **SinglyLinkedList)
//{
//	// TODO Switch head node with tail node
//}
//
//int bubbleSortSLL(SinglyLinkedList **SinglyLinkedList)
//{
//	if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
//	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
//	SinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
//	int i = 0;
//	while (scanner != NULL)
//	{
//		// TODO Switch function
//		//
//		//
//		scanner = scanner->next;
//	}
//}
//
//// SelectionSort
//// InsertionSort