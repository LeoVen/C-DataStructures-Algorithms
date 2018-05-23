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

int dev_short_cut()
{

	BinaryTreeTests();
	BinarySearchTreeTests();

	printf("\nPress enter to continue...");
	getch();
	printf("\n");
	return 0;
}