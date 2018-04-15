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

	int i;
	SinglyLinkedList *sll;
	sll_init_list(&sll);
	
	for (i = 0; i < 10; i++)
		sll_insert_tail(sll, i);

	Array *array;
	printf("\n%s", status_repr(convert_sll_to_arr(sll, &array)));
	
	arr_display(array);

	// Not working... see line 26 in DynamicArray.c
	/*
	DynamicArray *darray;

	printf("\n%s", status_repr(convert_sll_to_darr(sll, &darray)));

	darr_display(darray);

	for (i = 0; i < 20; i++)
		darr_push(&darray, 99);

	
	sll_delete_list(&sll);

	convert_darr_to_sll(darray, &sll);

	sll_display_raw(&sll);

	arr_delete(array);

	convert_sll_to_arr(sll, &array);

	darr_delete(darray);

	convert_arr_to_darr(array, &darray);

	darr_display(darray);
	*/
	printf("\n");
	return 0;
}