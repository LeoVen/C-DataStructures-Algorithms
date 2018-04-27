/**
 * @file C-DataStructures-Algorithms.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 04/04/2018
 *
 * @brief Entry point for project.
 *
 * C-DataStructures-Algorithms is a project for implementing data structures and algorithms purely in C.
 *
 */

#include "Core\DataStructures.h"
#include "Core\Algorithms.h"

int main()
{
	srand(time(NULL));

	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" |                   C Data Structures and Algorithms                 |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" |    by Leonardo Vencovsky                                           |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");

	DataStructuresMenu();
	AlgorithmsMenu();

	printf("\n");
    return 0;
}

