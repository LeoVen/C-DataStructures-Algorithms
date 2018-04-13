/**
 * @file SortingTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 19/03/2018
 *
 * @brief Sorting Tests to really push up the boundries
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "..\Headers\Array.h"

int SortingTests() {

	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Sorting              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	/*
	int i;

	// Testing limits of Insertion Sort
	Array *earray = getCArray(100000);
	for (i = 0; i < earray->size; i++) {
		insertValueCArray(earray, i, rand());
	}

	printf("\nInsertion Sort:");
	clock_t begin = clock();
	// Timing insertion sort
	insertionSortCArray(earray);
	clock_t end = clock();
	double time_spent4 = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nTotal time spent for insertion sort: %lf seconds", time_spent4);
	// displayCArray(earray);

	free(earray);

	*/
	return 0;
}