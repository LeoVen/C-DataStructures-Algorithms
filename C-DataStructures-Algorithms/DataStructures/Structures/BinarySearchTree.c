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

	(*node)->key = 0;
	(*node)->count = 0;

	return DS_OK;
}

Status bst_make_node(BinarySearchTreeNode **node, int value)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->key = value;
	(*node)->count = 1;

	(*node)->left = NULL;
	(*node)->right = NULL;

	(*node)->parent = NULL;

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
		{
			(bst->size)++;

			(scan->count)++;

			return DS_OK;
		}
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

Status bst_remove(BinarySearchTree *bst, int value)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	BinarySearchTreeNode *temp, *node = bst_node_find(bst->root, value);

	if (node == NULL)
		return DS_ERR_NOT_FOUND;

	Status st;

	bool is_root = node->parent == NULL;

	if (node->count > 1)
	{
		(node->count)--;
	}
	else
	{
		// Deleting a leaf. No need to update parent pointers.
		if (node->left == NULL && node->right == NULL)
		{
			// Deleting last element
			if (is_root)
				bst->root = NULL;
			else
			{
				// This is the right leaf of a node
				if (node->parent->right == node)
					node->parent->right = NULL;
				// This is the left leaf of a node
				else
					node->parent->left = NULL;
			}

			free(node);
		}
		// Only right subtree. Need to update right subtree parent pointer.
		else if (node->left == NULL)
		{
			// Short-circuit the right subtree
			if (is_root)
			{
				bst->root = node->right;

				bst->root->parent = NULL;
			}
			else
			{
				// Linking the subtree parent pointer
				node->right->parent = node->parent;

				// This is the right child of a node
				if (node->parent->right == node)
					node->parent->right = node->right;
				// This is the left child of a node
				else
					node->parent->left = node->right;
			}

			free(node);
		}
		// Only left subtree. Need to update left subtree parent pointer.
		else if (node->right == NULL)
		{
			// Short-circuit the left subtree
			if (is_root)
			{
				bst->root = node->left;

				bst->root->parent = NULL;
			}
			else
			{
				// Linking the subtree parent pointer
				node->left->parent = node->parent;

				// This is the right child of a node
				if (node->parent->right == node)
					node->parent->right = node->left;
				// This is the left child of a node
				else
					node->parent->left = node->left;
			}

			free(node);
		}
		// Node has left and right subtrees
		else
		{
			// Replace current value with successor's (temp) and then delete it.
			// Note that we don't care about is_root since we are only replacing
			// the node's contents.
			temp = node->right;

			// Finding successor node (temp)
			while (temp->left != NULL)
				temp = temp->left;

			// Storing key in a temporary value
			int temp_key = temp->key;
			int temp_count = temp->count;

			// Deleting temp
			// This node can not be an inner node so there are only three
			// options. Its a leaf, or it has either left or right subtrees
			// but not both.
			if (temp->left == NULL && temp->right == NULL)
			{
				// Can't be root

				// This is the right leaf of a node
				if (temp->parent->right == temp)
					temp->parent->right = NULL;
				// This is the left leaf of a node
				else
					temp->parent->left = NULL;

				free(temp);
			}
			// Only right subtree. Need to update right subtree parent pointer.
			else if (temp->left == NULL)
			{
				// Can't be root

				// Linking the subtree parent pointer
				temp->right->parent = temp->parent;

				// This is the right child of a node
				if (temp->parent->right == temp)
					temp->parent->right = temp->right;
				// This is the left child of a node
				else
					temp->parent->left = temp->right;

				free(temp);
			}
			// Only left subtree. Need to update left subtree parent pointer.
			else if (temp->right == NULL)
			{
				// Can't be root

				// Linking the subtree parent pointer
				temp->left->parent = temp->parent;

				// This is the right child of a node
				if (temp->parent->right == temp)
					temp->parent->right = temp->left;
				// This is the left child of a node
				else
					temp->parent->left = temp->left;

				free(temp);
			}
			// Undefined behaviour
			else
				return DS_ERR_UNEXPECTED_RESULT;

			// Finally switching values
			node->key = temp_key;
			node->count = temp_count;

		}
	}

	(bst->size)--;

	return DS_OK;
}


Status bst_pop(BinarySearchTree *bst, int *result)
{
	*result = 0;

	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	*result = bst->root->key;

	Status st = bst_remove(bst, *result);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

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

	if (display)
	{
		printf("\n+----------------------+");
		printf("\n|  Binary Search Tree  |");
		printf("\n+----------------------+\n");
	}

	switch (display)
	{
	case -1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_clean(bst->root, 0);
		break;
	case 0:
		printf("\n");
		st = bst_display_raw(bst->root, 0);
		break;
	case 1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_interactive(bst->root, 0);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bst_display_raw(BinarySearchTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	bst_display_raw(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", node->key);

	bst_display_raw(node->left, spaces + 1);

	return DS_OK;
}

Status bst_display_interactive(BinarySearchTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	bst_display_interactive(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces; i++)
		printf("|-------");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%zu|H-%zu]\n", node->parent->key, node->key, bst_depth(node), bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%zu|H-%zu]\n", 0, node->key, bst_depth(node), bst_height(node) - 1);

	bst_display_interactive(node->left, spaces + 1);

	return DS_OK;
}

Status bst_display_clean(BinarySearchTreeNode *node, size_t spaces)
{
	if (node == NULL)
		return DS_OK;

	bst_display_clean(node->right, spaces + 1);

	size_t i;
	for (i = 0; i < spaces; i++)
		printf("|       ");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%zu|H-%zu]\n", node->parent->key, node->key, bst_depth(node), bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%zu|H-%zu]\n", 0, node->key, bst_depth(node), bst_height(node) - 1);

	bst_display_clean(node->left, spaces + 1);

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

BinarySearchTreeNode* bst_node_find(BinarySearchTreeNode *root, int value)
{
	if (root == NULL)
		return NULL;

	BinarySearchTreeNode *scan = root;

	while (scan != NULL)
	{
		if (scan->key < value)
			scan = scan->right;
		else if (scan->key > value)
			scan = scan->left;
		else
			return scan;
	}

	return NULL;
}

bool bst_is_empty(BinarySearchTree *bst)
{
	return bst->size == 0;
}

size_t bst_height(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return 0;

	size_t r_height = bst_height(node->right);

	size_t l_height = bst_height(node->left);

	return (l_height > r_height) ? l_height + 1 : r_height + 1;
}

size_t bst_depth(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return 0;

	BinarySearchTreeNode *scan = node;

	size_t depth = 0;

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

Status bst_traversal_wrapper(BinarySearchTree *bst, int traversal)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	switch (traversal)
	{
	case -1:
		printf("\nPreorder Traversal\n");
		st = bst_traversal_preorder(bst->root);
		break;
	case 0:
		printf("\nInorder Traversal\n");
		st = bst_traversal_inorder(bst->root);
		break;
	case 1:
		printf("\nPostorder Traversal\n");
		st = bst_traversal_postorder(bst->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bst_traversal_preorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	printf(" %d", node->key);

	bst_traversal_preorder(node->left);

	bst_traversal_preorder(node->right);

	return DS_OK;
}

Status bst_traversal_inorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_inorder(node->left);

	printf(" %d", node->key);

	bst_traversal_inorder(node->right);

	return DS_OK;
}

Status bst_traversal_postorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_postorder(node->left);

	bst_traversal_postorder(node->right);

	printf(" %d", node->key);

	return DS_OK;
}

Status bst_traversal_leaves(BinarySearchTreeNode *node)
{
	if (node->left != NULL)
	{
		bst_traversal_leaves(node->left);
	}
	if (node->right != NULL)
	{
		bst_traversal_leaves(node->right);
	}
	if (node->left == NULL && node->right == NULL)
	{
		printf(" %d", node->key);
	}

	return DS_OK;
}
