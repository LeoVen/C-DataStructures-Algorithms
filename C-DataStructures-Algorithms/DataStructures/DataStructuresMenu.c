/**
 * @file DataStructuresMenu.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/04/2018
 *
 * @brief Menu for Data Structures, containing Tests and Interactive Versions
 *
 * C-DataStructures-Algorithms is a project for implementing data structures and algorithms purely in C.
 *
 */

#include "..\Core\Core.h"
#include "..\Core\DataStructuresTests.h"

int DataStructuresMenu()
{

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

	//SortingTests();

	printf("\n");
	return 0;
}