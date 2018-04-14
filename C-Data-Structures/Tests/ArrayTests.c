/**
 * @file ArrayTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 19/03/2018
 *
 * @brief Test Cases for @c Array implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "..\Headers\Array.h"

int ArrayTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Array               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	
	Array *array;

	size_t size = 100;

	arr_init(&array, size);
	
	int i;
	size_t t;
	for (t = 0; t < array->size; t++) {
		arr_insert(array, t, t + 1);
	}

	// Copy
	Array *arr;
	arr_copy(array, &arr);

	// Reverse copy
	arr_reverse(arr);

	arr_display_raw(array);  // Original
	arr_display_raw(arr);    // Reversed

	print_status_repr(arr_push(array, 11)); // DS_ERR_FULL

	for (i = 0; i < array->size; i++) {
		arr_remove(array, i);
	}
	
	arr_display_raw(array); // All 0's

	print_status_repr(arr_remove(array, -1));    // DS_ERR_INVALID_POSITION
	print_status_repr(arr_insert(array, -1, 1)); // DS_ERR_INVALID_POSITION

	// Erase
	for (i = 0; i < array->size; i++) {
		arr_insert(array, i, i + 1);
	}

	arr_erase(array);

	arr_display_raw(array); // Should give all 0s

	/*
	
	// Sorting
	srand(time(NULL));
	Array *barray = getCArray(20);
	for (i = 0; i < barray->size; i++) {
		insertValueCArray(barray, i, rand());
	}
	Array *carray = getCopyCArray(barray);
	Array *darray = getCopyCArray(barray);
	printf("\nNot sorted Array:");
	displayCArray(barray);

	printf("\nBubble Sort:");
	clock_t begin1 = clock();
	// Timing bubble sort
	bubbleSortCArray(barray);
	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	displayCArray(barray);

	printf("\nSelection Sort:");
	clock_t begin2 = clock();
	// Timing selection sort
	selectionSortCArray(carray);
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	displayCArray(carray);

	printf("\nInsertion Sort:");
	clock_t begin3 = clock();
	// Timing insertion sort
	insertionSortCArray(darray);
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	displayCArray(carray);

	// Descending order
	reverseCArray(barray);
	// displayCArray(barray);

//	printf("\nBlender:");
//	blenderCArray(barray);
//	displayCArray(barray);

	printf("\nTotal time spent for bubble sort: %lf seconds", time_spent1);
	printf("\nTotal time spent for selection sort: %lf seconds", time_spent2);
	printf("\nTotal time spent for insertion sort: %lf seconds", time_spent3);

	// Searching
	Array *aarray = getCArray(1000);
	for (i = 0; i < aarray->size; i++) {
		insertValueCArray(aarray, i, rand() % 100);
	}

	int j = 24;
	printf("\nOccurrences of the number %d in the array: %d", j, 
		valueOcurranceCArray(aarray, j));
	printf("\nAnd its positions:\n");
	Array *positions = valuePositionsCArray(aarray, j);
	displayCArray(positions);
	// This should all give value of j
	printf("\nAll %d s", j);
	for (i = 0; i < positions->size; i++) {
		printf("\nPosition %d has a value of %d", 
			positions->buffer[i], aarray->buffer[positions->buffer[i]]);
	}
	printf("\nThe list has a minimum value of %d and a maximum value of %d", 
		findMinCArray(aarray), findMaxCArray(aarray));
	insertionSortCArray(aarray);
	// displayCArray(aarray);
	
	printf("\n\nUpdate at specific location:\n");
	for (i = 5; i < 15; i++) {
		updateValueCArray(barray, i, 0);
	}
	updateValueCArray(barray, 10, 1); // Shouldn't pass since 0 == not init
	displayCArray(barray);

	free(arr);
	free(array);
	free(aarray);
	free(barray);
	free(carray);
	free(darray);
	printf("\n");

	*/
	return 0;
}