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

int alg_all(void);
int alg_print_menu(void);
int alg_switch_function(int f);

int AlgorithmsMenu(void)
{
	system(CLEAR_SCREEN);

	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                             Algorithms                             |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");

	int alg;
	bool ok = true;

	while (ok) {

		alg_print_menu();
		
		scanf_s("%d", &alg);
		ok = alg_switch_function(alg);
		
		printf("\nPress enter to continue...");
		_getch();

		system(CLEAR_SCREEN);
	}

	printf("\n");
	return 0;
}

int alg_print_menu(void)
{
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                          Interactive Menu                          |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" | Available Algorithms  [Exit : 0]                                   |\n");
	printf(" |                                                                    |\n");
	printf(" |                            Interactive Mode     Running Tests      |\n");
	printf(" |                                                                    |\n");
	printf(" | Generators                     |     |             | 101 |         |\n");
	printf(" | Mathematics                    |     |             | 102 |         |\n");
	printf(" | Sorting                        |     |             | 103 |         |\n");
	printf(" |                                                                    |\n");
	printf(" | Run all tests  |  1  |                                             |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" | Example                                                            |\n");
	printf(" | Structure Name                  |   |              | 102 |         |\n");
	printf(" |                              Not available        Available        |\n");
	printf(" |                                                  (input key)       |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");
	printf(" > ");

	return 0;
}

int alg_switch_function(int f)
{
	switch (f)
	{
	case 0:
		return false;
	case 1:
		alg_all();
		break;
	case 101:
		GeneratorsTests();
		break;
	case 102:
		MathematicsTests();
		break;
	case 103:
		SortingTests();
		break;
	default:
		printf("\nInvalid Number\n");
		break;
	}

	return true;
}

int alg_all(void)
{
	GeneratorsTests();

	MathematicsTests();

	SortingTests();

	return 0;
}