/**
 * @file DynamicArray.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Header file for Dynamic Array implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"

	typedef struct DynamicArray {
		int *buffer;       // Array of integers
		size_t size;       // Actual Size
		size_t maxSize;    // Maximum size.
		bool threshold;    // maxSize / 2
	} DynamicArray;

	Status darr_init(DynamicArray **darr, size_t size);

	DynamicArray * darr_get(size_t size);

	// Status darr_insert(DynamicArray **arr, size_t position, int value);
	Status darr_push(DynamicArray **darr, int value);

	// Status darr_remove(DynamicArray **darr, size_t position);
	Status darr_pop(DynamicArray **darr);

	Status darr_display(DynamicArray *darr);
	Status darr_display_raw(DynamicArray *darr);

	Status darr_erase(DynamicArray *darr);
	Status darr_delete(DynamicArray **darr);

	Status darr_resize(DynamicArray **darr);
	Status darr_shrink(DynamicArray **darr);
	Status darr_grow(DynamicArray **darr);

#ifdef __cplusplus
}
#endif