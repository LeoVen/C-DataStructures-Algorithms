/**
 * @file AlgorithmsMenu.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Menu for Algorithms, containing Tests and Interactive Versions
 *
 */

#include "..\Core\Core.h"
#include "..\Core\AlgorithmsTests.h"

int AlgorithmsMenu()
{
	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                             Algorithms                             |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");

	GeneratorsTests();

	MathematicsTests();

	SortingTests();

	printf("\n");
	return 0;
}