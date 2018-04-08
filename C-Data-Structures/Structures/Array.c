/**
 * @file Array.c
 *
 * @author Leonardo Vencovsky
 * @date 19/03/2018
 *
 * @brief Array Implementations in C
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

Array * getCArray(int size)
{
	Array *array = malloc(sizeof(Array));
	array->buffer = malloc(sizeof(int) * size);
	array->size = size;
	int i;
	for (i = 0; i < size; i++) {
		array->buffer[i] = 0;
	}
	return array;
}

int insertValueCArray(Array *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->buffer[position] == 0) {
			array->buffer[position] = value;
			return 0; // OK
		}
		else return 2; // Position already initialized (use update function)
	}
	return 1; // Invalid position
}

int removeValueCArray(Array *array, int position)
{
	if (position >= 0 && position < array->size) {
		if (array->buffer[position] != 0) {
			array->buffer[position] = 0;
		}
		else return 4; // Position already empty
	}
	return 1; // Invalid position
}

int pushValueCArray(Array *array, int value)
{
	int i;
	int ok = 0;
	for (i = 0; i < array->size; i++) {
		if (array->buffer[i] == 0) {
			array->buffer[i] = value;
			ok = 1;
			break;
		}
	}
	if (ok == 1) return 0;
	else return 5; // Array is full
}

int updateValueCArray(Array *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->buffer[position] != 0) {
			array->buffer[position] = value;
		}
		else return 3; // Position not initialized (use insert function)
	}
	return 1; // Invalid Position
}

int eraseCArray(Array *array)
{
	int i;
	for (i = 0; i < array->size; i++) {
		array->buffer[i] = 0;
	}
	return 0;
}

int switchValuesCArray(Array *array, int position1, int position2)
{
	if (position1 >= 0 && position1 < array->size 
		&& position2 >= 0 && position2 < array->size) {
		int temp = array->buffer[position1];
		array->buffer[position1] = array->buffer[position2];
		array->buffer[position2] = temp;
	}
	return 1; // Invalid Position
}

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