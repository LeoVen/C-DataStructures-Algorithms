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

	typedef enum BTLeaf {
		Left_bt = 0,
		Right_bt = 1
	} BTLeaf;

	typedef struct BinaryTree {
		int data;                           /*!< Node's data */
		size_t level;                       /*!< On what level the Node is in */
		struct BinaryTree *right;       /*!< Pointer to right child */
		struct BinaryTree *left;        /*!< Pointer to left child */
		struct BinaryTree *parent;      /*!< Pointer to parent Node */
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
	Status bt_erase(BinaryTree **bt);

	//Status bt_is_empty(BinaryTree *bt);

	Status bt_traversal_preorder(BinaryTree *bt);
	Status bt_traversal_inorder(BinaryTree *bt);
	Status bt_traversal_postorder(BinaryTree *bt);
	
#ifdef __cplusplus
}
#endif;
