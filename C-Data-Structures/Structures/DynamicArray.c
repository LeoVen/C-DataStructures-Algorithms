/*
 * DynamicArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Dynamic Array Implementations in C
 *
 * Dynamic Array grows and shrinks as you add and remove values
 */

#include "..\Headers\DynamicArray.h"

 // +-------------------------------------------------------------------------------------------------+
 // |                                             Getters                                             |
 // +-------------------------------------------------------------------------------------------------+

int initDArray(DynamicArray **array, int maxSize)
{
	(*array) = malloc(sizeof(DynamicArray));
	(*array)->buffer = malloc(sizeof(int) * maxSize);
	(*array)->size = 0;
	(*array)->threshold = false;
	(*array)->maxSize = maxSize;
	return 0;
}

DynamicArray * getDArray(int maxSize)
{
	if (maxSize < 0) {
		printf("\nFATAL ERROR\n");
		return NULL;
	}
	DynamicArray *newArr = malloc(sizeof(DynamicArray));
	newArr->size = 0;
	newArr->maxSize = maxSize;
	newArr->threshold = false;
	newArr->buffer = malloc(sizeof(int) * maxSize);
	return newArr;
}

int pushValueDArray(DynamicArray **array, int value)
{
	adjustSize(array);
	(*array)->buffer[(*array)->size] = value;
	((*array)->size)++;
	return 0;
}

int popValueDArray(DynamicArray **array)
{
	adjustSize(array);
	(*array)->buffer[(*array)->size] = 0;
	((*array)->size)--;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayDArray(DynamicArray *array)
{
	int i;
	if (array->size == 0) {
		printf("\n[ Empty ] \n");
		return 1;
	}
	printf("\nD Array\n[ ");
	for (i = 0; i < array->size; i++) {
		printf("%d, ", array->buffer[i]);
	}
	printf("nil ]\n");
	return 0;
}

int displayRawDArray(DynamicArray *array)
{
	int i;
	if (array->size == 0) {
		printf("\n[ Empty ] \n");
		return 1;
	}
	printf("\n");
	for (i = 0; i < array->size; i++) {
		printf("%d ", array->buffer[i]);
	}
	printf("\n");
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Dynamic                                             |
// +-------------------------------------------------------------------------------------------------+

int adjustSize(DynamicArray **arr)
{
	int i;
	if ((*arr)->size > (*arr)->maxSize / 2) (*arr)->threshold = true;
	if ((*arr)->size >= (*arr)->maxSize - 1) {
		// Grow
		return growDArray(arr);
	}
	else if ((*arr)->threshold && (*arr)->size < (*arr)->maxSize / 2) {
		// Shrink
		return shrinkDArray(arr);
	}
	else {
		// OK
		return 0;
	}
}

int shrinkDArray(DynamicArray **arr)
{
	int i;
	DynamicArray *nArray = getDArray((*arr)->maxSize / 2 + 1);
	DynamicArray *kill = (*arr);
	// Copy values
	for (i = 0; i < (*arr)->size; i++) {
		nArray->buffer[i] = (*arr)->buffer[i];
	}
	nArray->size = (*arr)->size;
	nArray->threshold = false;
	(*arr) = nArray;
	// Free old array
	free(kill);
	return 0; // OK
}

int growDArray(DynamicArray **arr)
{
	int i;
	DynamicArray *nArray = getDArray((*arr)->maxSize * 2);
	DynamicArray *kill = (*arr);
	// Copy values
	for (i = 0; i < (*arr)->size; i++) {
		nArray->buffer[i] = (*arr)->buffer[i];
	}
	nArray->size = (*arr)->size;
	nArray->threshold = false;
	*arr = nArray;
	// Free old array
	free(kill);
	return 0; // OK
}