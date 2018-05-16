/**
 * @file SparseMatrix.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/05/2018
 *
 * @brief Source file for @c SparseMatrix implementations in C
 *
 */

#include "..\Headers\SparseMatrix.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status spm_init_matrix(SparseMatrix **spm)
{
	(*spm) = malloc(sizeof(SparseMatrix));

	if (!(*spm))
		return DS_ERR_ALLOC;

	SparseMatrixNode *center;

	Status st = spm_init_node(&center, 0, 0, 0);

	if (st != DS_OK)
		return st;

	(*spm)->center = center;
	
	(*spm)->x_pos = center;
	(*spm)->x_neg = center;
	(*spm)->y_pos = center;
	(*spm)->y_neg = center;

	(*spm)->elements = 0;

	return DS_OK;
}

Status spm_init_node(SparseMatrixNode **node, int x, int y, int data)
{
	(*node) = malloc(sizeof(SparseMatrixNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->x = x;
	(*node)->y = y;

	(*node)->data = data;

	(*node)->x_ptr_pos = NULL;
	(*node)->x_ptr_neg = NULL;
	(*node)->y_ptr_pos = NULL;
	(*node)->y_ptr_neg = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

//Status spm_insert(SparseMatrix *spm, int x, int y, int data);
//Status spm_insert_row(SparseMatrix *spm, int y_pos, int x_from, int x_to);
//Status spm_insert_col(SparseMatrix *spm, int x_pos, int y_from, int y_to);

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status spm_remove(SparseMatrix *spm, int x, int y);
//Status spm_remove_row(SparseMatrix *spm, int row);
//Status spm_remove_col(SparseMatrix *spm, int col);

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

//Status spm_display(SparseMatrix *spm);
//Status spm_display_raw(SparseMatrix *spm);

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status spm_delete(SparseMatrix **spm);

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

/**
 * Checks if a given (x,y) coordinate already exists
 */
//Status spm_exists(SparseMatrix *spm, int x, int y);

//Status spm_find_max_x(SparseMatrix *spm, int *result);
//Status spm_find_min_x(SparseMatrix *spm, int *result);

//Status spm_find_max_y(SparseMatrix *spm, int *result);
//Status spm_find_min_y(SparseMatrix *spm, int *result);


// +-------------------------------------------------------------------------------------------------+
// |                                            Utility                                              |
// +-------------------------------------------------------------------------------------------------+

/**
 * This function returns two pointers to nodes of x and y positions
 * If insert is true then new nodes will be added to the axes until the
 * necessary x and/or y positions are met. If false, then its removing a node
 * so if either x or y axis reaches an end before finding a node then its an
 * invalid (x,y) coordinate.
 */
//Status spm_goto(SparseMatrixNode **x_node, SparseMatrixNode **y_node, int x_pos, int y_pos);

/**
 * Grows both axes (Linked Lists)
 */
//Status spm_grow(SparseMatrix *spm, int x, int y);
