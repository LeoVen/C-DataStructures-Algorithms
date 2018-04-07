/*
 * CArray.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header file for Array implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct Array {
		int *buffer;
		int size;
	} Array;

	// +-------------------------------------+
	// |           Returns array             |
	// +-------------------------------------+
	Array * getCArray(int size);
	Array * getCopyCArray(Array *array);

	// +-------------------------------------+
	// |                CRUD                 |
	// +-------------------------------------+
	int insertValueCArray(Array *array, int position, int value);
	int removeValueCArray(Array *array, int position);
	int pushValueCArray(Array *array, int value);
	int updateValueCArray(Array *array, int position, int value);

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseCArray(Array *array);

	// +-------------------------------------+
	// |             Switching               |
	// +-------------------------------------+
	int switchValuesCArray(Array *array, int position1, int position2);
	int reverseCArray(Array *array);

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	int bubbleSortCArray(Array *array);
	int selectionSortCArray(Array *array);
	int insertionSortCArray(Array *array);
	int blenderCArray(Array *array);

	// +-------------------------------------+
	// |             Searching               |
	// +-------------------------------------+
	int valueOcurranceCArray(Array *array, int value);
	Array * valuePositionsCArray(Array *array, int value);
	int findMaxCArray(Array *array);
	int findMinCArray(Array *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	int displayCArray(Array *array);
	int displayRawCArray(Array *array);

#ifdef __cplusplus
}
#endif