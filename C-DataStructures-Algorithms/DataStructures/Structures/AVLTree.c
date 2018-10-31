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

	(*node)->key = 0;
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

	(*node)->key = value;
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

			if (scan->key > value)
				scan = scan->left;
			else if (scan->key < value)
				scan = scan->right;
			else
				return DS_OK;
		}

		AVLTreeNode *node;

		st = avl_make_node(&node, value);

		if (st != DS_OK)
			return st;

		node->parent = before;

		if (before->key < value)
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

Status avl_display_wrapper(AVLTree *avl, int display)
{
	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	if (display)
	{
		printf("\n+----------------------+");
		printf("\n|       AVL Tree       |");
		printf("\n+----------------------+\n");
	}
	

	switch (display)
	{
	case -1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = avl_display_clean(avl->root, 0);
		break;
	case 0:
		printf("\n");
		st = avl_display_raw(avl->root, 0);
		break;
	case 1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = avl_display_interactive(avl->root, 0);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status avl_display_raw(AVLTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	avl_display_raw(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces * BT_PRINT_SPACES; i++)
		printf(" ");

	printf("%d\n", node->key);

	avl_display_raw(node->left, spaces + 1);

	return DS_OK;
}

Status avl_display_interactive(AVLTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	avl_display_interactive(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces; i++)
		printf("|-------");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%d|H-%d]\n", node->parent->key, node->key, avl_depth(node), node->height - 1);
	else
		printf("<%d(%d)[D-%d|H-%d]\n", 0, node->key, avl_depth(node), node->height - 1);

	avl_display_interactive(node->left, spaces + 1);

	return DS_OK;
}

Status avl_display_clean(AVLTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	avl_display_clean(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces; i++)
		printf("|       ");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%d|H-%d]\n", node->parent->key, node->key, avl_depth(node), node->height - 1);
	else
		printf("<%d(%d)[D-%d|H-%d]\n", 0, node->key, avl_depth(node), node->height - 1);

	avl_display_clean(node->left, spaces + 1);

	return DS_OK;
}

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

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status avl_key_max(AVLTree *avl, int *result)
{
	*result = 0;

	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	AVLTreeNode *scan = avl->root;

	while (scan->right != NULL)
	{
		scan = scan->right;
	}

	*result = scan->key;

	return DS_OK;
}

Status avl_key_min(AVLTree *avl, int *result)
{
	*result = 0;

	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	AVLTreeNode *scan = avl->root;

	while (scan->left != NULL)
	{
		scan = scan->left;
	}

	*result = scan->key;

	return DS_OK;
}

Status avl_find_max(AVLTree *avl, AVLTreeNode **result)
{
	*result = 0;

	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	AVLTreeNode *scan = avl->root;

	while (scan->right != NULL)
	{
		scan = scan->right;
	}

	*result = scan;

	return DS_OK;
}

Status avl_find_min(AVLTree *avl, AVLTreeNode **result)
{
	*result = 0;

	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	AVLTreeNode *scan = avl->root;

	while (scan->left != NULL)
	{
		scan = scan->left;
	}

	*result = scan;

	return DS_OK;
}

bool avl_contains(AVLTreeNode *root, int value)
{
	if (root == NULL)
		return false;

	if (value > root->key)
		return avl_contains(root->left, value);
	else if (value < root->key)
		return avl_contains(root->right, value);
	else
		return true;
}

bool avl_is_empty(AVLTree *avl)
{
	return avl->size == 0;
}

int avl_height_update(AVLTreeNode *node)
{
	if (node == NULL)
		return 0;

	int height_l = (node->left == NULL) ? 0 : node->left->height;
	int height_r = (node->right == NULL) ? 0 : node->right->height;

	return 1 + ((height_l >= height_r) ? height_l : height_r);
}

int avl_depth(AVLTreeNode *node)
{
	if (node == NULL)
		return 0;

	AVLTreeNode *scan = node;

	int depth = 0;

	while (scan->parent != NULL)
	{
		scan = scan->parent;

		depth++;
	}

	return depth;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

Status avl_traversal_wrapper(AVLTree *avl, int traversal)
{
	if (avl == NULL)
		return DS_ERR_NULL_POINTER;

	if (avl_is_empty(avl))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	switch (traversal)
	{
	case -1:
		printf("\nPreorder Traversal\n");
		st = avl_traversal_preorder(avl->root);
		break;
	case 0:
		printf("\nInorder Traversal\n");
		st = avl_traversal_inorder(avl->root);
		break;
	case 1:
		printf("\nPostorder Traversal\n");
		st = avl_traversal_postorder(avl->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status avl_traversal_preorder(AVLTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	printf(" %d", node->key);

	avl_traversal_preorder(node->left);

	avl_traversal_preorder(node->right);

	return DS_OK;
}

Status avl_traversal_inorder(AVLTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	avl_traversal_inorder(node->left);

	printf(" %d", node->key);

	avl_traversal_inorder(node->right);

	return DS_OK;
}

Status avl_traversal_postorder(AVLTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	avl_traversal_postorder(node->left);

	avl_traversal_postorder(node->right);

	printf(" %d", node->key);

	return DS_OK;
}

Status avl_traversal_leaves(AVLTreeNode *node)
{
	if (node->left != NULL)
	{
		avl_traversal_leaves(node->left);
	}
	if (node->right != NULL)
	{
		avl_traversal_leaves(node->right);
	}
	if (node->left == NULL && node->right == NULL)
	{
		printf(" %d", node->key);
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             AVL                                                 |
// +-------------------------------------------------------------------------------------------------+

/* Left-Left case
 *
 * T1, T2, T3 and T4 are subtrees.
 *
 *        Z                                      Y 
 *       / \                                   /   \
 *      Y   T4      Right Rotate (Z)          X      Z
 *     / \          - - - - - - - - ->      /  \    /  \ 
 *    X   T3                               T1  T2  T3  T4
 *   / \
 * T1   T2
 *
 */
Status avl_rotate_right(AVLTreeNode **node_z)
{
	// X won't change
	AVLTreeNode *node_zp = (*node_z)->parent; // Z parent
	AVLTreeNode *node_y = (*node_z)->left;    // Y
	AVLTreeNode *sub3 = node_y->right;        // T3
	
	// Rotate
	node_y->right = (*node_z);
	(*node_z)->left = sub3;

	// Modify parents
	(*node_z)->parent = node_y;
	node_y->parent = node_zp;

	if (sub3 != NULL)
	{
		sub3->parent = (*node_z);
	}
	
	// Update heights
	(*node_z)->height = avl_height_update(*node_z);
	
	node_y->height = avl_height_update(node_y);

	// Update parent of root
	if (node_zp != NULL)
	{
		if (node_zp->key > node_y->key)
			node_zp->left = node_y;
		else
			node_zp->right = node_y;

		// Update height
		node_zp->height = avl_height_update(node_zp);
	}

	// New root node
	*node_z = node_y;

	return DS_OK;
}

/* Right-Right case
 *
 * T1, T2, T3 and T4 are subtrees.
 * 
 *   Z                                Y
 *  /  \                            /   \ 
 * T1   Y     Left Rotate(Z)       Z      X
 *     /  \   - - - - - - - ->    / \    / \
 *    T2   X                     T1  T2 T3  T4
 *        / \
 *      T3  T4
 */
Status avl_rotate_left(AVLTreeNode **node_z)
{
	// X won't change
	AVLTreeNode *node_zp = (*node_z)->parent; // Z parent
	AVLTreeNode *node_y = (*node_z)->right;   // Y
	AVLTreeNode *sub2 = node_y->left;         // T2

	// Rotate
	node_y->left = (*node_z);
	(*node_z)->right = sub2;

	// Modify parents
	(*node_z)->parent = node_y;
	node_y->parent = node_zp;

	if (sub2 != NULL)
	{
		sub2->parent = (*node_z);
	}
	
	// Update heights
	(*node_z)->height = avl_height_update(*node_z);
	
	node_y->height = avl_height_update(node_y);

	// Update parent of root
	if (node_zp != NULL)
	{
		if (node_zp->key > node_y->key)
			node_zp->left = node_y;
		else
			node_zp->right = node_y;

		// Update height
		node_zp->height = avl_height_update(node_zp);
	}

	// New root node
	*node_z = node_y;

	return DS_OK;
}

int avl_height(AVLTreeNode *node)
{
	if (node == NULL)
		return 0;

	return node->height;
}

// Node is the newly inserted node
Status avl_rebalance(AVLTree *avl, AVLTreeNode *node)
{
	if (avl == NULL || node == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	AVLTreeNode *scan = node, *child = NULL;

	int balance, value = node->key;

	bool is_root = false;

	while (scan != NULL)
	{
		// If we are changing the root then change avl->root = scan
		if (scan->parent == NULL)
			is_root = true;

		scan->height = avl_height_update(scan);

		balance = avl_height(scan->right) - avl_height(scan->left);

		// Right
		if (balance >= 2)
		{
			child = scan->right;

			// Right Left
			if (avl_height(child->right) < avl_height(child->left))
			{
				st = avl_rotate_right(&child);

				if (st != DS_OK)
					return st;
			}

			st = avl_rotate_left(&scan);

			if (st != DS_OK)
				return st;
		}
		// Left
		else if (balance <= -2)
		{
			child = scan->left;

			// Left Right
			if (avl_height(child->left) < avl_height(child->right))
			{
				st = avl_rotate_left(&child);

				if (st != DS_OK)
					return st;
			}

			st = avl_rotate_right(&scan);

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
