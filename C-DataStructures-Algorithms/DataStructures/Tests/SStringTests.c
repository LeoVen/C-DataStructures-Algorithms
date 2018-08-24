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

int STR_IO_TESTS_0(void);
int STR_IO_TESTS_1(void);
int STR_REALLOC_TEST(void);
int STR_COMPARE_TEST(void);

int SStringTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C String              |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	//STR_IO_TESTS_0();
	STR_IO_TESTS_1();
	//STR_REALLOC_TEST();
	//STR_COMPARE_TEST();

	String *str0, *str1, *str2, *str3;
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
		st = str_push_char_back(str0, lotr->buffer[i]);

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

	str_pop_char_at(str0, 6);
	str_push_char_at(str0, 'o', 6);

	char f, e; // Front, end

	str_front(str0, &f);
	str_back(str0, &e);

	printf("\nFrist character: %c\nLast character: %c", f, e);

	const char *string;

	str_get_string(str0, &string);

	printf("\n\nReturned string: %s", string);
	free(string);

	str_delete(&str0);

	printf("\n");

	// The resulting string is always stored in the first string
	// Append
	str_make(&str0, "Alan");
	str_make(&str1, "Turin");

	str_append(str0, str1);
	str_push_char_at(str0, ' ', 4);
	str_push_char_back(str0, 'g');

	str_display(str0);

	str_delete(&str0);
	str_delete(&str1);

	// Prepend
	str_make(&str0, "them all");
	str_make(&str1, "One ring");
	str_make(&str2, " to rule ");

	// Prepend str2 to str0
	str_prepend(str0, str2);
	// Append str0 to str1
	str_append(str1, str0);

	str_display(str1);

	str_make(&str3, "Lord of the Rings: ");

	str_prepend(str1, str3);

	str_display(str1);

	str_delete(&str0);
	str_delete(&str1);
	str_delete(&str2);
	str_delete(&str3);

	printf("\n");
	return 0;
}

// Push/Pop char
int STR_IO_TESTS_0(void)
{
	const char *text = " ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789 ";

	String *str;
	char ch;

	Status st = str_init(&str);

	if (st != DS_OK)
		return st;

	size_t max_len = 8, iter = 1000, pos, i, j, k, text_len = strlen(text);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ------- STR_IO_TESTS_0 -------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	printf("\n---------- ---------- ---------- ---------- ----------");

	for (k = 0; k < iter; k++)
	{
		i = rand();
		j = rand() % 3;

		if (i % 2 == 0 && str->len < max_len)
		{
			// Push char
			ch = text[rand() % text_len];

			if (j == 0)
			{
				// Push front
				printf("\nstr_push_char_front()");
				st = str_push_char_front(str, ch);
			}
			else if (j == 1)
			{
				// Push at
				printf("\nstr_push_char_at()");
				printf(" position");
				if (str->len != 0)
				{
					pos = rand() % str->len;
					printf(" %zu", pos);
					st = str_push_char_at(str, ch, pos);
				}
				else
				{
					st = str_push_char_at(str, ch, 0);
					printf(" 0");
				}
			}
			else
			{
				// Push back
				printf("\nstr_push_char_back()");
				st = str_push_char_back(str, ch);
			}
		}
		else
		{
			// Pop char
			if (j == 0)
			{
				// Pop front
				printf("\nstr_pop_char_front()");
				st = str_pop_char_front(str);
			}
			else if (j == 1)
			{
				// Pop at
				printf("\nstr_pop_char_at()");
				printf(" position");
				if (str->len != 0)
				{
					pos = rand() % str->len;
					printf(" %zu", pos);
					st = str_pop_char_at(str, pos);
				}
				else
				{
					st = str_pop_char_at(str, 0);
					printf(" 0");
				}
			}
			else
			{
				// Pop back
				printf("\nstr_pop_char_back()");
				st = str_pop_char_back(str);
			}
		}

		str_display_raw(str);
		printf("\nString Lenght: %zu", str->len);
		print_status_repr(st);
		if (!str_buffer_empty(str))
		{
			str_front(str, &ch);
			printf("\nFront char: %c", ch);
			str_back(str, &ch);
			printf("\nBack  char: %c", ch);
		}
		else
		{
			printf("\nFront char: ");
			printf("\nBack  char: ");
		}

		printf("\n---------- ---------- ---------- ---------- ----------");
	}

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	return 0;
}

// Push/Pop
int STR_IO_TESTS_1(void)
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ------- STR_IO_TESTS_1 -------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	String *test;

	Status st = str_init(&test);

	if (st != DS_OK)
		return st;

	while (test->len < 200)
	{
		st += str_push_front(test, "Oi eu sou o goku. ");
		
		if (st != DS_OK)
			return st;
	}

	printf("\n%s", test->buffer);

	str_delete(&test);

	str_init(&test);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");
	return 0;
}

int STR_REALLOC_TEST(void)
{
	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ------ STR_REALLOC_TEST ------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	String *str;

	str_init(&str);

	str->growth_rate = 10000000000; // oops! wrong!

	// Testing realloc
	int i;
	for (i = 65; i < 76; i++)
		str_push_char_back(str, i);

	str_display(str);

	str_delete(&str);

	printf("\n");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- End tests ---------- ---------- ----------");
	printf("\n ---------- ---------- ---------- --------- ---------- ---------- ----------");
	printf("\n");

	return 0;
}

int STR_COMPARE_TEST(void)
{
	String *s1, *s2, *s3, *s4, *s5;

	Status st = 0;
	st += str_make(&s1, "/home");
	st += str_make(&s2, "array");
	st += str_make(&s3, "Array");
	st += str_make(&s4, "arrayy");
	st += str_make(&s5, "/home");

	if (st != DS_OK)
		return st;

	if (str_greater(s3, s2))
		printf("\n\n%8s  is greater than  %8s", s3->buffer, s2->buffer);

	if (str_equals(s1, s5))
		printf("\n%8s       equals      %8s", s1->buffer, s5->buffer);

	if (str_lesser(s4, s2))
		printf("\n%8s   is lesser than  %8s\n\n", s4->buffer, s2->buffer);

	if (str_greater(s5, s3))
		printf("\n\n%8s  is greater than  %8s", s5->buffer, s3->buffer);

	if (!str_equals(s2, s3))
		printf("\n%8s   is not equal to   %8s", s2->buffer, s3->buffer);

	if (str_lesser(s2, s1))
		printf("\n%8s   is lesser than  %8s\n\n", s2->buffer, s1->buffer);

	str_delete(&s1);
	str_delete(&s2);
	str_delete(&s3);
	str_delete(&s4);

	return 0;
}