/*
 * DArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Dynamic Array Implementations in C
 *
 * Dynamic Array grows and shrinks as you add and remove values
 */

#include "..\Headers\DArray.h"

 // +-------------------------------------------------------------------------------------------------+
 // |                                             Getters                                             |
 // +-------------------------------------------------------------------------------------------------+

int initDArray(DArray **array, int maxSize)
{
	(*array) = malloc(sizeof(DArray));
	(*array)->array = malloc(sizeof(int) * maxSize);
	(*array)->size = 0;
	(*array)->threshold = false;
	(*array)->maxSize = maxSize;
	return 0;
}

DArray * getDArray(int maxSize)
{
	if (maxSize < 0) {
		printf("\nFATAL ERROR\n");
		return NULL;
	}
	DArray *newArr = malloc(sizeof(DArray));
	newArr->size = 0;
	newArr->maxSize = maxSize;
	newArr->threshold = false;
	newArr->array = malloc(sizeof(int) * maxSize);
	return newArr;
}

int pushValueDArray(DArray **array, int value)
{
	adjustSize(array);
	(*array)->array[(*array)->size] = value;
	((*array)->size)++;
	return 0;
}

int popValueDArray(DArray **array)
{
	adjustSize(array);
	(*array)->array[(*array)->size] = 0;
	((*array)->size)--;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayDArray(DArray *array)
{
	int i;
	if (array->size == 0) {
		printf("\n[ Empty ] \n");
		return 1;
	}
	printf("\nD Array\n[ ");
	for (i = 0; i < array->size; i++) {
		printf("%d, ", array->array[i]);
	}
	printf("nil ]\n");
	return 0;
}

int displayRawDArray(DArray *array)
{
	int i;
	if (array->size == 0) {
		printf("\n[ Empty ] \n");
		return 1;
	}
	printf("\n");
	for (i = 0; i < array->size; i++) {
		printf("%d ", array->array[i]);
	}
	printf("\n");
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Dynamic                                             |
// +-------------------------------------------------------------------------------------------------+

int adjustSize(DArray **arr)
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

int shrinkDArray(DArray **arr)
{
	int i;
	DArray *nArray = getDArray((*arr)->maxSize / 2 + 1);
	DArray *kill = (*arr);
	// Copy values
	for (i = 0; i < (*arr)->size; i++) {
		nArray->array[i] = (*arr)->array[i];
	}
	nArray->size = (*arr)->size;
	nArray->threshold = false;
	(*arr) = nArray;
	// Free old array
	free(kill);
	return 0; // OK
}

int growDArray(DArray **arr)
{
	int i;
	DArray *nArray = getDArray((*arr)->maxSize * 2);
	DArray *kill = (*arr);
	// Copy values
	for (i = 0; i < (*arr)->size; i++) {
		nArray->array[i] = (*arr)->array[i];
	}
	nArray->size = (*arr)->size;
	nArray->threshold = false;
	*arr = nArray;
	// Free old array
	free(kill);
	return 0; // OK
}