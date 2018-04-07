/*
 * DynamicArrayTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Test Cases for Dynamic Array Implementations in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
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