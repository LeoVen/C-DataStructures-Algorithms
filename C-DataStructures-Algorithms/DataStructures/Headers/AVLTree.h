/**
 * @file AVLTree.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Header file for @c AVLTree implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef BT_PRINT_SPACES

#define BT_PRINT_SPACES 4

#endif

	/**
	 * An @c AVLTreeNode is what an @c AVLTree is composed of. It it much like
	 * a @c BinarySearchTreeNode with one pointer to its left child, one to its
	 * right child and another to its parent, being NULL if that Node is the
	 * @c root node. It also has a height value to easily implement the AVL
	 * tree property.
	 */
	typedef struct AVLTreeNode
	{
		int data;					/*!< Node's data */
		int height;				    /*!< Node's Height */
		struct AVLTreeNode *right;  /*!< Pointer to right child */
		struct AVLTreeNode *left;   /*!< Pointer to left child */
		struct AVLTreeNode *parent; /*!< Pointer to parent Node */
	} AVLTreeNode;

	/**
	 * A @c AVLTree is much like a @c BinarySearchTree but now with a rule
	 * for inserting the nodes. This now makes every @c BinarySearchTreeNode
	 * binded to its descriptor, the @c BinarySearchTree, which has a size
	 * variable counting the amount of elements in that tree and a pointer to
	 * the first node added, the @c root. The insertion rule is that every Node
	 * to the left must have a lower (key) value (data in this case) than its
	 * parent, higher values to the right and no duplicate nodes.
	 *
	 * @note For simplicity the keys of each node are actually its data.
	 */
	typedef struct AVLTree
	{
		size_t size;			  /*!< Total @c AVLTree elements */
		struct AVLTreeNode *root; /*!< Pointer to the very first node in the @c AVLTree */
	} AVLTree;

	Status avl_init_tree(AVLTree **avl);
	Status avl_init_node(AVLTreeNode **node);

	Status avl_make_node(AVLTreeNode **node, int value);

	Status avl_insert(AVLTree *avl, int value);

	//Status avl_remove(BinarySearchTree *avl, int value);

	//Status avl_display_wrapper(AVLTree *avl, int display);
	Status avl_display_raw(AVLTreeNode *node, size_t spaces);
	//Status avl_display_interactive(AVLTreeNode *node);
	//Status avl_display_clean(AVLTreeNode *node);

	Status avl_delete(AVLTree **avl);
	Status avl_delete_node(AVLTreeNode **node);
	Status avl_erase(AVLTree **avl);

	//Status avl_find_max(AVLTree *avl, AVLTreeNode **result);
	//Status avl_find_min(AVLTree *avl, AVLTreeNode **result);
	
	int avl_height(AVLTreeNode *node);

	bool avl_contains(AVLTreeNode *root, int value);
	
	bool avl_is_empty(AVLTree *avl);

	//Status avl_traversal_wrapper(AVLTree *avl, int traversal);
	//Status avl_traversal_preorder(AVLTreeNode *node);
	//Status avl_traversal_inorder(AVLTreeNode *node);
	//Status avl_traversal_postorder(AVLTreeNode *node);

	//Status avl_traversal_leaves(AVLTreeNode *node);

	int avl_balance_factor(AVLTreeNode *node);

	Status avl_rotate_right(AVLTreeNode **node_y);
	Status avl_rotate_left(AVLTreeNode **node_x);

	Status avl_rebalance(AVLTree *avl, AVLTreeNode *node);

#ifdef __cplusplus
}
#endif;
