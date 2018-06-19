/**
 * @file UserInput.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/06/2018
 *
 * @brief Function handlers for user input
 *
 */

#include "UserInput.h"

int input_int(const char *message)
{
	fflush(stdin);

	int i;

	printf("\n%s", message);

	scanf_s("%d", &i);

	return i;
}

size_t input_size_t(const char *message)
{
	fflush(stdin);

	size_t i;

	printf("\n%s", message);

	scanf_s("%zu", &i);

	return i;
}

char input_char(const char *message)
{
	fflush(stdin);

	char i;

	printf("\n%s", message);

	scanf_s("%c", &i);

	return i;
}

char * input_string(size_t max_size, const char *message)
{
	fflush(stdin);

	char *ch = malloc(sizeof(char) * (max_size + 1));

	printf("\n%s", message);

	fgets(ch, max_size, stdin);

	ch[max_size] = 0;

	return ch;
}