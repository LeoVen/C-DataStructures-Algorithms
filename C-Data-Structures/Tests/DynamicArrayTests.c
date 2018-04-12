/**
 * @file DynamicArrayTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Test Cases for @c DynamicArray implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "..\Headers\DynamicArray.h"

int DynamicArrayTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |           C Dynamic Array           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	DynamicArray *array = getDArray(100);

	DynamicArray *arr;
	initDArray(&arr, 100);

	int i;
	for (i = 0; i < 200; i++) {
		pushValueDArray(&array, i);
		pushValueDArray(&arr, i);
	}
	displayDArray(array);
	for (i = 0; i < 200; i++) {
		popValueDArray(&array);
		popValueDArray(&arr);
	}
	displayDArray(arr);

	printf("\n");
	return 0;
}