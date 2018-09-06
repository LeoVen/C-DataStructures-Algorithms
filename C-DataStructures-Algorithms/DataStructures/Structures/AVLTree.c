/**
 * @file AVLTree.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Source file for @c AVLTree implementations in C
 *
 */

#include "AVLTree.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status avl_init_tree(AVLTree **avl)
{
	(*avl) = malloc(sizeof(AVLTree));

	if (!(*avl))
		return DS_ERR_ALLOC;

	(*avl)->root = NULL;

	(*avl)->size = 0;

	return DS_OK;
}

Status avl_init_node(AVLTreeNode **node)
{
	(*node) = malloc(sizeof(AVLTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = 0;
	(*node)->height = 1;

	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->parent = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

Status avl_make_node(AVLTreeNode **node, int value)
{
	(*node) = malloc(sizeof(AVLTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = value;
	(*node)->height = 1;

	(*node)->left = NULL;
	(*node)->right = NULL;
	(*node)->parent = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status avl_insert(AVLTree *avl, int value)
{
	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_contains(avl->root, value))
		return DS_OK;

	Status st;

	if (avl_is_empty(avl))
	{
		AVLTreeNode *node;

		st = avl_make_node(&node, value);

		if (st != DS_OK)
			return st;

		avl->root = node;

		(avl->size)++;
	}
	else
	{
		AVLTreeNode *scan = avl->root;
		AVLTreeNode *before = NULL;

		while (scan != NULL)
		{
			before = scan;

			if (scan->data > value)
				scan = scan->left;
			else if (scan->data < value)
				scan = scan->right;
			else
				return DS_OK;
		}

		AVLTreeNode *node;

		st = avl_make_node(&node, value);

		if (st != DS_OK)
			return st;

		node->parent = before;

		if (before->data < value)
			before->right = node;
		else
			before->left = node;

		st = avl_rebalance(avl, node);

		if (st != DS_OK)
			return st;

		(avl->size)++;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status avl_remove(BinarySearchTree *avl, int value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

//Status avl_display_wrapper(AVLTree *avl, int display)

Status avl_display_raw(AVLTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	avl_display_raw(node->right, spaces + 1);

	int i;
	for (i = 0; i < spaces * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d(%d)\n", node->height, node->data);

	avl_display_raw(node->left, spaces + 1);

	return DS_OK;
}

//Status avl_display_interactive(AVLTreeNode *node)
//Status avl_display_clean(AVLTreeNode *node)

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status avl_delete(AVLTree **avl)
{
	if (*avl == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = avl_delete_node(&((*avl)->root));

	if (st != DS_OK)
		return st;

	free(*avl);

	*avl = NULL;

	return DS_OK;
}

Status avl_delete_node(AVLTreeNode **node)
{
	if (*node == NULL)
		return DS_OK;

	avl_delete_node(&((*node)->left));

	avl_delete_node(&((*node)->right));

	free((*node));

	return DS_OK;
}

Status avl_erase(AVLTree **avl)
{
	if ((*avl) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = avl_delete(avl);

	if (st != DS_OK)
		return st;

	st = avl_init_tree(avl);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

//Status avl_delete(BinarySearchTreeNode **node)
//Status avl_erase(BinarySearchTree **avl)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status avl_find_max(AVLTree *avl, AVLTreeNode **result)
//Status avl_find_min(AVLTree *avl, AVLTreeNode **result)

int avl_height(AVLTreeNode *node)
{
	if (node == NULL)
		return 0;

	int height_l = (node->left == NULL) ? 0 : node->left->height;
	int height_r = (node->right == NULL) ? 0 : node->right->height;
		
	return 1 + ((height_l >= height_r) ? height_l : height_r);
}

bool avl_contains(AVLTreeNode *root, int value)
{
	if (root == NULL)
		return false;

	if (value > root->data)
		return avl_contains(root->left, value);
	else if (value < root->data)
		return avl_contains(root->right, value);
	else
		return true;
}

bool avl_is_empty(AVLTree *avl)
{
	return avl->size == 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status avl_traversal_wrapper(AVLTree *avl, int traversal)
//Status avl_traversal_preorder(AVLTreeNode *node)
//Status avl_traversal_inorder(AVLTreeNode *node)
//Status avl_traversal_postorder(AVLTreeNode *node)

//Status avl_traversal_leaves(AVLTreeNode *node)

// +-------------------------------------------------------------------------------------------------+
// |                                             AVL                                                 |
// +-------------------------------------------------------------------------------------------------+

int avl_balance_factor(AVLTreeNode *node)
{
	if (node == NULL)
		return 0;
	
	return ((node->left) ? node->left->height : 0) - ((node->right) ? node->right->height : 0);
}

Status avl_rotate_right(AVLTreeNode **node_y)
{
	AVLTreeNode *node_x = (*node_y)->left;
	AVLTreeNode *middle = node_x->right;

	// Rotate
	(*node_y)->left = middle;
	node_x->right = (*node_y);

	// Update heights
	(*node_y)->height = avl_height(*node_y);
	node_x->height = avl_height(node_x);

	// Update parents
	if ((*node_y)->parent != NULL)
	{
		if ((*node_y)->parent->data < (*node_y)->data)
			(*node_y)->parent->right = node_x;
		else
			(*node_y)->parent->left = node_x;
	}

	node_x->parent = (*node_y)->parent;
	(*node_y)->parent = node_x;

	if (middle != NULL)
		middle->parent = (*node_y);

	// Change new root
	*node_y = node_x;

	return DS_OK;
}

Status avl_rotate_left(AVLTreeNode **node_x)
{
	AVLTreeNode *node_y = (*node_x)->right;
	AVLTreeNode *middle = node_y->left;

	// Rotate
	(*node_x)->right = middle;
	node_y->left = (*node_x);

	// Update heights
	(*node_x)->height = avl_height(*node_x);
	node_y->height = avl_height(node_y);

	// Update parents
	if ((*node_x)->parent != NULL)
	{
		if ((*node_x)->parent->data < (*node_x)->data)
			(*node_x)->parent->right = node_y;
		else
			(*node_x)->parent->left = node_y;
	}

	node_y->parent = (*node_x)->parent;
	(*node_x)->parent = node_y;

	if (middle != NULL)
		middle->parent = (*node_x);

	// Change new root
	*node_x = node_y;

	return DS_OK;
}

Status avl_update_height(AVLTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	avl_update_height(node->left);

	avl_update_height(node->right);

	node->height = avl_height(node);

	return DS_OK;
}

// Node is the newly inserted node
Status avl_rebalance(AVLTree *avl, AVLTreeNode *node)
{
	if (avl == NULL || node == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	AVLTreeNode *scan = node;

	int balance, value = node->data;

	bool is_root = false;

	while (scan != NULL)
	{
		// If we are changing the root then change avl->root = scan
		if (scan->parent == NULL)
			is_root = true;

		scan->height = avl_height(scan);

		balance = avl_balance_factor(scan);

		// Left Left
		if (balance > 1 && value < scan->left->data)
		{
			st = avl_rotate_right(&scan);

			if (st != DS_OK)
				return st;
		}

		// Right Right
		if (balance < -1 && value > scan->right->data)
		{

			st = avl_rotate_left(&scan);

			if (st != DS_OK)
				return st;
		}

		// Left Right
		if (balance > 1 && value > scan->left->data)
		{
			st = avl_rotate_left(&(scan->left));

			if (st != DS_OK)
				return st;

			st = avl_rotate_right(&scan);

			if (st != DS_OK)
				return st;
		}

		// Right Left
		if (balance < -1 && value < scan->right->data)
		{
			st = avl_rotate_right(&(scan->right));

			if (st != DS_OK)
				return st;

			st = avl_rotate_left(&scan);

			if (st != DS_OK)
				return st;
		}

		if (is_root)
		{
			avl->root = scan;

			is_root = false;
		}

		scan = scan->parent;
	}

	return DS_OK;
}
