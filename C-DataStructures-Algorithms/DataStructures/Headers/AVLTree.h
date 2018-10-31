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
		int key;                    /*!< Node's key */
		int height;				    /*!< Node's Height */
		struct AVLTreeNode *right;  /*!< Pointer to right child */
		struct AVLTreeNode *left;   /*!< Pointer to left child */
		struct AVLTreeNode *parent; /*!< Pointer to parent Node */
	} AVLTreeNode;

	/**
	 * A @c AVLTree is much like a @c BinarySearchTree where the difference
	 * between heights of left and right subtrees cannot be more than one for
	 * all nodes. To maintain this property left and right rotations are used.
	 *
	 * @b Advantages over @c BinarySearchTree
	 * - The height of an @c AVLTree is always <code>log n</code> so all
	 * operations like search, insert and remove are running on
	 * <code>O(log n)</code>
	 *
	 * @b Drawbacks
	 * - Insertion is slower because to maintain the AVL property many
	 * rotations are needed
	 *
	 * @b Functions
	 *
	 * @c BinarySearchTree.c
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

	Status avl_display_wrapper(AVLTree *avl, int display);
	Status avl_display_raw(AVLTreeNode *node, size_t spaces);
	Status avl_display_interactive(AVLTreeNode *node, size_t spaces);
	Status avl_display_clean(AVLTreeNode *node, size_t spaces);

	Status avl_delete(AVLTree **avl);
	Status avl_delete_node(AVLTreeNode **node);
	Status avl_erase(AVLTree **avl);

	Status avl_key_max(AVLTree *avl, int *result);
	Status avl_key_min(AVLTree *avl, int *result);
	Status avl_find_max(AVLTree *avl, AVLTreeNode **result);
	Status avl_find_min(AVLTree *avl, AVLTreeNode **result);
	
	bool avl_contains(AVLTreeNode *root, int value);
	
	bool avl_is_empty(AVLTree *avl);

	int avl_height_update(AVLTreeNode *node);
	int avl_depth(AVLTreeNode *node);

	Status avl_traversal_wrapper(AVLTree *avl, int traversal);
	Status avl_traversal_preorder(AVLTreeNode *node);
	Status avl_traversal_inorder(AVLTreeNode *node);
	Status avl_traversal_postorder(AVLTreeNode *node);

	Status avl_traversal_leaves(AVLTreeNode *node);

	Status avl_rotate_right(AVLTreeNode **node_z);
	Status avl_rotate_left(AVLTreeNode **node_z);

	int avl_height(AVLTreeNode *node);

	Status avl_rebalance(AVLTree *avl, AVLTreeNode *node);

#ifdef __cplusplus
}
#endif;
