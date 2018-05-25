/**
 * @file BinaryTreeTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/05/2018
 *
 * @brief Test Cases for @c BinaryTree implementations in C
 *
 */

#include "..\Headers\BinaryTree.h"

int BinaryTreeTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Binary Tree            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	BinaryTree *root, *b_R, *b_L, *b_R_R, *b_R_L, *b_L_R, *b_L_L;

	bt_init_node(&root, 0);

	bt_init_node(&b_R, 2);
	bt_init_node(&b_L, 1);
	bt_init_node(&b_R_R, 22);
	bt_init_node(&b_R_L, 21);
	bt_init_node(&b_L_R, 12);
	bt_init_node(&b_L_L, 11);

	bt_insert(root, b_R, Right_bt);
	bt_insert(root, b_L, Left_bt);

	bt_insert(b_L, b_L_L, Left_bt);
	bt_insert(b_L, b_L_R, Right_bt);

	bt_insert(b_R, b_R_L, Left_bt);
	bt_insert(b_R, b_R_R, Right_bt);

	bt_insert(b_L_L, bt_get_node(111), Left_bt);
	bt_insert(b_L_L, bt_get_node(112), Right_bt);

	bt_insert(b_L_R, bt_get_node(121), Left_bt);
	bt_insert(b_L_R, bt_get_node(122), Right_bt);

	bt_insert(b_R_L, bt_get_node(211), Left_bt);
	bt_insert(b_R_L, bt_get_node(212), Right_bt);

	bt_insert(b_R_R, bt_get_node(221), Left_bt);
	bt_insert(b_R_R, bt_get_node(222), Right_bt);

	bt_display(root);
	printf("\n ---------- ---------- ---------- ----------");
	bt_display(b_R);
	printf("\n ---------- ---------- ---------- ----------");
	bt_display(b_L);

	printf("\nPreOrder InOrder and PostOrder traversals:\n");

	bt_traversal_preorder(root);
	printf("\n");
	bt_traversal_inorder(root);
	printf("\n");
	bt_traversal_postorder(root);

	// Almost right
	bt_delete(&b_L);
	bt_display(root);

	printf("\n");
	return 0;
}