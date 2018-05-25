/**
 * @file StringTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c String implementations in C
 *
 */

#include "SString.h"

int StringTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C String              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	String *str0, *str1, *str2;

	str_make(&str0, "Hello World!");
	str_make(&str1, "Lorem Ipsum");
	str_make(&str2, "Java");

	str_display(str0);
	str_display(str1);
	str_display(str2);

	printf("\nLength: %zu", str_length(str0));
	printf("\nLength: %zu", str_length(str1));
	printf("\nLength: %zu", str_length(str2));

	String *lotr;

	str_make(&lotr, "Three Rings for the Elven-Kings under the sky,\n\
Seven for the Dwarf-lords in their halls of stone,\n\
Nine for Mortal Men doomed to die,\n\
One for the Dark Lord on his dark throne\n\
In the Land of Mordor where the shadows lie.\n\
One Ring to rule them all, One Ring to find them,\n\
One Ring to bring them all and in the darkness bind them\n\
In the Land of Mordor where the Shadows lie.");

	str_display(lotr);

	printf("\nLength: %zu", str_length(lotr));



	str_delete(&str0);
	str_delete(&str1);
	str_delete(&str2);
	printf("\n");
	return 0;
}