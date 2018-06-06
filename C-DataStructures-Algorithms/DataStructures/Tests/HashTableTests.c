/**
 * @file HashTableTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/06/2018
 *
 * @brief Test Cases for @c HashTable implementations in C
 *
 */

#include "HashTable.h"

int HashTableTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |             C Hash Table            |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	HashTable *hst;

	size_t hash;

	Status st = hst_init_table(&hst, 31, hash_string_sdbm);

	print_status_repr(st);

	hst->hash_function("Hello World", &hash);

	printf("\nHash: %zu", hash);

	hst->hash_function("Hello World!", &hash);

	printf("\nHash: %zu", hash);
	
	hst->hash_function("One ring to rule them all, one ring to find them and in the darkness bind them", &hash);

	printf("\nHash: %zu", hash);

	hst->hash_function("I like big butts and I can not lie", &hash);

	printf("\nHash: %zu", hash);

	hst_insert(hst, "Hello World!", 1);
	hst_insert(hst, "Hello World", 2);
	hst_insert(hst, "Fire and Blood", 3);
	hst_insert(hst, "Hear me Roar", 4);
	hst_insert(hst, "Ours is the Fury", 5);
	hst_insert(hst, "Winter is Coming", 6);
	hst_insert(hst, "As High as Honor", 7);
	hst_insert(hst, "We do not Sow", 8);
	hst_insert(hst, "Unbowed, Unbent, Unbroken", 9);
	hst_insert(hst, "Growing Strong", 10);
	hst_insert(hst, "Lorem Ipsum", 11);
	hst_insert(hst, "Thomas Edson", 12);
	hst_insert(hst, "Alan Turing", 13);
	hst_insert(hst, "Bernhard Riemann", 14);
	hst_insert(hst, "Leonhard Euler", 15);
	hst_insert(hst, "Carl Friedrich Gauss", 16);
	hst_insert(hst, "Isaac Newton", 17);

	hst_display_table(hst);

	hst_delete_table(&hst);

	size_t size = 109;

	hst_init_table(&hst, size, hash_string_djb2);

	int i, j;
	const char charset[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t c_len = strlen(charset);
	const size_t str_len = 31;
	size_t len;

	char *str = malloc(sizeof(char) * str_len);

	for (i = 0; i < size; i++) {

		len = rand() % (str_len + 1 - 5) + 5;

		for (j = 0; j < len - 1; j++) {
			str[j] = charset[rand() % c_len];
		}

		str[j + 1] = '\0';

		hst_insert(hst, str, rand());
	}

	hst_display_table(hst);

	hst_delete_table(&hst);

	return 0;
}