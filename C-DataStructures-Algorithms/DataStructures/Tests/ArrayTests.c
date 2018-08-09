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

#include "Array.h"

int ArrayTests(void)
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
	for (t = 0, i= 0; t < array->size; t++, i++) {
		arr_insert(array, t, i + 1);
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

	// Erase
	for (i = 0; i < array->size; i++) {
		arr_insert(array, i, i + 1);
	}

	arr_erase(array);

	arr_display_raw(array); // Should give all 0s

	printf("Array is empty? %s\n", (arr_is_empty(array) ? "true" : "false"));
	
	// ---------- ---------- Bubble Sort
	// ---------- ----------
	for (i = 0; i < array->size; i++) {
		arr_insert(array, i, rand());
	}

	arr_display_raw(array); // Not sorted array

	printf("\nBubble Sort:");
	clock_t begin1 = clock();

	// Timing bubble sort
	arr_sort_bubble(array);

	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

	arr_display_raw(array); // Sorted array

	arr_erase(array);

	// ---------- ---------- Selection Sort
	// ---------- ----------
	for (i = 0; i < array->size; i++) {
		arr_insert(array, i, rand());
	}

	arr_display_raw(array); // Not sorted array

	printf("\nSelection Sort:");
	clock_t begin2 = clock();

	// Timing selection sort
	arr_sort_selection(array);

	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	
	arr_display_raw(array);

	arr_erase(array);

	// ---------- ---------- Insertion Sort
	// ---------- ----------
	for (i = 0; i < array->size; i++) {
		arr_insert(array, i, rand());
	}

	arr_display_raw(array); // Not sorted array
	
	printf("\nInsertion Sort:");
	clock_t begin3 = clock();

	// Timing insertion sort
	arr_sort_insertion(array);
	
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	
	arr_display_raw(array);

	printf("\nBlender:");
	arr_blend(array);
	arr_display(array);

	printf("\nTotal time spent for bubble sort: %lf seconds", time_spent1);
	printf("\nTotal time spent for selection sort: %lf seconds", time_spent2);
	printf("\nTotal time spent for insertion sort: %lf seconds", time_spent3);

	// Searching
	Array *sArray;
	Array *result;

	arr_init(&sArray, 1000);

	for (i = 0; i < sArray->size; i++) {
		arr_insert(sArray, i, rand() % 100);
	}

	int j = 24, freq = 0;

	arr_frequency(sArray, j, &freq); // Frequency

	printf("\nOccurrences of the number %d in the array: %d", j, freq);
	
	arr_key_positions(sArray, &result, j); // Positions of key value (j)
	
	printf("\nAnd its positions:\n");
	
	arr_display(result); // Result array of positions for key value (j)

	// This should all give value of j
	printf("\nAll %d s", j);
	for (i = 0; i < result->size; i++) {

		printf("\nPosition %d has a value of %d", 
			result->buffer[i], sArray->buffer[result->buffer[i]]);

	}

	// Min and Max
	int min = 0, max = 0;

	arr_min(array, &min);
	arr_max(array, &max);

	printf("\nThe list has a minimum value of %d and a maximum value of %d", min, max);

	arr_sort_insertion(array);

	arr_display(array);
	
	printf("\n\nUpdate at specific location:\n");
	for (t = 5; t < 15; t++) {
		arr_update(array, t, 0);
	}

	print_status_repr(arr_update(array, 10, 1)); // DS_ERR_INVALID_OPERATION

	arr_display(array);

	arr_delete(&arr);
	arr_delete(&array);
	arr_delete(&sArray);

	printf("\n");
	return 0;
}