/**
 * @file AVLTree.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Source file for @c AVLTree implementations in C
 *
 */

#include "..\Headers\AVLTree.h"


 // +-------------------------------------------------------------------------------------------------+
 // |                                          Initializers                                           |
 // +-------------------------------------------------------------------------------------------------+

Status avl_init_tree(AVLTree **avl)
{
	(*avl) = malloc(sizeof(AVLTree));

	if (!(*avl))
		return DS_ERR_ALLOC;

	(*avl)->root = NULL;

	(*avl)->depth = 0;
	(*avl)->size = 0;

	return DS_OK;
}

Status avl_init_node(AVLTreeNode **node)
{
	(*node) = malloc(sizeof(AVLTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

//AVLTree * avl_get_tree()
//AVLTreeNode * avl_get_node(int value)

Status avl_make_node(AVLTreeNode **node, int value)
{

}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

//Status avl_insert(AVLTree *avl, int value)

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status avl_remove(BinarySearchTree *avl, int value)

// Unlink subtree from referenced node (removes link with parent)
//Status avl_unlink(BinarySearchTreeNode *ref)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

//Status avl_display_wrapper(AVLTree *avl, int display)
//Status avl_display_raw(AVLTreeNode *node)
//Status avl_display_interactive(AVLTreeNode *node)
//Status avl_display_clean(AVLTreeNode *node)

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status avl_delete(BinarySearchTreeNode **node)
//Status avl_erase(BinarySearchTree **avl)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

//Status avl_find_max(AVLTree *avl, AVLTreeNode **result)
//Status avl_find_min(AVLTree *avl, AVLTreeNode **result)

//bool avl_is_empty(AVLTree *avl)

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

//Status avl_balance(AVLTreeNode *node)

//Status avl_shift_right(AVLTreeNode *node)
// Status avl_shift_left(AVLTreeNode *node)