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

#include "DataStructures.h"
#include "Algorithms.h"

int dev_short_cut(void);

int main(void)
{

	// Checking memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand((unsigned int)time(NULL));

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

	int ds_alg;

	while (true)
	{
		printf(" +--------------------------------------------------------------------+\n");
		printf(" |                                                                    |\n");
		printf(" |                           Select Menu                              |\n");
		printf(" |                                                                    |\n");
		printf(" +---------------------------------+----------------------------------+\n");
		printf(" |      1  -  Data Structures      |         2  -  Algorithms         |\n");
		printf(" +--------------------------------------------------------------------+\n");
		printf(" |                            0 to Exit                               |\n");
		printf(" +--------------------------------------------------------------------+\n");

		printf(" > ");
		scanf_s("%d", &ds_alg);

		switch (ds_alg)
		{
		case 0:
			return;
		case 1:
			DataStructuresMenu();
			break;
		case 2:
			AlgorithmsMenu();
			break;
		case 3:
			dev_short_cut();
			break;
		default:
			printf("\nInvalid Number");

			printf("\nPress enter to continue...");
			_getch();
			break;
		}

		system(CLEAR_SCREEN);
	}

	printf("\n");
	return 0;
}
