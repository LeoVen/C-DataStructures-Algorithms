/*
 * DArray.h
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Header for Dynamic Array in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct DArray {
		int *array;     // Array of integers
		int size;       // Actual Size
		int maxSize;    // Maximum size.
		bool threshold; // maxSize / 2
	} DArray;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+

	int initDArray(DArray **array, int maxSize);

	// +-------------------------------------+
	// |              Getters                |
	// +-------------------------------------+
	DArray * getDArray(int maxSize);

	// +-------------------------------------+
	// |             Push / Pop              |
	// +-------------------------------------+
	int pushValueDArray(DArray **array, int value);
	int popValueDArray(DArray **array);

	// +-------------------------------------+
	// |          Insert / Remove            |
	// +-------------------------------------+
	int insertValueDArray(DArray *array, int position, int value);
	int removeValueDArray(DArray *array, int position);

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseDArray(DArray *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	/* Displays array in the console
	 *
	 * @Param [ DArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayDArray(DArray *array);

	/* Displays only numbers of array in the console
	 *
	 * @Param [ DArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayRawDArray(DArray *array);

	// +-------------------------------------+
	// |              Dynamic                |
	// +-------------------------------------+
	/* Checks if the array needs to be adjusted (for push and pop)
	 *
	 * @Param [ DArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int adjustSize(DArray **array);

	/* Makes a bigger copy of current array and frees the memory of the old one
	 *
	 * @Param [ DArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int growDArray(DArray **arr);

	/* Makes a smaller copy of current array and frees the memory of the old one
	 *
	 * @Param [ DArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int shrinkDArray(DArray **arr);

#ifdef __cplusplus
}
#endif