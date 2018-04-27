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

	cbf_init(&cbf, 20);

	printf("\nLength: %zu", cbf->length);

	printf("\n");
	return 0;
}