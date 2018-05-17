/**
 * @file BinaryTree.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/05/2018
 *
 * @brief Source file for @c BinaryTree implementations in C
 *
 */

#include "..\Headers\BinaryTree.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+
/*
Status bt_init_tree(BinaryTree **bt)
{
	(*bt) = malloc(sizeof(BinaryTree));

	if (!(*bt))
		return DS_ERR_ALLOC;

	(*bt)->root = NULL;

	(*bt)->depth = 0;
	(*bt)->size = 0;

	return DS_OK;
}
*/
Status bt_init_node(BinaryTreeNode **leaf, int value)
{
	(*leaf) = malloc(sizeof(BinaryTreeNode));

	if (!(*leaf))
		return DS_ERR_ALLOC;

	(*leaf)->left = NULL;
	(*leaf)->right = NULL;

	(*leaf)->parent = NULL;

	(*leaf)->level = 0;
	(*leaf)->data = value;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*
/*
BinaryTree * bt_get_tree()
{
	BinaryTree *bt = malloc(sizeof(BinaryTree));

	if (!bt)
		return DS_ERR_ALLOC;

	bt->root = NULL;

	bt->depth = 0;
	bt->size = 0;

	return bt;
}
*/
BinaryTreeNode * bt_get_node(int value)
{
	BinaryTreeNode *leaf = malloc(sizeof(BinaryTreeNode));

	leaf->left = NULL;
	leaf->right = NULL;

	leaf->parent = NULL;

	leaf->level = 0;
	leaf->data = value;
	
	return leaf;
}
/*
Status bt_make_node(BinaryTreeNode **leaf, int value)
{
	(*leaf) = malloc(sizeof(BinaryTreeNode));

	(*leaf)->data = value;

	(*leaf)->left = NULL;
	(*leaf)->right = NULL;

	(*leaf)->parent = NULL;

	(*leaf)->level = 0;

	return DS_OK;
}
*/
// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status bt_insert(BinaryTreeNode *ref, BinaryTreeNode *new, BTLeaf leaf)
{
	if (ref == NULL || new == NULL)
		return DS_ERR_NULL_POINTER;

	if (leaf == Right_bt && ref->right != NULL)
		return DS_ERR_INVALID_POSITION;

	if (leaf == Left_bt && ref->left != NULL)
		return DS_ERR_INVALID_POSITION;

	if (leaf == Right_bt)
		ref->right = new;
	else
		ref->left = new;

	new->parent = ref;

	new->level = ref->level + 1;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status bt_remove(BinaryTreeNode *ref, BinaryTreeNode *new, BTLeaf leaf)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status bt_display(BinaryTreeNode *root)
{
	if (root == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\nBinary Tree");

	Status st = bt_display_raw(root);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bt_display_raw(BinaryTreeNode *root)
{
	if (root == NULL)
		return DS_OK;

	bt_display_raw(root->right);

	printf("\n");
	for (int i = 0; i < root->level * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", root->data);

	bt_display_raw(root->left);
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status bt_delete(BinaryTree **bt)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status bt_is_empty(BinaryTree *bt)