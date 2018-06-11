/**
 * @file HashSetTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 10/06/2018
 *
 * @brief Test cases for @c HashSet implementations in C
 *
 */

#include "HashSet.h"

int HashSetTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Hash Set             |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	HashSet *set;

	set_init_table(&set, 100, set_rehash_rj);

	size_t i, j, len, hash, size = 100;
	const char charset[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t c_len = strlen(charset);
	const size_t str_len = 31;

	char *str = malloc(sizeof(char) * str_len);

	for (i = 0; i < size; i++) {

		len = rand() % (str_len + 1 - 5) + 5;

		for (j = 0; j < len - 1; j++) {
			str[j] = charset[rand() % c_len];
		}

		str[j + 1] = '\0';

		set_hash_string_sdbm(str, &hash);

		printf("\n| %21zu | %40s |", hash, str);
	}

	printf("\n");
	return 0;
}