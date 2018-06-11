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
	Status st;

	size_t size = 200;

	set_init_table(&set, size, set_hash_string_djb2, set_rehash_rj);

	size_t j, len, hash;
	const char charset[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t c_len = strlen(charset);
	const size_t str_len = 31;

	char *str = malloc(sizeof(char) * str_len);

	while (!set_is_full(set))
	{
		len = rand() % (str_len + 1 - 5) + 5;

		for (j = 0; j < len - 1; j++) {
			str[j] = charset[rand() % c_len];
		}

		str[j + 1] = '\0';

		st = set_insert(set, str);
	}

	set_display_table(set);

	printf("\nSet size: %zu", set->size);

	set_delete_table(&set);

	set_init_table(&set, 30, set_hash_string_sdbm, set_rehash_prime);

	printf("\nSet size: %zu", set->size);

	set_insert(set, "Hello World!");
	set_insert(set, "Hello World");
	set_insert(set, "Fire and Blood");
	set_insert(set, "Hear me Roar");
	set_insert(set, "Ours is the Fury");
	set_insert(set, "Winter is Coming");
	set_insert(set, "As High as Honor");
	set_insert(set, "We do not Sow");
	set_insert(set, "Unbowed, Unbent, Unbroken");
	set_insert(set, "Growing Strong");
	set_insert(set, "Lorem Ipsum");
	set_insert(set, "Thomas Edson");
	set_insert(set, "Alan Turing");
	set_insert(set, "Bernhard Riemann");
	set_insert(set, "Leonhard Euler");
	set_insert(set, "Carl Friedrich Gauss");
	set_insert(set, "Isaac Newton");
	set_insert(set, "Winter is Coming"); // Not allowed
	set_insert(set, "Isaac Newton");     // Not allowed

	set_display_table(set);

	printf("\nSet size: %zu", set->size);

	set_delete_table(&set);

	printf("\n");
	return 0;
}