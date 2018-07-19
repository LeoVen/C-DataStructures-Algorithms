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

	set_init_set(&set, size, set_hash_djb2, set_rehash_rj);

	size_t i, j, len;
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

	set_display_set(set);

	printf("\nSet size: %zu", set->size);

	set_delete_set(&set);

	set_init_set(&set, 30, set_hash_sdbm, set_rehash_prime);

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
	set_insert(set, "Ada Lovelace");
	set_insert(set, "Thomas Edson");
	set_insert(set, "Alan Turing");
	set_insert(set, "Bernhard Riemann");
	set_insert(set, "Leonhard Euler");
	set_insert(set, "Carl Friedrich Gauss");
	set_insert(set, "Isaac Newton");
	set_insert(set, "Winter is Coming"); // Not allowed
	set_insert(set, "Isaac Newton");     // Not allowed

	set_display_set(set);

	printf("\nSet size: %zu", set->size);

	size_t r, s;
	set_count_empty(set, &r);
	set_count_elements(set, &s);

	printf("\nThere are %zu entries and %zu empty spaces", s, r);

	bool res;
	if (set_contains(set, "Isaac Newton", &res) == DS_OK)
		printf("\nThe set %s Isaac Newton", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Insertion Sort", &res) == DS_OK)
		printf("\nThe set %s Insertion Sort", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Fire and Blood", &res) == DS_OK)
		printf("\nThe set %s Fire and Blood", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Barack Obama", &res) == DS_OK)
		printf("\nThe set %s Barack Obama", (res) ? "contains" : "does not contains");

	char *words[8] = { "Hello World!", "Lorem Ipsum", "The Ring", "Thomas Muller",
		"Winter is Coming", "Turing Machine", "Hear me Roar", "Ramanujan"};

	for (i = 0; i < 8; i++) {

		if (set_exists(set, words[i]))
			printf("\nThe element [ %s ] exists", words[i]);
		else
			printf("\nThe element [ %s ] does not exists", words[i]);
	}

	st = set_remove(set, "Winter is Coming");
	print_status_repr(st);
	st = set_remove(set, "Thomas Edson");
	print_status_repr(st);
	st = set_remove(set, "Lorem Ipsum");
	print_status_repr(st);
	st = set_remove(set, "As High as Honor");
	print_status_repr(st);
	st = set_remove(set, "Bernhard Riemann");
	print_status_repr(st);
	st = set_remove(set, "Unbowed, Unbent, Unbroken");
	print_status_repr(st);
	printf("\nShouldn't find:");
	st = set_remove(set, "Unbowed, Unbent, Unbroken");
	print_status_repr(st);

	set_display_set(set);

	printf("\nSet size: %zu", set->size);

	set_count_empty(set, &r);
	set_count_elements(set, &s);

	printf("\nThere are %zu entries and %zu empty spaces", s, r);

	set_delete_set(&set);

	/* **********************************************************************
	 *
	 * SETS
	 *
	 ********************************************************************** */

	const char *letters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
								"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	len = 26;

	HashSet *set_a, *set_b, *set_c;

	size = 12;

	set_init_set(&set_a, size, set_hash_prime, set_rehash_prime);
	set_init_set(&set_b, size, set_hash_djb2, set_rehash_rj);
	set_init_set(&set_c, size * 2, set_hash_prime, set_rehash_rj);

	for (i = 0; i < size; i++)
		set_insert(set_a, letters[rand() % len]);

	for (i = 0; i < size; i++)
		set_insert(set_b, letters[rand() % len]);

	printf("\n\n +--------------------------------------------------+");
	printf("\n |                     Set A                        |");
	printf("\n +--------------------------------------------------+");
	set_display_elements(set_a);

	printf("\n\n +--------------------------------------------------+");
	printf("\n |                     Set B                        |");
	printf("\n +--------------------------------------------------+");
	set_display_elements(set_b);

	printf("\n");

	printf("\n +--------------------------------------------------+");
	printf("\n |                   UNION SET                      |");
	printf("\n +--------------------------------------------------+");
	st = set_union(set_a, set_b, set_c);
	print_status_repr(st);
	set_display_elements(set_c);

	set_erase_set(&set_c);

	printf("\n +--------------------------------------------------+");
	printf("\n |                   INTER SET                      |");
	printf("\n +--------------------------------------------------+");
	st = set_intersection(set_a, set_b, set_c);
	print_status_repr(st);
	set_display_elements(set_c);

	set_erase_set(&set_c);

	printf("\n +--------------------------------------------------+");
	printf("\n |                     A - B                        |");
	printf("\n +--------------------------------------------------+");
	st = set_difference(set_a, set_b, set_c);
	print_status_repr(st);
	set_display_elements(set_c);

	set_erase_set(&set_c);

	printf("\n +--------------------------------------------------+");
	printf("\n |                     B - A                        |");
	printf("\n +--------------------------------------------------+");
	st = set_difference(set_b, set_a, set_c);
	print_status_repr(st);
	set_display_elements(set_c);

	set_erase_set(&set_c);

	printf("\n +--------------------------------------------------+");
	printf("\n |               (A \\ B) U (B \\ A)                  |");
	printf("\n +--------------------------------------------------+");
	st = set_sym_diff(set_b, set_a, set_c);
	print_status_repr(st);
	set_display_elements(set_c);

	set_erase_set(&set_c);

	set_delete_set(&set_a);
	set_delete_set(&set_b);
	set_delete_set(&set_c);

	printf("\n");
	return 0;
}
