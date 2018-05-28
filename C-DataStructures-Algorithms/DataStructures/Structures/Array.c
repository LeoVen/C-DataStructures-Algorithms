/**
 * @file Array.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 19/03/2018
 *
 * @brief Source file for @c Array implementations in C
 *
 */

#include "Array.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status arr_init(Array **arr, size_t size)
{
	(*arr) = malloc(sizeof(Array));

	if (!(*arr))
		return DS_ERR_ALLOC;

	(*arr)->buffer = calloc(size, sizeof(int));

	if (!(*arr)->buffer)
		return DS_ERR_ALLOC;
	
	(*arr)->size = size;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Array * arr_get(size_t size)
{
	Array *arr;

	arr = malloc(sizeof(Array));

	arr->buffer = calloc(size, sizeof(int));

	return arr;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status arr_insert(Array *arr, size_t position, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (position >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[position] == 0) {

		arr->buffer[position] = value;

		return DS_OK;

	}

	return DS_ERR_INVALID_OPERATION;
}

Status arr_push(Array *arr, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	int ok = 0;

	for (i = 0; i < arr->size; i++) {
	
		if (arr->buffer[i] == 0) {
		
			arr->buffer[i] = value;
			
			ok = 1;
			break;
		}
	}

	if (ok == 1)
		return DS_OK;

	return DS_ERR_FULL;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Update                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_update(Array *arr, size_t position, int value)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (position >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[position] != 0) {

		arr->buffer[position] = value;

		return DS_OK;

	}
	
	return DS_ERR_INVALID_OPERATION;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status arr_remove(Array *arr, size_t position)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (position >= arr->size)
		return DS_ERR_INVALID_POSITION;

	if (arr->buffer[position] != 0) {
		
		arr->buffer[position] = 0;
	
	}
	
	return DS_ERR_INVALID_OPERATION;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status arr_display(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;

	printf("\nC Array\n[ ");
	
	for (i = 0; i < arr->size; i++) {
	
		printf("%d, ", arr->buffer[i]);
	}

	printf("nil ]\n");
	
	return DS_OK;
}

Status arr_display_raw(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;

	printf("\n");

	for (i = 0; i < arr->size; i++) {

		printf("%d ", arr->buffer[i]);
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_erase(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;

	for (i = 0; i < arr->size; i++) {
	
		arr->buffer[i] = 0;
	}

	return DS_OK;
}

Status arr_delete(Array **arr)
{
	if (*arr == NULL)
		return DS_ERR_NULL_POINTER;

	free((*arr)->buffer);
	free((*arr));

	(*arr) = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_max(Array *arr, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	int min = arr->buffer[0];

	for (i = 1; i < arr->size; i++) {

		if (arr->buffer[i] > min) {

			min = arr->buffer[i];

		}
	}

	*result = min;

	return DS_OK;
}

Status arr_min(Array *arr, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	int min = arr->buffer[0];

	for (i = 1; i < arr->size; i++) {

		if (arr->buffer[i] < min) {

			min = arr->buffer[i];

		}
	}

	*result = min;

	return DS_OK;
}

Status arr_frequency(Array *arr, int key, int *result)
{
	*result = 0;

	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < arr->size; i++) {
	
		if (arr->buffer[i] == key)
			(*result)++;

	}
	
	return DS_OK;
}

Status arr_key_positions(Array *arr, Array **result, int key)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i, j = 0;
	int val = 0, total = 0;

	Status st = arr_frequency(arr, key, &total);

	if (st != DS_OK)
		return st;

	st = arr_init(result, total);

	if (st != DS_OK)
		return st;

	for (i = 0; i < arr->size; i++) {

		if (arr->buffer[i] == key) {

			(*result)->buffer[j] = val;
			j++;
		}

		val++;
	}

	return DS_OK;
}

// bool arr_is_empty(Array *arr);

// +-------------------------------------------------------------------------------------------------+
// |                                   Slice / Link / Trim / Grow                                    |
// +-------------------------------------------------------------------------------------------------+

// Status arr_grow(Array **arr);
// Status arr_shrink(Array **arr);

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

Status arr_copy(Array *arr, Array **result)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	arr_init(result, arr->size);

	if (!(*result))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < arr->size; i++)
		(*result)->buffer[i] = arr->buffer[i];

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

Status arr_switch(Array *arr, size_t pos1, size_t pos2)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (pos1 >= arr->size || pos2 >= arr->size)
		return DS_ERR_INVALID_POSITION;

	int temp = arr->buffer[pos1];
	arr->buffer[pos1] = arr->buffer[pos2];
	arr->buffer[pos2] = temp;

	return DS_OK;
}

Status arr_reverse(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	size_t i;
	for (i = 0; i < arr->size / 2; i++) {

		st = arr_switch(arr, i, arr->size - i - 1);

		if (st != DS_OK)
			return st;

	}

	return DS_OK;
}

Status arr_blend(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i;

	size_t loop = arr->size * 100;
	for (i = 0; i < loop; i++) {

		arr_switch(arr, (size_t)rand() % arr->size, (size_t)rand() % arr->size);
	}

	return DS_OK;
}

Status arr_sort_bubble(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j;
	for (i = 0; i < arr->size - 1; i++) {

		for (j = 0; j < arr->size - i - 1; j++) {

			if (arr->buffer[j] > arr->buffer[j + 1]) {

				arr_switch(arr, j, j + 1);

			}
		}
	}

	return DS_OK;
}

Status arr_sort_selection(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j, min;

	for (i = 0; i < arr->size - 1; i++) {

		min = i;

		for (j = i + 1; j < arr->size; j++)
			if (arr->buffer[j] < arr->buffer[min])
				min = j;

		arr_switch(arr, min, i);
	}

	return DS_OK;
}

Status arr_sort_insertion(Array *arr)
{
	if (arr == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr->size < 2)
		return DS_ERR_INVALID_OPERATION;

	size_t i, j;
	int num;
	for (i = 1; i < arr->size; i++) {

		num = arr->buffer[i];

		j = i - 1;

		while (arr->buffer[j] > num)
		{
			arr->buffer[j + 1] = arr->buffer[j];
			j--;
		}

		arr->buffer[j + 1] = num;
	}

	return DS_OK;
}
