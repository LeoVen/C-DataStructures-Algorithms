/**
 * @file BinarySearchTree.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 17/05/2018
 *
 * @brief Header file for @c BinarySearchTree implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\..\Core\Core.h"

	/**
	 * A @c BinarySearchTreeNode is what a @c BinarySearchTree is composed of.
	 * It it much like a @c BinaryTree (Node) with one pointer to its left
	 * child, one to its right child and another to its parent, being NULL if
	 * that Node is the @c root.
	 */
	typedef struct BinarySearchTreeNode {
		int data;                           /*!< Node's data */
		size_t level;                       /*!< On what level the Node is in */
		struct BinarySearchTreeNode *right; /*!< Pointer to right child */
		struct BinarySearchTreeNode *left;  /*!< Pointer to left child */
		struct BinarySearchTreeNode *parent;/*!< Pointer to parent Node */
	} BinarySearchTreeNode;

	/**
	 * A @c BinarySearchTree is much like a @c BinaryTree but now with a rule
	 * for inserting the nodes. This now makes every @c BinarySearchTreeNode
	 * binded to its descriptor, the @c BinarySearchTree, which has a size
	 * variable counting the amount of elements in that tree, a depth variable
	 * which keeps track of the deepest leaf and a pointer to the first node
	 * added, the @c root. The insertion rule is that every Node to the left
	 * must have a lower (key) value (data in this case) than its parent,
	 * higher values to the right and no duplicate nodes.
	 *
	 * @note For simplicity the keys of each node are actually its data.
	 */
	typedef struct BinarySearchTree {
		size_t depth;                       /*!< @c BinarySearchTree depth */
		size_t size;                        /*!< Total @c BinarySearchTree elements */
		struct BinarySearchTreeNode *root;  /*!< Pointer to the very first node in the @c BinarySearchTree */
	} BinarySearchTree;

	Status bst_init_tree(BinarySearchTree **bt);
	Status bst_init_node(BinarySearchTreeNode **node, int value);

	BinarySearchTree * bst_get_tree();
	BinarySearchTreeNode * bst_get_node(int value);

	Status bst_make_node(BinarySearchTreeNode **node, int value);

	Status bst_insert(BinarySearchTree *bst, int value);

	//Status bst_remove(BinarySearchTree *bst, int value);

	// Unlink subtree from referenced node (removes link with parent)
	//Status bst_unlink(BinarySearchTreeNode *ref);

	Status bst_display(BinarySearchTree *bst);
	Status bst_display_raw(BinarySearchTreeNode *root);

	//Status bst_delete(BinarySearchTree **bst);
	//Status bst_erase(BinarySearchTree **bst);

	bool bst_is_empty(BinarySearchTree *bst);

	Status bst_traversal_wrapper(BinarySearchTree *bst, int traversal);
	Status bst_traversal_preorder(BinarySearchTreeNode *bst);
	Status bst_traversal_inorder(BinarySearchTreeNode *bst);
	Status bst_traversal_postorder(BinarySearchTreeNode *bst);
	
#ifdef __cplusplus
}
#endif;
