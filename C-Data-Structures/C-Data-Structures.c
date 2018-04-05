/**
 * Entry point for project. In this file all tests are called.
 *
 * What is C-Data-Structures ?
 *
 * C-Data-Structures is a project for implementing data structures purely in C.
 *
 */

#include "Core\Tests.h"

int main()
{

	srand();

	//ArrayTests();
	//DArrayTests();
	//DoublyLinkedListTests();
	SinglyLinkedListTests();
	CircularLinkedListTests();
	//StackTests();
	//ConversionTests();
	//VectorTests();

	printf("\n");
    return 0;
}
