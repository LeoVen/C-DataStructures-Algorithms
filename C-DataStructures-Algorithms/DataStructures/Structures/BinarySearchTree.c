/**
 * @file BinarySearchTree.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 17/05/2018
 *
 * @brief Source file for @c BinarySearchTree implementations in C
 *
 */

#include "BinarySearchTree.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status bst_init_tree(BinarySearchTree **bst)
{
	(*bst) = malloc(sizeof(BinarySearchTree));

	if (!(*bst))
		return DS_ERR_ALLOC;

	(*bst)->root = NULL;

	(*bst)->size = 0;

	return DS_OK;
}

Status bst_init_node(BinarySearchTreeNode **node)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->left = NULL;
	(*node)->right = NULL;

	(*node)->parent = NULL;

	(*node)->level = 0;
	(*node)->key = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

BinarySearchTree *bst_get_tree(void)
{
	BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));

	bst->root = NULL;

	bst->size = 0;

	return bst;
}

BinarySearchTreeNode *bst_get_node(int value)
{
	BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));

	node->left = NULL;
	node->right = NULL;

	node->parent = NULL;

	node->level = 0;
	node->key = value;

	return node;
}

Status bst_make_node(BinarySearchTreeNode **node, int value)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->key = value;

	(*node)->left = NULL;
	(*node)->right = NULL;

	(*node)->parent = NULL;

	(*node)->level = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status bst_insert(BinarySearchTree *bst, int value)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	BinarySearchTreeNode *scan = bst->root;
	BinarySearchTreeNode *before = NULL;

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

	BinarySearchTreeNode *node;

	Status st = bst_make_node(&node, value);

	if (st != DS_OK)
		return st;

	if (before == NULL)
	{
		node->parent = NULL;

		bst->root = node;

		(bst->size)++;

		return DS_OK;
	}

	node->parent = before;
	node->level = before->level + 1;

	if (before->key < value)
		before->right = node;
	else
		before->left = node;

	(bst->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status bst_remove(BinarySearchTree *bst, int value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status bst_display_wrapper(BinarySearchTree *bst, int display)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	printf("\n+----------------------+");
	printf("\n|  Binary Search Tree  |");
	printf("\n+----------------------+\n");

	switch (display)
	{
	case -1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_clean(bst->root);
		break;
	case 0:
		st = bst_display_raw(bst->root);
		break;
	case 1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_interactive(bst->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bst_display_raw(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_raw(node->right);

	size_t i;
	for (i = 0; i < node->level * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", node->key);

	bst_display_raw(node->left);

	return DS_OK;
}

Status bst_display_interactive(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_interactive(node->right);

	size_t i;
	for (i = 0; i < node->level; i++)
		printf("|-------");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%zu|H-%zu]\n", node->parent->key, node->key, node->level, bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%zu|H-%zu]\n", 0, node->key, node->level, bst_height(node) - 1);

	bst_display_interactive(node->left);

	return DS_OK;
}

Status bst_display_clean(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_clean(node->right);

	size_t i;
	for (i = 0; i < node->level; i++)
		printf("|       ");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%zu|H-%zu]\n", node->parent->key, node->key, node->level, bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%zu|H-%zu]\n", 0, node->key, node->level, bst_height(node) - 1);

	bst_display_clean(node->left);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status bst_delete(BinarySearchTree **bst)
{
	if (*bst == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = bst_delete_node(&((*bst)->root));

	if (st != DS_OK)
		return st;

	free(*bst);

	*bst = NULL;

	return DS_OK;
}

Status bst_delete_node(BinarySearchTreeNode **node)
{
	if (*node == NULL)
		return DS_OK;

	bst_delete_node(&((*node)->right));

	bst_delete_node(&((*node)->left));

	free((*node));

	return DS_OK;
}

Status bst_erase(BinarySearchTree **bst)
{
	if ((*bst) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = bst_delete(bst);

	if (st != DS_OK)
		return st;

	st = bst_init_tree(bst);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status bst_key_max(BinarySearchTree *bst, int *result)
{
	*result = 0;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *scan = bst->root;

	while (scan->right != NULL)
	{
		scan = scan->right;
	}

	*result = scan->key;

	return DS_OK;
}

Status bst_key_min(BinarySearchTree *bst, int *result)
{
	*result = 0;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *scan = bst->root;

	while (scan->left != NULL)
	{
		scan = scan->left;
	}

	*result = scan->key;

	return DS_OK;
}

Status bst_find_max(BinarySearchTree *bst, BinarySearchTreeNode **result)
{
	*result = NULL;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *scan = bst->root;

	while (scan->right != NULL)
	{
		scan = scan->right;
	}

	*result = scan;

	return DS_OK;
}

Status bst_find_min(BinarySearchTree *bst, BinarySearchTreeNode **result)
{
	*result = NULL;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *scan = bst->root;

	while (scan->left != NULL)
	{
		scan = scan->left;
	}

	*result = scan;

	return DS_OK;
}

Status bst_search(BinarySearchTree *bst, int key, BinarySearchTreeNode **result)
{
	*result = NULL;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *scan = bst->root;

	while (scan->key != key)
	{
		if (scan->key < key)
			scan = scan->right;
		else if (scan->key > key)
			scan = scan->left;
	}

	*result = scan;

	return DS_OK;
}

bool bst_is_empty(BinarySearchTree *bst)
{
	return (bst->root == NULL);
}

size_t bst_height(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return 0;

	size_t r_height = bst_height(node->right);

	size_t l_height = bst_height(node->left);

	return (l_height > r_height) ? l_height + 1 : r_height + 1;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

Status bst_traversal_wrapper(BinarySearchTree *bst, int traversal)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	switch (traversal)
	{
	case -1:
		bst_traversal_preorder(bst->root);
		break;
	case 0:
		bst_traversal_inorder(bst->root);
		break;
	case 1:
		bst_traversal_postorder(bst->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	return DS_OK;
}

Status bst_traversal_preorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	printf(" %d", node->key);

	bst_traversal_preorder(node->right);

	bst_traversal_preorder(node->left);

	return DS_OK;
}

Status bst_traversal_inorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_inorder(node->right);

	printf(" %d", node->key);

	bst_traversal_inorder(node->left);

	return DS_OK;
}

Status bst_traversal_postorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_postorder(node->right);

	bst_traversal_postorder(node->left);

	printf(" %d", node->key);

	return DS_OK;
}

Status bst_traversal_leaves(BinarySearchTreeNode *node)
{
	if (node->right != NULL)
	{
		bst_traversal_leaves(node->right);
	}
	if (node->left != NULL)
	{
		bst_traversal_leaves(node->left);
	}
	if (node->left == NULL && node->right == NULL)
	{
		printf(" %d", node->key);
	}

	return DS_OK;
}
