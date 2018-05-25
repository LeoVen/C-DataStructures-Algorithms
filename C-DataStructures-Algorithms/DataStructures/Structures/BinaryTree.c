/**
 * @file BinaryTree.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/05/2018
 *
 * @brief Source file for @c BinaryTree implementations in C
 *
 */

#include "BinaryTree.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status bt_init_node(BinaryTree **leaf, int value)
{
	(*leaf) = malloc(sizeof(BinaryTree));

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

BinaryTree * bt_get_node(int value)
{
	BinaryTree *leaf = malloc(sizeof(BinaryTree));

	leaf->left = NULL;
	leaf->right = NULL;

	leaf->parent = NULL;

	leaf->level = 0;
	leaf->data = value;
	
	return leaf;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status bt_insert(BinaryTree *ref, BinaryTree *new, BTLeaf leaf)
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

Status bt_remove(BinaryTree *ref, BTLeaf leaf)
{
	if (ref == NULL)
		return DS_ERR_NULL_POINTER;

	if (leaf == Right_bt && ref->right == NULL)
		return DS_ERR_INVALID_POSITION;

	if (leaf == Left_bt && ref->left == NULL)
		return DS_ERR_INVALID_POSITION;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status bt_display(BinaryTree *root)
{
	if (root == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\nBinary Tree");

	Status st = bt_display_raw(root);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bt_display_raw(BinaryTree *root)
{
	if (root == NULL)
		return DS_OK;

	bt_display_raw(root->right);

	printf("\n");

	size_t i;
	for (i = 0; i < root->level * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", root->data);

	bt_display_raw(root->left);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status bt_delete(BinaryTree **bt)
{
	if ((*bt)->left == NULL && (*bt)->right == NULL) {

		if ((*bt)->parent != NULL) {

			if ((*bt)->parent->right == (*bt))
				(*bt)->parent->right = NULL;
			else
				(*bt)->parent->left = NULL;

		}

		free((*bt));

		return DS_OK;
	}

	bt_delete(&((*bt)->right));

	bt_delete(&((*bt)->left));

	return DS_OK;
}

//Status bt_erase(BinaryTree **bt)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status bt_is_empty(BinaryTree *bt)

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

Status bt_traversal_preorder(BinaryTree *bt)
{
	if (bt == NULL)
		return DS_OK;

	printf("%d ", bt->data);

	bt_traversal_preorder(bt->left);

	bt_traversal_preorder(bt->right);

	return DS_OK;
}

Status bt_traversal_inorder(BinaryTree *bt)
{
	if (bt == NULL)
		return DS_OK;

	bt_traversal_inorder(bt->left);

	printf("%d ", bt->data);

	bt_traversal_inorder(bt->right);

	return DS_OK;
}

Status bt_traversal_postorder(BinaryTree *bt)
{
	if (bt == NULL)
		return DS_OK;

	bt_traversal_postorder(bt->left);

	bt_traversal_postorder(bt->right);

	printf("%d ", bt->data);

	return DS_OK;
}
