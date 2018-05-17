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

	typedef struct BinaryTreeNode {
		int data;                           /*!< Node's data */
		size_t level;                       /*!< On what level the Node is in */
		struct BinaryTreeNode *right;       /*!< Pointer to right child */
		struct BinaryTreeNode *left;        /*!< Pointer to left child */
		struct BinaryTreeNode *parent;      /*!< Pointer to parent Node */
	} BinaryTreeNode;

#define BT_PRINT_SPACES 4

	//typedef struct BinaryTree {
	//	size_t depth;                       /*!< @c BinaryTree depth */
	//	size_t size;                        /*!< Total @c BinaryTree elements */
	//	struct BinaryTreeNode *root;        /*!< Pointer to the very first node in the @c BinaryTree */
	//} BinaryTree;

	//Status bt_init_tree(BinaryTree **bt);
	Status bt_init_node(BinaryTreeNode **leaf, int value);

	//BinaryTree * bt_get_tree();
	BinaryTreeNode * bt_get_node(int value);

	//Status bt_make_node(BinaryTreeNode **leaf, int value);

	Status bt_insert(BinaryTreeNode *ref, BinaryTreeNode *new, BTLeaf leaf);

	//Status bt_remove(BinaryTreeNode *ref, BinaryTreeNode *new, BTLeaf leaf);

	// Unlink subtree from referenced node (removes link with parent)
	//Status bt_unlink(BinaryTreeNode *ref);

	Status bt_display(BinaryTreeNode *root);
	Status bt_display_raw(BinaryTreeNode *root);

	//Status bt_delete(BinaryTree **bt);

	//Status bt_is_empty(BinaryTree *bt);
	
#ifdef __cplusplus
}
#endif;
