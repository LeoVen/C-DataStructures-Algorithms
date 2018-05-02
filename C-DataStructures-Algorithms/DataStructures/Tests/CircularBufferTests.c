/**
 * @file CircularBufferTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c CircularBuffer implementations in C
 *
 */

#include "..\Headers\CircularBuffer.h"

int CircularBufferTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |          C Circular Buffer          |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CircularBuffer *cbf;

	cbf_init(&cbf, 6);

	// Testing wrap
	int i, j;
	for (i = 0; i < 12; i++) {
		cbf_display(cbf);
		if (i % 2 == 0)
			cbf_add(cbf, i);
		else
			cbf_remove(cbf, &j);
	}

	cbf_display(cbf);

	for (i = 0; i < 100; i++) {
		cbf_add(cbf, 0); // Adding 0's that don't count as empty
	}

	// Should print DS_OK in a total of the buffer length
	for (i = 0; i < 10; i++) {
		if (cbf_remove(cbf, &j) == DS_OK)
			printf("\nBuffer Length: %zu, Value removed: %d", cbf->length, j);
	}

	cbf_erase(&cbf);

	cbf_display(cbf);

	cbf_delete(&cbf);

	printf("\n");
	return 0;
}