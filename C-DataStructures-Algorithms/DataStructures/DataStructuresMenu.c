/**
 * @file DataStructuresMenu.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Menu for Data Structures, containing Tests and Interactive Versions
 *
 */

#include "..\Core\Core.h"
#include "..\Core\DataStructuresTests.h"

int ds_all();
int ds_print_menu();
bool ds_switch_function(int f);

int DataStructuresMenu()
{
	system(CLEAR_SCREEN);

	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                           Data Structures                          |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" | - Singly Linked List                                               |\n");
	printf(" |     __      __      __      __      __                             |\n");
	printf(" |    |__| -> |__| -> |__| -> |__| -> |__| -> null                    |\n");
	printf(" |    head                            tail                            |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" | - Doubly Linked List                                               |\n");
	printf(" |             __       __       __       __                          |\n");
	printf(" |    null <- |__| <-> |__| <-> |__| <-> |__| -> null                 |\n");
	printf(" |            head                       tail                         |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" | - Queue                                                            |\n");
	printf(" |            __      __  __  __  __  __      __                      |\n");
	printf(" | enqueue() |__| --> __||__||__||__||__ --> |__| dequeue()           |\n");
	printf(" |                  front            back                             |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" | - Stack           __                __                             |\n");
	printf(" |           push() |__| -->      --> |__| pop()                      |\n");
	printf(" |                           |__|                                     |\n");
	printf(" |                           |__|                                     |\n");
	printf(" |                           |__|                                     |\n");
	printf(" |                           |__|                                     |\n");
	printf(" |                                                                    |\n");
	printf(" |                                                                    |\n");
	printf(" | - Binary Tree          _____                                       |\n");
	printf(" |                       |_____| Root              _                  |\n");
	printf(" |                   _____/   \\_____                |                 |\n");
	printf(" |     left-child   |_____|   |_____|  right-child  |                 |\n");
	printf(" |              ___ / \\ ___    ___/ \\ ___           | Sub tree        |\n");
	printf(" |             |___|   |___|  |___|  |___|  Leaves  |                 |\n");
	printf(" |                             ^        ^          _|                 |\n");
	printf(" |                             |siblings|                             |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");

	int ds;
	bool ok = true;

	while (ok) {

		ds_print_menu();
		
		scanf_s("%d", &ds);
		ok = ds_switch_function(ds);
		
		printf("\nPress enter to continue...");
		getch();
		
		system(CLEAR_SCREEN);
	}

	//DS_SortingTests();

	printf("\n");
	return 0;
}

int ds_print_menu()
{
	printf(" +--------------------------------------------------------------------+\n");
	printf(" |                                                                    |\n");
	printf(" |                          Interactive Menu                          |\n");
	printf(" |                                                                    |\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf("\n");
	printf(" +--------------------------------------------------------------------+\n");
	printf(" | Available Structures  [Exit : 0]                                   |\n");
	printf(" |                                                                    |\n");
	printf(" |                            Interactive Mode     Running Tests      |\n");
	printf(" |                                                                    |\n");
	printf(" | Array                          |     |             | 101 |         |\n");
	printf(" | Dynamic Array                  |     |             | 102 |         |\n");
	printf(" | Circular Buffer                |     |             | 103 |         |\n");
	printf(" | Static Stack                   |     |             |     |         |\n");
	printf(" | Singly Linked List             |     |             | 105 |         |\n");
	printf(" | Doubly Linked List             |     |             | 106 |         |\n");
	printf(" | Circular Linked List           |     |             | 107 |         |\n");
	printf(" | Stack                          |     |             | 108 |         |\n");
	printf(" | Queue                          |     |             | 109 |         |\n");
	printf(" | Vector                         |     |             | 110 |         |\n");
	printf(" |                                                                    |\n");
	printf(" | String                         |     |             | 120 |         |\n");
	printf(" | Structure Conversions          |     |             | 130 |         |\n");
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

bool ds_switch_function(int f)
{
	switch (f)
	{
	case 0:
		return false;
	case 1:
		ds_all();
		break;
	case 101:
		ArrayTests();
		break;
	case 102:
		DynamicArrayTests();
		break;
	case 103:
		CircularBufferTests();
		break;
	case 105:
		SinglyLinkedListTests();
		break;
	case 106:
		DoublyLinkedListTests();
		break;
	case 107:
		CircularLinkedListTests();
		break;
	case 108:
		StackTests();
		break;
	case 109:
		QueueTests();
		break;
	case 110:
		VectorTests();
		break;
	case 120:
		StringTests();
		break;
	case 130:
		StructureConversionsTests();
		break;
	default:
		printf("\nInvalid Number\n");
		break;
	}

	return true;
}

int ds_all()
{
	SinglyLinkedListTests();
	DoublyLinkedListTests();
	CircularLinkedListTests();

	StackTests();
	//StaticStackTests();

	QueueTests();
	CircularBufferTests();

	ArrayTests();
	DynamicArrayTests();

	VectorTests();

	StructureConversionsTests();

	StringTests();

	SortingTests();

	return 0;
}