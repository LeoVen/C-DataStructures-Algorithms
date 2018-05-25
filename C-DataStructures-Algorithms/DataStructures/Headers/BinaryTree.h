/**
 * @file BinaryTree.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/05/2018
 *
 * @brief Header file for @c BinaryTree implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Core.h"

	/**
	 * This enum is used to determine weather a Node will be inserted as the
	 * @c Right child or the @c Left child of a referenced node. Only used with
	 * @c BinaryTree.
	 */
	typedef enum BTLeaf {
		Left_bt = 0,
		Right_bt = 1
	} BTLeaf;

	/**
	 * A @c BinaryTree is a hierarchical data structure where each node has up
	 * to 2 childs. In this case the @c BinaryTree can be seeing as independent
	 * Nodes without a Structure or a Descriptor. This is due to the fact that
	 * this @c BinaryTree has its operations relative to another @c BinaryTree
	 * (which are actually nodes) making this structure having no rules for
	 * insertion and removal allowing for the user to create its own. The Node
	 * has a data variable, a level variable which is relative to its parent,
	 * one pointer to its left child, one to is right child and another to its
	 * parent, being NULL if that node is the @c root.
	 */
	typedef struct BinaryTree {
		int data;                           /*!< Node's data */
		size_t level;                       /*!< On what level the Node is in */
		struct BinaryTree *right;           /*!< Pointer to right child */
		struct BinaryTree *left;            /*!< Pointer to left child */
		struct BinaryTree *parent;          /*!< Pointer to parent Node */
	} BinaryTree;

	Status bt_init_node(BinaryTree **leaf, int value);

	BinaryTree * bt_get_node(int value);

	Status bt_insert(BinaryTree *ref, BinaryTree *new, BTLeaf leaf);

	Status bt_remove(BinaryTree *ref, BTLeaf leaf);

	// Unlink subtree from referenced node (removes link with parent)
	//Status bt_unlink(BinaryTree *ref);

	Status bt_display(BinaryTree *root);
	Status bt_display_raw(BinaryTree *root);

	Status bt_delete(BinaryTree **bt);
	//Status bt_erase(BinaryTree **bt);

	//Status bt_is_empty(BinaryTree *bt);

	Status bt_traversal_preorder(BinaryTree *bt);
	Status bt_traversal_inorder(BinaryTree *bt);
	Status bt_traversal_postorder(BinaryTree *bt);
	
#ifdef __cplusplus
}
#endif;
