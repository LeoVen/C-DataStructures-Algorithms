/**
 * @file Dev.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 04/04/2018
 *
 * @brief Source File for quick launch of functions and tests
 *
 */

#include "Core.h"
#include "AlgorithmsTests.h"
#include "DataStructuresTests.h"
#include "DataStructuresInteractive.h"

int dev_short_cut(void)
{

	SinglyLinkedListInteractive();

	printf("\nPress enter to continue...");
	_getch();
	printf("\n");
	return 0;
}