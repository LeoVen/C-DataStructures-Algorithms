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

	Array *array = getCArray(10);

	int i;
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i+1);
	}

	displayCArray(array);
	printf("\nCode: %d\n", pushValueCArray(array, 11)); // 5

	for (i = 0; i < array->size; i++) {
		removeValueCArray(array, i);
	}
	
	displayCArray(array);

	printf("\nCode: %d", removeValueCArray(array, -1)); // 1
	printf("\nCode: %d\n", insertValueCArray(array, -1, 1)); // 1

	// Erase
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i + 1);
	}
	eraseCArray(array);
	displayCArray(array); // Should give all 0s

	// Switching
	Array *arr = getCArray(13);
	for (i = 0; i < arr->size; i++) {
		insertValueCArray(arr, i, i + 1);
	}
	displayCArray(arr);
	for (i = 0; i < arr->size / 2; i++) {
		switchValuesCArray(arr, i, arr->size - i - 1);
	}

	displayCArray(arr);

	// Or simply...
	reverseCArray(arr);

	displayCArray(arr);
	
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
	return 0;
}