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

void swap(Array *array, int position1, int position2);

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status arr_init_array(Array **arr, size_t size)
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

Array * arr_get_array(size_t size)
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

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status arr_erase_array(Array *array)
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

	arr_init_array(result, arr->size);

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

// int switchValuesCArray(Array *array, int position1, int position2)
Status arr_switch_values(Array *arr, size_t pos1, size_t pos2)
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


/*
int reverseCArray(Array *array)
{
	int i;
	for (i = 0; i < array->size / 2; i++) {
		swap(array, i, array->size - i - 1);
	}
	return 0;
}

int displayCArray(Array *array)
{
	int i;
	printf("\nC ARRAY\n[ ");
	for (i = 0; i < array->size; i++) {
		printf("%d, ", array->buffer[i]);
	}
	printf("nil ]\n");
	return 0;
}

int displayRawCArray(Array *array)
{
	int i;
	printf("\n");
	for (i = 0; i < array->size; i++) {
		printf("%d ", array->buffer[i]);
	}
	printf("\n");
	return 0;
}

int blenderCArray(Array *array)
{
	srand(time(NULL) * array->size);
	int i;
	int total = array->size * 100;
	for (i = 0; i < total; i++) {
		swap(array, rand() % array->size, rand() % array->size);
	}
	return 0;
}

Array * getCopyCArray(Array *arr)
{
	Array *array = malloc(sizeof(Array));
	array->buffer = malloc(sizeof(int) * arr->size);
	array->size = arr->size;
	int i;
	for (i = 0; i < arr->size; i++) {
		array->buffer[i] = arr->buffer[i];
	}
	return array;
}

void swap(Array *array, int position1, int position2)
{
	int temp = array->buffer[position1];
	array->buffer[position1] = array->buffer[position2];
	array->buffer[position2] = temp;
}

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