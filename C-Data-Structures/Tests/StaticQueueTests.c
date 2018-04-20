/**
 * @file StaticQueueTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c StaticQueue implementations in C
 *
 */

#include "..\Headers\StaticQueue.h"

int StaticQueueTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Static Queue           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	StaticQueue *squ;

	que_stc_init(&squ, 20);

	printf("\nLength: %zu", squ->length);

	printf("\n");
	return 0;
}