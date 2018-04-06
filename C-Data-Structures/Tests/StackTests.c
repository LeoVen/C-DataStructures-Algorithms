/*
 * CStackTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 31/03/2018
 *
 * Test Cases for Stack in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\Stack.h"

int StackTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Stack               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Stack *stack;
	initCStack(&stack);

	int i;
	for (i = 0; i < 10; i++) {
		pushCStack(&stack, i);
	}
	displayCStack(&stack);

	for (i = 0; i < 5; i++) {
		sliceCStack(&stack);
	}
	displayCStack(&stack);

	free(stack);
	printf("\n");
	return 0;
}