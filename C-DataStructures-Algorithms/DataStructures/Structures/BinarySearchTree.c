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

	(*bst)->depth = 0;
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
	(*node)->data = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

BinarySearchTree * bst_get_tree(void)
{
	BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));

	bst->root = NULL;

	bst->depth = 0;
	bst->size = 0;

	return bst;
}

BinarySearchTreeNode * bst_get_node(int value)
{
	BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));

	node->left = NULL;
	node->right = NULL;

	node->parent = NULL;

	node->level = 0;
	node->data = value;
	
	return node;
}

Status bst_make_node(BinarySearchTreeNode **node, int value)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	(*node)->data = value;

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

	BinarySearchTreeNode *node;

	Status st = bst_make_node(&node, value);

	if (st != DS_OK)
		return st;

	BinarySearchTreeNode *scan = bst->root;
	BinarySearchTreeNode *before = NULL;

	while (scan != NULL)
	{
		before = scan;

		if (scan->data < value)
			scan = scan->left;
		else if (scan->data > value)
			scan = scan->right;
		else {

			free(node);

			return DS_OK;
		}

	}

	if (before == NULL) {

		node->parent = NULL;

		bst->root = node;

		(bst->size)++;

		return DS_OK;
	}
	
	node->parent = before;
	node->level = before->level + 1;

	bst->depth = node->level;

	if (before->data < value)
		before->left = node;
	else
		before->right = node;

	(bst->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status bst_remove(BinarySearchTree *bst, int value)

// Unlink subtree from referenced node (removes link with parent)
//Status bst_unlink(BinarySearchTreeNode *ref)

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
		printf("\n<parent_data(data)D-Depth\n\n");
		st = bst_display_clean(bst->root);
		break;
	case 0:
		st = bst_display_raw(bst->root);
		break;
	case 1:
		printf("\n<parent_data(data)D-Depth\n\n");
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

	bst_display_raw(node->left);

	int i;
	for (i = 0; i < node->level * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", node->data);

	bst_display_raw(node->right);

	return DS_OK;
}

Status bst_display_interactive(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_interactive(node->left);

	int i;
	for (i = 0; i < node->level; i++)
		printf("|-------");

	if (node->parent != NULL)
		printf("<%d(%d)D-%zu\n", node->parent->data, node->data, node->level);
	else
		printf("<%d(%d)D-%zu\n", 0, node->data, node->level);


	bst_display_interactive(node->right);

	return DS_OK;
}

Status bst_display_clean(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_clean(node->left);

	int i;
	for (i = 0; i < node->level; i++)
		printf("|       ");

	if (node->parent != NULL)
		printf("<%d(%d)D-%zu\n", node->parent->data, node->data, node->level);
	else
		printf("<%d(%d)D-%zu\n", 0, node->data, node->level);


	bst_display_clean(node->right);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+
/*
Status bst_delete(BinarySearchTreeNode **node)
{
	if ((*node) != NULL)
		bst_delete(&((*node)->left));

	if ((*node) != NULL)
		bst_delete(&((*node)->right));

	free(node);

	return DS_OK;
}

Status bst_erase(BinarySearchTree **bst)
{
	if ((*bst) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = bst_delete(bst);

	if (st != DS_OK)
		return st;

	return DS_OK;
}
*/
// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status bst_find_max(BinarySearchTree *bst, BinarySearchTreeNode **result);
//Status bst_find_min(BinarySearchTree *bst, BinarySearchTreeNode **result);

bool bst_is_empty(BinarySearchTree *bst)
{
	return (bst->root == NULL);
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

	printf(" %d", node->data);

	bst_traversal_preorder(node->right);

	bst_traversal_preorder(node->left);

	return DS_OK;
}

Status bst_traversal_inorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_inorder(node->right);

	printf(" %d", node->data);

	bst_traversal_inorder(node->left);

	return DS_OK;
}

Status bst_traversal_postorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_postorder(node->right);

	bst_traversal_postorder(node->left);

	printf(" %d", node->data);

	return DS_OK;
}

Status bst_traversal_leaves(BinarySearchTreeNode *node)
{
	if (node->right != NULL) {
		bst_traversal_leaves(node->right);
	}
	if (node->left != NULL) {
		bst_traversal_leaves(node->left);
	}
	if (node->left == NULL && node->right == NULL) {
		printf(" %d", node->data);
	}

	return DS_OK;
}
