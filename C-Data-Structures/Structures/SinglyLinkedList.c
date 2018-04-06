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

#include "..\Headers\SinglyLinkedList.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Initializes a new @c SinglyLinkedList.
 *
 * This functions uses malloc to allocate a new @c SinglyLinkedList, assigns
 * @c length to 0 and then points @c *head and @c *tail pointers to @c NULL
 * if the allocation fails @c DS_ERR_ALLOC is returned
 *
 * @param[out] sll Reference to an empty list
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @see sll_get_list()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *sll;
 * sll_init_list(&sll);
 * @endcode
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
 * @brief Initializes a new @c SinglyLinkedNode.
 *
 * This function uses malloc to allocate a new @c SinglyLinkedNode, if the
 * allocation fails @c DS_ERR_ALLOC is returned.
 *
 * @param[out] sln Reference to an empty node
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @see sll_get_node()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedNode *sln;
 * sll_init_node(&sln);
 * @endcode
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
 * @brief Initializes a new @c SinglyLinkedList and returns it as a result.
 *
 * This functions uses malloc to allocate a new @c SinglyLinkedList, sets
 * @c length to 0 and points @c head and @c tail to @c NULL, and finally
 * returns the new List.
 *
 * @return Returns a new @c SinglyLinkedList with length of 0.
 *
 * @see sll_init_list()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *sll = sll_get_list();
 * @endcode
 *
 * @note Avoid using this function as it does not return a status code and
 * does not check for failures. Give preference to @c sll_init_list().
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
 * @brief Initializes a new @c SinglyLinkedNode and returns it as a
 * result.
 *
 * This function uses malloc to allocate a new @c SinglyLinkedNode, sets Node
 * @c data to the value parameter, its @c *next pointer to @c NULL and finally
 * returns the new Node.
 *
 * @param[in] value Node value
 *
 * @return Returns a new @c SinglyLinkedNode with data of given parameter
 *
 * @see sll_init_node()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedNode *sln = sll_get_node();
 * @endcode
 *
 * @note Avoid using this function as it does not return a @c Status code and
 * does not check for failures. Give preference to @c sll_init_node() or
 * @c sll_make_node().
*/
SinglyLinkedNode * sll_get_node(int value)
{
	SinglyLinkedNode *sln = malloc(sizeof(SinglyLinkedNode));

	sln->data = value;
	sln->next = NULL;

	return sln;
}

/**
 * @brief Initializes a new @c SinglyLinkedNode with a value
 *
 * This function allows you to make a @c SinglyLinkedNode by passing
 * its value as a parameter
 *
 * @param[out] sln Pointer to new Node 
 * @param[in] value New Node value
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @see sll_init_node()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedNode *sln;
 * sll_make_node(10, &sln); // Makes a node with value of 10
 * @endcode
 */
Status sll_make_node(SinglyLinkedNode **sln, int value)
{
	*sln = malloc(sizeof(SinglyLinkedNode));

	if (!sln)
		return DS_ERR_ALLOC;

	(*sln)->next = NULL;
	(*sln)->data = value;

	return DS_OK;
}

/**
 * @brief Get SinglyLinkedList length
 *
 * This function
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] length Length of specified Singly Linked List
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced list points
 * to NULL
 * @return @c DS_ERR_UNEXPECTED_RESULT if lengths don't match
 *
 * @warning Do not pass length parameter as an integer or your program won't
 * finish correctly.
 */
Status sll_get_length(SinglyLinkedList *sll, size_t *length)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *scanner = sll->head;

	*length = 0;

	while (scanner != NULL)
	{
		scanner = scanner->next;
		(*length)++;
	}

	if ((*length) != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

/**
 * @brief Get a specific @c SinglyLinkedNode data
 *
 * This function searches for a Node at given position and then assigns it to
 * the result variable.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] position Node relative position to the first element of the list
 * @param[out] result Node value
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced list points
 * to NULL
 * @return @c DS_ERR_INVALID_OPERATION if list length is 0
 * @return @c DS_ERR_ITER if a variable points to NULL during
 * iteration
 *
 * @warning Do not pass position parameter as an integer or your program won't
 * finish correctly.
 */
Status sll_get_node_data(SinglyLinkedList *sll, size_t position, int *result)
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


// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

/* INSERT
 *
 * Interval [0, size]
 * Assuming lists starts at the zeroth (0) position.
 *
 * There are three cases:
 *
 * Always:
 *     Check if structure was initialized. Initialization is obligatory!
 *
 * Insert head:
 *     Node->next = head
 *     Reposition head to new Node
 *
 * Insert tail:
 *     Insert new Node to tail->next
 *     Reposition tail to new Node
 *
 * Insert middle:
 *     Position can be the same as the size
 *     This allows you to insert at the last non-existing (yet) position
 *     if (position == 0) - Insert at head
 *     if (position == size) - Insert at tail
 *     else  Insert middle
 *         - interval [0 , size]
 *         - Position tmp pointer one before chosen node
 *         - new Node->next = tmp->next
 *         - tmp->next = new Node
 *     reposition tail
 *
 */

/**
 * @brief Inserts new @c SinglyLinkedNode at the first position.
 * 
 * This function inserts a @c SinglyLinkedNode that is initialized inside the
 * function. Its value is assigned and then he is added to the list. Its
 * @c *next pointer points to the first element of the list and then the
 * @c *head pointer is repositioned to this newly added node. If it is the
 * first node, @c *tail pointer is also points to it.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] value Value to be inserted in the node
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_OPERATION_FAILED if any external functions failed
 * @return @c DS_ERR_ALLOC if allocation failed
 */
Status sll_insert_head(SinglyLinkedList *sll, int value)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *sln;

	if (sll_init_node(&sln) != DS_OK)
		return DS_ERR_OPERATION_FAILED;

	if (!sln)
		return DS_ERR_ALLOC;
	
	sln->data = value;

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

/**
* @brief Inserts new @c SinglyLinkedNode at chosen position.
*
* This function inserts a @c SinglyLinkedNode that is initialized inside the
* function. Its value is assigned and then he is added to the list. Its
* @c *next pointer points to the first element of the list and then the
* @c *head pointer is repositioned to this newly added node. If it is the
* first node, @c *tail pointer is also points to it.
*
* @param[in] sll Reference to a @c SinglyLinkedList
* @param[in] value Value to be inserted in the node
* @param[in] position Relative position to the first element of the list where
* new @c SinglyLinkedNode will be inserted
*
* @return @c DS_OK if all operations were successful
* @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
* @return @c DS_ERR_INVALID_POSITION if position is out of range
* @return @c DS_ERR_OPERATION_FAILED if any external functions failed
* @return @c DS_ERR_ALLOC if allocation failed
*
* @warning Do not pass position parameter as an integer or your program won't
* finish correctly.
*/
Status sll_insert_at(SinglyLinkedList *sll, int value, size_t position)
{
	if (sll == NULL || position == NULL)
		return DS_ERR_NULL_POINTER;

	if (position > sll->length)
		return DS_ERR_INVALID_POSITION;

	SinglyLinkedNode *sln;

	if (sll_init_node(&sln) != DS_OK)
		return DS_ERR_OPERATION_FAILED;

	if (!sln)
		return DS_ERR_ALLOC;

	if (position == 0) {

		Status st = sll_insert_head(sll, value);
		if (st != DS_OK)
			return st;

	}
	else if (position == sll->length) {

		Status st = sll_insert_tail(sll, value);
		if (st != DS_OK)
			return st;

	}
	else {

		SinglyLinkedNode *curr = sll->head;

		int i;
		for (i = 1; i < position; i++) {

			if (curr == NULL)
				return DS_ERR_ITER;

			curr = curr->next;

		}

		sln->data = value;

		sln->next = curr->next;
		curr->next = sln;

	}

	(sll->length)++;

	return DS_OK;
}


/**
 * @brief Inserts new @c SinglyLinkedNode at the last position.
 *
 * This function inserts a @c SinglyLinkedNode that is initialized
 * inside the function. Its value is assigned and then the node is added to the
 * end of the list. Its @c *next pointer points to @c NULL (no Node after it)
 * and then the @c *head pointer is repositioned to this newly added node. If
 * it is the first node, the @c sll_insert_head() function is
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] value Value to be inserted in the node
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_OPERATION_FAILED if any external functions failed
 * @return @c DS_ERR_ALLOC if allocation faileds
 */
Status sll_insert_tail(SinglyLinkedList *sll, int value)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *sln;

	if (sll_init_node(&sln) != DS_OK)
		return DS_ERR_OPERATION_FAILED;

	if (!sln)
		return DS_ERR_ALLOC;

	sln->data = value;

	if (sll->head == NULL) {

		sll->head = sln;
		sll->tail = sln;

	}
	else {

		sll->tail->next = sln;
		sll->tail = sll->tail->next;

	}

	(sll->length)++;

	return DS_OK;
}

// Insert newly made SinglyLinkedNode to list

//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node);
//Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node, size_t position);
//Status sll_insert_node_tail(SinglyLinkedList *sll, SinglyLinkedNode *node);

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

/* REMOVE
 *
 * Interval [0, size)
 * Assuming lists starts at the zeroth (0) position.
 *
 * There are three cases:
 *
 * Always:
 *     Check if structure was initialized. Initialization is obligatory!
 *     Check if head == null or if size == 0. If yes, list is empty.
 *
 * Remove head:
 *     Get reference to head
 *     Reposition head = head->next
 *     Remove reference to head
 *
 * Remove tail:
 *     Go to one before tail
 *     Remove next node
 *     Reposition tail ()
 *
 * Remove middle:
 *     Position has to be smaller then size
 *         Because lists also start with 0!
 *     if (position == 0) - Insert at head
 *     if (position == size - 1) - Insert at tail
 *     else - Remove middle with (possibly?) double pointer
 *         - interval [0 , size)
 *         - Position tmp pointer one before chosen node
 *         - tmp->next = (tmp->next)->next // Skipps node to be removed
 *     Reposition tail
 *
 */

 /**
  * @brief Removes first @c SinglyLinkedNode from the list.
  *
  * This function removes the first @c SinglyLinkedNode from the list. If the
  * list is empty, @c DS_ERR_INVALID_OPERATION is returned.
  *
  * @param[in] sll Reference to a @c SinglyLinkedList
  *
  * @return @c DS_OK if all operations were successful
  * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
  * @return @c DS_ERR_INVALID_OPERATION if list is empty
  */
Status sll_remove_head(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *sln = sll->head;
	
	sll->head = sll->head->next;

	if (sll->head == NULL)
		sll->tail == NULL;

	free(sln);

	(sll->length)--;
	
	return DS_OK;
}

/**
 * @brief Removes a @c SinglyLinkedNode from the list at a chosen position.
 *
 * This function removes a chosen @c SinglyLinkedNode from the list at a
 * position relative to the head of the list If the list is empty, @c
 * DS_ERR_INVALID_OPERATION is returned.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] position Relative position to the first element of the list where
 * a @c SinglyLinkedNode will be removed
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_OPERATION_FAILED if any external functions failed
 * @return @c DS_ERR_ALLOC if allocation faileds
 */
Status sll_remove_at(SinglyLinkedList *sll, size_t position)
{
	if (sll == NULL || position == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	if (position == 0) {

		Status st = sll_remove_head(sll);
		if (st != DS_OK)
			return st;

	}
	else if (position == sll->length - 1) {

		Status st = sll_remove_tail(sll);
		if (st != DS_OK)
			return st;

	}
	else {

		SinglyLinkedNode *prev = NULL;
		SinglyLinkedNode *curr = sll->head;

		int i;
		for (i = 1; i < position; i++) {

			if (curr == NULL)
				return DS_ERR_ITER;

			prev = curr;
			curr = curr->next;

		}

		prev->next = curr->next;
		free(curr);
	}

	(sll->length)--;

	return DS_OK;
}

/**
 * @brief Removes last @c SinglyLinkedNode from the list.
 *
 * This function removes the last @c SinglyLinkedNode from the list. If the
 * list is empty, @c DS_ERR_INVALID_OPERATION is returned.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] position Relative position to the first element of the list where
 * a @c SinglyLinkedNode will be removed
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 */
Status sll_remove_tail(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *prev = NULL;
	SinglyLinkedNode *curr = sll->head;

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	
	if (prev == NULL) {

		free(curr);
		sll->head = NULL;
		sll->tail = NULL;

	}
	else {

		prev->next = NULL;
		sll->tail = prev;
		free(curr);

	}

	(sll->length)--;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status sll_display(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL) {

		printf("\nSingly Linked List\n[ empty ]\n");
		return DS_OK;

	}

	SinglyLinkedNode *scan = sll->head;

	printf("\nSingly Linked List\n");

	while (scan != NULL)
	{
		printf(" %d ->", scan->data);
		scan = scan->next;
	}

	printf(" NULL\n");

	return DS_OK;
}

Status sll_display_raw(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *scan = sll->head;

	printf("\n");

	while (scan != NULL)
	{
		printf("%d ", scan->data);
		scan = scan->next;
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status sll_delete_list(SinglyLinkedList **sll)
{
	if ((*sll) == NULL)
		return DS_ERR_NULL_POINTER;
	
	SinglyLinkedNode *prev = (*sll)->head;

	while ((*sll)->head != NULL)
	{
		(*sll)->head = (*sll)->head->next;
		free(prev);
		prev = (*sll)->head;
	}

	free((*sll));

	(*sll) = NULL;

	return DS_OK;
}

Status sll_erase_list(SinglyLinkedList **sll)
{
	if ((*sll) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = sll_delete_list(sll);
	
	if (st != DS_OK)
		return st;

	st = sll_init_list(sll);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status sll_frequency(SinglyLinkedList *sll, int key, size_t *frequency)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;
	
	SinglyLinkedNode *scan = sll->head;

	*frequency = 0;

	while (scan != NULL)
	{
		if (scan->data == key)
			(*frequency)++;

		scan = scan->next;
	}
	
	return DS_OK;
}

Status sll_contains(SinglyLinkedList *sll, int key, bool *result)
{
	*result = false;

	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length == 0 || sll->head == NULL)
		return DS_ERR_NOT_FOUND;

	SinglyLinkedNode *scan = sll->head;

	while (scan != NULL)
	{
		if (scan->data == key) {

			result = true;
			break;

		}

		scan = scan->next;
	}
	
	return DS_OK;
}

bool sll_exists(SinglyLinkedList *sll, int key)
{
	if (sll == NULL)
		return 0;

	if (sll->length == 0 || sll->head == NULL)
		return 0;

	SinglyLinkedNode *scan = sll->head;

	while (scan != NULL)
	{
		if (scan->data == key)
			return true;

		scan = scan->next;
	}

	return false;
}

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