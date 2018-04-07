/*
 * DynamicArray.h
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

	typedef struct DynamicArray {
		int *buffer;    // Array of integers
		int size;       // Actual Size
		int maxSize;    // Maximum size.
		bool threshold; // maxSize / 2
	} DynamicArray;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+

	int initDArray(DynamicArray **array, int maxSize);

	// +-------------------------------------+
	// |              Getters                |
	// +-------------------------------------+
	DynamicArray * getDArray(int maxSize);

	// +-------------------------------------+
	// |             Push / Pop              |
	// +-------------------------------------+
	int pushValueDArray(DynamicArray **array, int value);
	int popValueDArray(DynamicArray **array);

	// +-------------------------------------+
	// |          Insert / Remove            |
	// +-------------------------------------+
	int insertValueDArray(DynamicArray *array, int position, int value);
	int removeValueDArray(DynamicArray *array, int position);

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseDArray(DynamicArray *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	/* Displays array in the console
	 *
	 * @Param [ DynamicArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayDArray(DynamicArray *array);

	/* Displays only numbers of array in the console
	 *
	 * @Param [ DynamicArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayRawDArray(DynamicArray *array);

	// +-------------------------------------+
	// |              Dynamic                |
	// +-------------------------------------+
	/* Checks if the array needs to be adjusted (for push and pop)
	 *
	 * @Param [ DynamicArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int adjustSize(DynamicArray **array);

	/* Makes a bigger copy of current array and frees the memory of the old one
	 *
	 * @Param [ DynamicArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int growDArray(DynamicArray **arr);

	/* Makes a smaller copy of current array and frees the memory of the old one
	 *
	 * @Param [ DynamicArray **array ] Reference to array
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int shrinkDArray(DynamicArray **arr);

#ifdef __cplusplus
}
#endif