/**
 * @file StructureConversionsTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/04/2018
 *
 * @brief Test Cases for Structure Conversions in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "..\Headers\StructureConversions.h"

int StructureConversionsTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |          C Conversion Tests         |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");
	/*
	int i;
	SinglyLinkedList *sll;
	initListSLL(&sll);
	
	for (i = 0; i < 10; i++) {
		insertTailSLL(&sll, i);
	}

	Array *array;
	printf("\n%s", status_repr(convert_sll_to_array(sll, &array)));
	
	displayCArray(array);

	DynamicArray *darray;

	printf("\n%s", status_repr(convert_sll_to_darray(sll, &darray)));

	displayDArray(darray);

	for (i = 0; i < 20; i++)
		pushValueDArray(&darray, 99);

	
	free(sll);

	convert_darray_to_sll(darray, &sll);

	displayListSLL(&sll);

	free(array);

	convert_sll_to_array(sll, &array);

	free(darray);

	convert_array_to_darray(array, &darray);

	displayDArray(darray);
	*/
	printf("\n");
	return 0;
}