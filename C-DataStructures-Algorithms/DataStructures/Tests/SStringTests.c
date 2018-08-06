/**
 * @file SStringTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/04/2018
 *
 * @brief Test Cases for @c String implementations in C
 *
 */

#include "SString.h"

int SStringTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C String              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	String *str0, *str1, *str2;
	Status st;

	str_make(&str0, "Hello World!");
	str_make(&str1, "Lorem Ipsum");
	str_make(&str2, "Java");

	str_display(str0);
	str_display(str1);
	str_display(str2);

	printf("\nLength: %zu", str_len(str0));
	printf("\nLength: %zu", str_len(str1));
	printf("\nLength: %zu", str_len(str2));

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

	printf("\nLength: %zu", str_len(lotr));

	str_delete(&str0);
	str_delete(&str1);
	str_delete(&str2);

	str_init(&str0);

	size_t i, len;
	for (i = 0; i < lotr->len; i++)
	{
		st = str_push_back(str0, lotr->buffer[i]);

		if (st != DS_OK)
		{
			print_status_repr(st);
			return -1;
		}
	}

	str_display(str0);

	str_delete(&str0);
	str_delete(&lotr);

	str_init(&str0);

	char *test = "Neumann";
	len = strlen(test);

	for (i = 0; i < len; i++)
	{
		st = str_push_char_back(str0, test[i]);

		if (st != DS_OK)
		{
			print_status_repr(st);
			return -1;
		}
	}

	str_push_char_front(str0, 'n');
	str_push_char_front(str0, 'h');
	str_push_char_front(str0, 'o');
	str_push_char_front(str0, 'J');

	str_display(str0);

	str_push_char_at(str0, ' ', 4);
	str_push_char_at(str0, 'n', 4);
	str_push_char_at(str0, 'o', 4);
	str_push_char_at(str0, 'v', 4);
	str_push_char_at(str0, ' ', 4);

	str_display(str0);

	str_delete(&str0);

	printf("\n");
	return 0;
}