/**
 * @file Array.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 19/03/2018
 *
 * @brief Source file for @c Array implementations in C
 *
 */

 /*
 Return Codes

 -1 - Array Erased
 0 - Success
 1 - Invalid Position
 2 - Position already initialized (use update function)
 3 - Position not initialized (use insert function)
 4 - Position already empty
 5 - Array is full

 */

#include "..\Headers\Array.h"

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

	int i;
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

	int i;

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

	int i;

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

Status arr_erase(Array *array)
{
	int i;

	for (i = 0; i < array->size; i++) {
	
		array->buffer[i] = 0;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

// +-------------------------------------------------------------------------------------------------+
// |                                         Slice / Link                                            |
// +-------------------------------------------------------------------------------------------------+

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

	int i;
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

	int i;
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

	int i;

	int loop = arr->size * 100;
	for (i = 0; i < loop; i++) {

		arr_switch(arr, (size_t)rand() % arr->size, (size_t)rand() % arr->size);
	}

	return DS_OK;
}

/*

int bubbleSortCArray(Array *array)
{
	int i, j;
	for (i = 0; i < array->size - 1; i++) {
		for (j = 0; j < array->size - i - 1; j++) {
			if (array->buffer[j] > array->buffer[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
	return 0;
}

int selectionSortCArray(Array *array)
{
	int i, j, min;
	for (i = 0; i < array->size - 1; i++) {
		min = i;
		for (j = i + 1; j < array->size; j++)
			if (array->buffer[j] < array->buffer[min]) min = j;
		swap(array, min, i);
	}
	return 0;
}

int insertionSortCArray(Array *array)
{
	int i, j, num;
	for (i = 1; i < array->size; i++) {
		num = array->buffer[i];
		j = i - 1;
		while (j >= 0 && array->buffer[j] > num)
		{
			array->buffer[j + 1] = array->buffer[j];
			j--;
		}
		array->buffer[j + 1] = num;
	}
	return 0;
}

int valueOcurranceCArray(Array *array, int value)
{
	int i, total = 0;
	for (i = 0; i < array->size; i++) {
		if (array->buffer[i] == value) total++;
	}
	return total;
}

Array * valuePositionsCArray(Array *array, int value)
{
	int i, j = 0;
	int total = valueOcurranceCArray(array, value);
	Array *resultArray = getCArray(total);
	for (i = 0; i < array->size; i++) {
		if (array->buffer[i] == value) {
			// Hopefully this won't overflow
			resultArray->buffer[j] = i;
			j++;
		}
	}
	return resultArray;
}

int findMinCArray(Array *array)
{
	int i;
	int min = array->buffer[0];
	for (i = 1; i < array->size; i++) {
		if (array->buffer[i] < min) {
			min = array->buffer[i];
		}
	}
	return min;
}

int findMaxCArray(Array *array)
{
	int i;
	int max = array->buffer[0];
	for (i = 1; i < array->size; i++) {
		if (array->buffer[i] > max) {
			max = array->buffer[i];
		}
	}
	return max;
}


*/