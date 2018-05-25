/**
 * @file SinglyLinkedList.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/03/2018
 *
 * @brief Source file for @c SinglyLinkedList implementations in C
 *
 * Singly Linked List are linear structures...
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

	if (!(*sll))
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
 * @param[out] node Reference to an empty node
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @see sll_get_node()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedNode *node;
 * sll_init_node(&node);
 * @endcode
 */
Status sll_init_node(SinglyLinkedNode **node)
{
	(*node) = malloc(sizeof(SinglyLinkedNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = 0;
	(*node)->next = NULL;

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
 * SinglyLinkedNode *node = sll_get_node(12);
 * @endcode
 *
 * @note Avoid using this function as it does not return a @c Status code and
 * does not check for failures. Give preference to @c sll_init_node() or
 * @c sll_make_node().
*/
SinglyLinkedNode * sll_get_node(int value)
{
	SinglyLinkedNode *node = malloc(sizeof(SinglyLinkedNode));

	node->data = value;
	node->next = NULL;

	return node;
}

/**
 * @brief Initializes a new @c SinglyLinkedNode with a value
 *
 * This function allows you to make a @c SinglyLinkedNode by passing
 * its value as a parameter
 *
 * @param[out] node Pointer to new Node 
 * @param[in] value New Node value
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @see sll_init_node()
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedNode *node;
 * sll_make_node(&node, 10); // Makes a node with value of 10
 * @endcode
 */
Status sll_make_node(SinglyLinkedNode **node, int value)
{
	(*node) = malloc(sizeof(SinglyLinkedNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->next = NULL;
	(*node)->data = value;

	return DS_OK;
}

/**
 * @brief Get @c SinglyLinkedList length
 *
 * This function
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] result Length of specified Singly Linked List
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced list points to NULL
 * @return @c DS_ERR_UNEXPECTED_RESULT if lengths don't match
 *
 * @warning Do not pass length parameter as an integer or your program won't
 * finish correctly.
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * size_t len;
 * sll_init_list(&list);
 *
 * sll_insert_head(list, 12);
 *
 * sll_get_length(list, &len); // Variable len has length of the list
 *
 * @endcode
 */
Status sll_get_length(SinglyLinkedList *sll, size_t *result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *scanner = sll->head;

	*result = 0;

	while (scanner != NULL)
	{
		scanner = scanner->next;
		(*result)++;
	}

	if ((*result) != sll->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                              Node                                               |
// +-------------------------------------------------------------------------------------------------+

/**
 * @brief Gets a reference of a Node at specific position in the list
 *
 * This function retrieves a references of a @c SinglyLinkedNode at a specific
 * position in the list
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] result Resulting node
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced list points to NULL
 * @return @c DS_ERR_ITER if a variable points to NULL during iteration
 *
 * @warning 
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * size_t len;
 * sll_init_list(&list);
 *
 * sll_insert_head(list, 12);
 *
 * sll_get_length(list, &len); // Variable len has length of the list
 *
 * @endcode
 */
Status sll_get_node_at(SinglyLinkedList *sll, SinglyLinkedNode **result, size_t position)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	(*result) = sll->head;

	size_t i;
	for (i = 0; i < position; i++) {

		if ((*result) == NULL)
			return DS_ERR_ITER;

		(*result) = (*result)->next;

	}

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
 * @return @c DS_ERR_ITER if a variable points to NULL during iteration
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * int i, result;
 * sll_init_list(&list);
 *
 * for (i = 10; i < 20; i++)
 *     sll_insert_head(list, i);
 *
 * sll_get_node_data(sll, 3, &result); // Result has value of 13
 * @endcode
 *
 * @warning Do not pass position parameter as an integer or your program won't
 * finish correctly.
 */
Status sll_get_node_data(SinglyLinkedList *sll, size_t position, int *result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
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

/**
 * @brief Updates a specific @c SinglyLinkedNode data
 *
 * This function searches for a Node at given position and then assigns its
 * data as the value parameter.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] position Node relative position to the first element of the list
 * @param[in] value New value for Node at specified position
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if referenced list points
 * to NULL
 * @return @c DS_ERR_INVALID_OPERATION if list length is 0
 * @return @c DS_ERR_ITER if a variable points to NULL during iteration
 * @return @c DS_ERR_INVALID_POSITION if position is higher than 
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * int i;
 * sll_init_list(&list);
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_head(list, i);
 *
 * sll_update_node_data(sll, 0, 12); // First position has now a value of 12
 * @endcode
 *
 * @warning Do not pass position parameter as an integer or your program won't
 * finish correctly.
 */
Status sll_update_node_data(SinglyLinkedList *sll, size_t position, int value)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	SinglyLinkedNode *curr = sll->head;

	int i;
	for (i = 0; i < position; i++) {

		if (curr == NULL)
			return  DS_ERR_ITER;

		curr = curr->next;
	}

	curr->data = value;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

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
 * @return @c DS_ERR_ALLOC if allocation failed
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 *
 * sll_insert_head(list, 4);
 * sll_insert_head(list, 5); // 5 -> 4 -> NULL
 * @endcode
 *
 */
Status sll_insert_head(SinglyLinkedList *sll, int value)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *node;

	Status st = sll_make_node(&node, value);

	if (st != DS_OK)
		return st;

	if (!node)
		return DS_ERR_ALLOC;

	if (sll_is_empty(sll)) {

		sll->head = node;
		sll->tail = node;

	}
	else {

		node->next = sll->head;
		sll->head = node;

	}

	(sll->length)++;

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
* @return @c DS_ERR_ALLOC if allocation failed
*
* @b Usage
* @code{.c}
* SinglyLinkedList *list;
* sll_init_list(&list);
*
* sll_insert_head(list, 5);
* sll_insert_head(list, 3);
*
* sll_insert_at(list, 4, 1); // 3 -> 4 -> 5 -> NULL
* @endcode
*
* @warning Do not pass position parameter as an integer or your program won't
* finish correctly.
*/
Status sll_insert_at(SinglyLinkedList *sll, int value, size_t position)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (position > sll->length)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (position == 0) {

		st = sll_insert_head(sll, value);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else if (position == sll->length) {

		st = sll_insert_tail(sll, value);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else {

		SinglyLinkedNode *node = NULL;

		st = sll_make_node(&node, value);

		if (st != DS_OK)
			return st;

		if (!node)
			return DS_ERR_ALLOC;
	
		SinglyLinkedNode *curr = NULL;
		
		st = sll_get_node_at(sll, &curr, position - 1);

		if (st != DS_OK)
			return st;

		node->next = curr->next;
		curr->next = node;

		(sll->length)++;

		return DS_OK;
	}
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
 * @return @c DS_ERR_ALLOC if allocation fails
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 *
 * sll_insert_tail(list, 1);
 * sll_insert_tail(list, 2); // 1 -> 2 -> NULL
 * @endcode
 *
 */
Status sll_insert_tail(SinglyLinkedList *sll, int value)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	SinglyLinkedNode *node;

	Status st = sll_make_node(&node, value);

	if (st != DS_OK)
		return st;

	if (!node)
		return DS_ERR_ALLOC;

	if (sll_is_empty(sll)) {

		sll->head = node;
		sll->tail = node;

	}
	else {

		sll->tail->next = node;
		sll->tail = node;

	}

	(sll->length)++;

	return DS_OK;
}

/**
 * @brief Pushes an already initialized @c SinglyLinkedNode at the first
 * position.
 *
 * This function pushes an already initialized @c SinglyLinkedNode to the first
 * position of the list. It can be used in conjunction with @c
 * sll_remove_node_head, @c sll_remove_node_at, @c sll_remove_node_tail to
 * pop an already created node and use it in this function.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] node Node to be inserted in the list
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 *
 * @b Usage
 * @code{.c}
 *
 * int i;
 * SinglyLinkedList *sll;
 * SinglyLinkedNode *node;
 *
 * sll_init_list(&sll);
 *
 * for (i = 0; i < 10; i++) {
 *     sll_make_node(&node, i);
 *     sll_insert_node_head(sll, node); // 9 -> 8 -> ... -> 2 -> 1 -> 0 -> NULL
 * }
 * @endcode
 */
Status sll_insert_node_head(SinglyLinkedList *sll, SinglyLinkedNode *node)
{
	if (sll == NULL || node == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll)) {

		sll->head = node;
		sll->tail = node;

		node->next = NULL;

	}
	else {

		node->next = sll->head;

		sll->head = node;

	}

	(sll->length)++;

	return DS_OK;
}

/**
 * @brief Pushes an already initialized @c SinglyLinkedNode at a chosen
 * position.
 *
 * This function pushes an already initialized @c SinglyLinkedNode at a chosen
 * position of the list relative to the first element. It can be used in
 * conjunction with @c sll_remove_node_head, @c sll_remove_node_at, @c
 * sll_remove_node_tail to pop an already created node and use it in this
 * function.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] node Node to be inserted in the list
 * @param[in] position Relative position to the first element of the list where
 * the Node will be inserted
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_INVALID_POSITION if position is out of range
 *
 * @b Usage
 * @code{.c}
 *
 * size_t i;
 * SinglyLinkedList *sll;
 * SinglyLinkedNode *node;
 *
 * sll_init_list(&sll);
 *
 * for (i = 0; i < 10; i++) {
 *     sll_make_node(&node, i);
 *     sll_insert_node_at(sll, node, i);
 * }
 *
 * @endcode
 */
Status sll_insert_node_at(SinglyLinkedList *sll, SinglyLinkedNode *node, size_t position)
{
	if (sll == NULL || node == NULL)
		return DS_ERR_NULL_POINTER;

	if (position > sll->length)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (position == 0) {

		st = sll_insert_node_head(sll, node);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else if (position == sll->length) {

		st = sll_insert_node_tail(sll, node);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else {

		SinglyLinkedNode *curr = NULL;

		st = sll_get_node_at(sll, &curr, position - 1);

		if (st != DS_OK)
			return DS_OK;

		node->next = curr->next;
		curr->next = node;

		(sll->length)++;

		return DS_OK;
	}
}

/**
 * @brief Pushes an already initialized @c SinglyLinkedNode at the last
 * position.
 *
 * This function pushes an already initialized @c SinglyLinkedNode to the last
 * position of the list. It can be used in conjunction with @c
 * sll_remove_node_head, @c sll_remove_node_at, @c sll_remove_node_tail to pop
 * an already created node and use it in this function.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] node Node to be inserted in the list
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 *
 * @b Usage
 * @code{.c}
 *
 * int i;
 * SinglyLinkedList *sll;
 * SinglyLinkedNode *node;
 *
 * sll_init_list(&sll);
 *
 * for (i = 0; i < 10; i++) {
 *     sll_make_node(&node, i);
 *     sll_insert_node_tail(sll, node); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 * }
 *
 * @endcode
 */
Status sll_insert_node_tail(SinglyLinkedList *sll, SinglyLinkedNode *node)
{
	if (sll == NULL || node == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll)) {

		sll->head = node;
		sll->tail = node;

	}
	else {

		sll->tail->next = node;
		sll->tail = node;

	}

	(sll->length)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

 /**
  * @brief Removes first @c SinglyLinkedNode from the list.
  *
  * This function removes the first @c SinglyLinkedNode from the list and frees
  * it from memory.
  *
  * @param[in] sll Reference to a @c SinglyLinkedList
  *
  * @return @c DS_OK if all operations were successful
  * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
  * @return @c DS_ERR_INVALID_OPERATION if list is empty
  *
  * @b Usage
  * @code{.c}
  * SinglyLinkedList *list;
  * sll_init_list(&list);
  * int i;
  *
  * for (i = 0; i < 10; i++)
  *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
  *
  * sll_remove_head(list); // 1 -> 2 -> 3 -> ... -> 8 -> 9 -> NULL
  *
  * @endcode
  */
Status sll_remove_head(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *node = sll->head;
	
	sll->head = sll->head->next;

	sll_delete_node(&node);

	(sll->length)--;

	if (sll_is_empty(sll)) {
		
		sll->head = NULL;
		sll->tail = NULL;

	}
	
	return DS_OK;
}

/**
 * @brief Removes a @c SinglyLinkedNode from the list at a chosen position.
 *
 * This function removes a chosen @c SinglyLinkedNode from the list at a
 * position relative to the head of the list and frees it from memory.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[in] position Relative position to the first element of the list where
 * a @c SinglyLinkedNode will be removed
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if list reference is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 * @return @c DS_ERR_INVALID_POSITION if position is out of range
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 * int i;
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 *
 * sll_remove_at(list, 2); // 0 -> 1 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL
 * sll_remove_at(list, 7); // 0 -> 1 -> 3 -> 4 -> 5 -> 6 -> 7 -> 9 -> NULL
 * sll_remove_at(list, 4); // 0 -> 1 -> 3 -> 4 -> 6 -> 7 -> 9 -> NULL
 *
 * @endcode
 */
Status sll_remove_at(SinglyLinkedList *sll, size_t position)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (position == 0) {

		st = sll_remove_head(sll);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else if (position == sll->length - 1) {

		st = sll_remove_tail(sll);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else {
	
		SinglyLinkedNode *prev = NULL;
		SinglyLinkedNode *curr = NULL;

		st = sll_get_node_at(sll, &prev, position - 1);

		if (st != DS_OK)
			return st;

		st = sll_get_node_at(sll, &curr, position);

		if (st != DS_OK)
			return st;
	
		prev->next = curr->next;
		sll_delete_node(&curr);
		
		(sll->length)--;

		if (sll_is_empty(sll)) {

			sll->head = NULL;
			sll->tail = NULL;

		}

		return DS_OK;
	}
}

/**
 * @brief Removes last @c SinglyLinkedNode from the list.
 *
 * This function removes the last @c SinglyLinkedNode from the list and frees
 * it from memory.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if any parameter is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 * int i;
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 *
 * sll_remove_tail(list); // 0 -> 1 -> 2 ... -> 6 -> 7 -> 8 -> NULL
 * sll_remove_tail(list); // 0 -> 1 -> 2 ... -> 5 -> 6 -> 7 -> NULL
 *
 * @endcode
 */
Status sll_remove_tail(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *prev = NULL;
	SinglyLinkedNode *curr = sll->head;

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	
	if (prev == NULL) {

		sll_delete_node(&curr);

		sll->head = NULL;
		sll->tail = NULL;

	}
	else {

		prev->next = NULL;
		sll->tail = prev;

		sll_delete_node(&curr);

	}

	(sll->length)--;

	if (sll_is_empty(sll)) {

		sll->head = NULL;
		sll->tail = NULL;

	}

	return DS_OK;
}

/**
 * @brief Pops the first @c SinglyLinkedNode from the list.
 *
 * This function pops the first @c SinglyLinkedNode from the list. It can be
 * used in conjunction with @c sll_insert_node_head, @c sll_insert_node_at, @c
 * sll_insert_node_tail to insert that node back into any other list.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] node Resulting node of the operation
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if list parameter is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 * int i;
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 *
 * SinglyLinkedNode *node;
 *
 * sll_remove_node_head(list, &node); // 1 -> 2 -> ... -> 8 -> 9 -> NULL
 * // Variable node has 0 as its data
 *
 * @endcode
 */
Status sll_remove_node_head(SinglyLinkedList *sll, SinglyLinkedNode **node)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	(*node) = sll->head;

	sll->head = sll->head->next;

	(*node)->next = NULL;

	(sll->length)--;

	if (sll_is_empty(sll)) {

		sll->head = NULL;
		sll->tail = NULL;

	}

	return DS_OK;
}

/**
 * @brief Pops a @c SinglyLinkedNode from a chosen position.
 *
 * This function pops a @c SinglyLinkedNode from a chosen position relative to
 * the first node on the list. It can beused in conjunction with @c
 * sll_insert_node_head, @c sll_insert_node_at, @c sll_insert_node_tail to
 * insert that node back into any other list.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] node Resulting node of the operation
 * @param[in] position Relative position to the first element of the list where
 * a @c SinglyLinkedNode will be popped out
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if list parameter is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 * @return @c DS_ERR_INVALID_POSITION if position is out of range
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 * int i;
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 *
 * SinglyLinkedNode *node;
 *
 * sll_remove_node_head(list, &node, 2); // 0 -> 1 -> 3 -> ... -> 8 -> 9 -> NULL
 * // Variable node has 2 as its data
 *
 * @endcode
 */
Status sll_remove_node_at(SinglyLinkedList *sll, SinglyLinkedNode **node, size_t position)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (position == 0) {

		st = sll_remove_node_head(sll, node);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else if (position == sll->length - 1) {

		st = sll_remove_node_tail(sll, node);

		if (st != DS_OK)
			return st;

		return DS_OK;
	}
	else {
	
		SinglyLinkedNode *prev = NULL;
		SinglyLinkedNode *curr = NULL;

		st = sll_get_node_at(sll, &prev, position - 1);

		if (st != DS_OK)
			return st;

		st = sll_get_node_at(sll, &curr, position);

		if (st != DS_OK)
			return st;
	
		prev->next = curr->next;

		(*node) = curr;
		(*node)->next = NULL;

		(sll->length)--;

		if (sll_is_empty(sll)) {

			sll->head = NULL;
			sll->tail = NULL;

		}

		return DS_OK;
	}
}

/**
 * @brief Pops the last @c SinglyLinkedNode from the list.
 *
 * This function pops the last @c SinglyLinkedNode from the list. It can be
 * used in conjunction with @c sll_insert_node_head, @c sll_insert_node_at, @c
 * sll_insert_node_tail to insert that node back into any other list.
 *
 * @param[in] sll Reference to a @c SinglyLinkedList
 * @param[out] node Resulting node of the operation
 *
 * @return @c DS_OK if all operations were successful
 * @return @c DS_ERR_NULL_POINTER if list parameter is @c NULL
 * @return @c DS_ERR_INVALID_OPERATION if list is empty
 *
 * @b Usage
 * @code{.c}
 * SinglyLinkedList *list;
 * sll_init_list(&list);
 * int i;
 *
 * for (i = 0; i < 10; i++)
 *     sll_insert_tail(list, i); // 0 -> 1 -> 2 -> ... -> 8 -> 9 -> NULL
 *
 * SinglyLinkedNode *node;
 *
 * sll_remove_node_tail(list, &node); // 0 -> 1 -> ... -> 7 -> 8 -> NULL
 * // Variable node has 9 as its data
 *
 * @endcode
 */
Status sll_remove_node_tail(SinglyLinkedList *sll, SinglyLinkedNode **node)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	SinglyLinkedNode *prev = NULL;
	SinglyLinkedNode *curr = sll->head;

	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL) {

		(*node) = curr;

		sll->head = NULL;
		sll->tail = NULL;

	}
	else {

		prev->next = NULL;
		sll->tail = prev;

		(*node) = curr;

	}

	(*node)->next = NULL;

	(sll->length)--;

	if (sll_is_empty(sll)) {

		sll->head = NULL;
		sll->tail = NULL;

	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status sll_display(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll)) {

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

	if (sll_is_empty(sll))
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

Status sll_delete_node(SinglyLinkedNode **node)
{
	free(*node);
	
	(*node) = NULL;

	return DS_OK;
}

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

	if (sll_is_empty(sll))
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

	if (sll_is_empty(sll))
		return DS_ERR_NOT_FOUND;

	SinglyLinkedNode *scan = sll->head;

	while (scan != NULL)
	{
		if (scan->data == key) {

			*result = true;
			break;

		}

		scan = scan->next;
	}
	
	return DS_OK;
}

bool sll_exists(SinglyLinkedList *sll, int key)
{
	if (sll == NULL)
		return false;

	if (sll_is_empty(sll))
		return false;

	SinglyLinkedNode *scan = sll->head;

	while (scan != NULL)
	{
		if (scan->data == key)
			return true;

		scan = scan->next;
	}

	return false;
}

bool sll_is_empty(SinglyLinkedList *sll)
{
	return (sll->length == 0 || sll->head == NULL);
}

Status sll_find_max(SinglyLinkedList *sll, int *result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;


	SinglyLinkedNode *scan = sll->head;

	int max = scan->data;
	while (scan != NULL)
	{
		if (scan->data > max)
			max = scan->data;

		scan = scan->next;
	}

	*result = max;

	return DS_OK;
}

Status sll_find_min(SinglyLinkedList *sll, int *result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;


	SinglyLinkedNode *scan = sll->head;

	int min = scan->data;
	while (scan != NULL)
	{
		if (scan->data < min)
			min = scan->data;

		scan = scan->next;
	}

	*result = min;

	return DS_OK;
}

Status sll_occurrance_list(SinglyLinkedList *sll, SinglyLinkedList **result, int key)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	Status st = sll_init_list(result);
	
	if (st != DS_OK)
		return st;

	SinglyLinkedNode *scan = sll->head;

	int data;
	size_t i = 0;

	while (scan != NULL)
	{
		sll_get_node_data(sll, i, &data);

		if (data == key) {

			st = sll_insert_tail((*result), (int) i); // Issue : size_t can be bigger than int

			if (st != DS_OK)
				return st;

		}

		scan = scan->next;

		i++;

	}

	return DS_OK;
}

Status sll_find_occurrance_first(SinglyLinkedList *sll, int key, size_t *position)
{
	*position = 0;

	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_NOT_FOUND;

	SinglyLinkedNode *scan = sll->head;

	while (scan != NULL)
	{
		if (scan->data == key)
			return DS_OK;

		(*position)++;

		scan = scan->next;

	}

	return DS_ERR_NOT_FOUND;
}

Status sll_find_occurrance_last(SinglyLinkedList *sll, int key, size_t *position)
{
	*position = 0;

	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_NOT_FOUND;

	SinglyLinkedNode *scan = sll->head;

	bool found = false;

	size_t iter = 0;

	while (scan != NULL)
	{
		if (scan->data == key) {
			found = true;
			*position = iter;
		}
		
		iter++;

		scan = scan->next;

	}

	if (found)
		return DS_OK;

	return DS_ERR_NOT_FOUND;
}

// +-------------------------------------------------------------------------------------------------+
// |                                         Slice / Link                                            |
// +-------------------------------------------------------------------------------------------------+

Status sll_link(SinglyLinkedList *sll1, SinglyLinkedList *sll2)
{
	if (sll1 == NULL || sll2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll2))
		return DS_ERR_INVALID_OPERATION;

	if (sll_is_empty(sll1)) {

		sll1->head = sll2->head;
		sll1->tail = sll2->tail;

		sll1->length = sll2->length;

	}
	else {

		sll1->tail->next = sll2->head;
		sll1->tail = sll2->tail;

		sll1->length += sll2->length;

	}

	sll2->head = NULL;
	sll2->tail = NULL;

	sll2->length = 0;

	return DS_OK;
}

Status sll_link_at(SinglyLinkedList *sll1, SinglyLinkedList *sll2, size_t position)
{
	if (sll1 == NULL || sll2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (position > sll1->length)
		return DS_ERR_INVALID_POSITION;

	if (sll_is_empty(sll1) || sll_is_empty(sll2))
		return DS_ERR_INVALID_OPERATION;

	if (position == 0) {

		sll2->tail->next = sll1->head;

		sll1->head = sll2->head;

	}
	else if (position == sll1->length) {

		sll1->tail->next = sll2->head;
		sll1->tail = sll2->tail;

	}
	else {

		SinglyLinkedNode *before;

		sll_get_node_at(sll1, &before, position - 1);

		sll2->tail->next = before->next;

		before->next = sll2->head;

	}

	sll2->head = NULL;
	sll2->tail = NULL;

	sll1->length += sll2->length;
	sll2->length = 0;

	return DS_OK;
}

Status sll_unlink(SinglyLinkedList *sll, SinglyLinkedList *result, size_t position)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (!sll_is_empty(result))
		return DS_ERR_INVALID_OPERATION;

	if (position >= sll->length)
		return DS_ERR_INVALID_POSITION;

	Status st;

	size_t len;
	st = sll_get_length(sll, &len);

	if (st != DS_OK)
		return st;

	if (position == 0) {

		result->head = sll->head;
		result->tail = sll->tail;

		result->length = sll->length;

		result->tail = NULL;
		result->head = NULL;

	}
	else {

		SinglyLinkedNode *before;

		st = sll_get_node_at(sll, &before, position - 1);

		if (st != DS_OK)
			return st;

		result->head = before->next;
		result->tail = sll->tail;

		sll->tail = before;

		before->next = NULL;

	}
	
	sll->length = position;

	result->length = len - position;

	return DS_OK;
}

//Status sll_unlink_at(SinglyLinkedList *sll, SinglyLinkedList *result, size_t position1, size_t position2);

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

Status sll_copy_list(SinglyLinkedList *sll, SinglyLinkedList **result)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll_is_empty(sll))
		return DS_ERR_INVALID_OPERATION;

	Status st = sll_init_list(result);

	if (st != DS_OK)
		return st;

	SinglyLinkedNode *scan = sll->head;
	SinglyLinkedNode *copy;

	while (scan != NULL)
	{

		st = sll_copy_node(scan, &copy);
		
		if (st != DS_OK)
			return st;

		st = sll_insert_node_tail((*result), copy);

		if (st != DS_OK)
			return st;

		scan = scan->next;
	}

	return DS_OK;
}

Status sll_copy_node(SinglyLinkedNode *node, SinglyLinkedNode **result)
{
	if (node == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = sll_make_node(result, node->data);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

Status sll_reverse(SinglyLinkedList *sll)
{
	if (sll == NULL)
		return DS_ERR_NULL_POINTER;

	if (sll->length < 2 || sll->head == NULL)
		return DS_ERR_INVALID_OPERATION;
	
	SinglyLinkedNode *prev = NULL;
	SinglyLinkedNode *curr = sll->head;
	SinglyLinkedNode * next = NULL;

	while (curr != NULL)
	{

		next = curr->next;

		curr->next = prev;

		prev = curr;

		curr = next;

	}

	sll->head = prev;

	return DS_OK;
}

//Status sll_switch_nodes(SinglyLinkedList *sll, size_t position1, size_t position2)
//Status sll_switch_head(SinglyLinkedList *sll, size_t position);
//Status sll_switch_tail(SinglyLinkedList *sll, size_t position);
//Status sll_switch_ends(SinglyLinkedList *sll);

//Status sll_sort_bubble(SinglyLinkedList *sll);
//Status sll_sort_slection(SinglyLinkedList *sll);
//Status sll_sort_insertion(SinglyLinkedList *sll);

//Status sll_merge_sorted(SinglyLinkedList *sll1, SinglyLinkedList *sll2, SinglyLinkedList **result);
