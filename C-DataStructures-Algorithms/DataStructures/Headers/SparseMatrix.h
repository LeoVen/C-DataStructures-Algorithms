/**
 * @file SparseMatrix.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/05/2018
 *
 * @brief Header file for @c SparseMatrix implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

	/**
	 * Sparse Matrix using @c DoublyLinkedList.
	 */
	typedef struct SparseMatrixNode
	{
		int data;							/*!< Node's data */
		int x;								/*!< X coordinate */
		int y;								/*!< Y coordinate */
		struct SparseMatrixNode *x_ptr_pos; /*!< Pointer towards the positive side of x */
		struct SparseMatrixNode *x_ptr_neg; /*!< Pointer towards the negative side of x */
		struct SparseMatrixNode *y_ptr_pos; /*!< Pointer towards the positive side of y */
		struct SparseMatrixNode *y_ptr_neg; /*!< Pointer towards the negative side of y */
	} SparseMatrixNode;

	/**
	 * Sparse Matrix using a matrix of @c DoublyLinkedList with slightly
	 * modified nodes.
	 *
	 * @see Principal component analysis
	 */
	typedef struct SparseMatrix
	{
		struct SparseMatrixNode *center; /*!< Pointer to the node at the center of the matrix ( 0 , 0 ) */
		struct SparseMatrixNode *x_pos;  /*!< End of X axis towards the Positive direction */
		struct SparseMatrixNode *x_neg;  /*!< End of X axis towards the Negative direction */
		struct SparseMatrixNode *y_pos;  /*!< End of y axis towards the Positive direction */
		struct SparseMatrixNode *y_neg;  /*!< End of y axis towards the Negative direction */
		size_t elements;				 /*!< Number of elements in the @c SparseMatrix */
	} SparseMatrix;

	Status spm_init_matrix(SparseMatrix **spm);

	Status spm_init_node(SparseMatrixNode **node, int x, int y, int data);

	// Note: Inserting value 0 equals deleting that node. Cannot insert 0 at origin.
	//Status spm_insert(SparseMatrix *spm, int x, int y, int data);

	//Status spm_insert_row(SparseMatrix *spm, int y_pos, int x_from, int x_to);
	//Status spm_insert_col(SparseMatrix *spm, int x_pos, int y_from, int y_to);

	//Status spm_remove(SparseMatrix *spm, int x, int y);
	//Status spm_remove_row(SparseMatrix *spm, int row);
	//Status spm_remove_col(SparseMatrix *spm, int col);

	//Status spm_display(SparseMatrix *spm);
	//Status spm_display_raw(SparseMatrix *spm);

	//Status spm_delete(SparseMatrix **spm);

	//Status spm_exists(SparseMatrix *spm, int x, int y);

	//Status spm_find_max_x(SparseMatrix *spm, int *result);
	//Status spm_find_min_x(SparseMatrix *spm, int *result);

	//Status spm_find_max_y(SparseMatrix *spm, int *result);
	//Status spm_find_min_y(SparseMatrix *spm, int *result);

	//Status spm_goto(SparseMatrixNode **x_node, SparseMatrixNode **y_node, int x_pos, int y_pos);

	//Status spm_grow(SparseMatrix *spm, int x, int y);

#ifdef __cplusplus
}
#endif;