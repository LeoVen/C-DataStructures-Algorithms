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

	DynamicArray *arr, *array;

	darr_init(&array, 100);
	darr_init(&arr, 100);

	int i;
	for (i = 0; i < 200; i++) {
		darr_push(&array, i);
		darr_push(&arr, i);
	}

	darr_display(arr);

	for (i = 0; i < 200; i++) {
		darr_pop(&array);
		darr_pop(&arr);
	}

	darr_display_raw(arr);

	printf("\n");
	return 0;
}