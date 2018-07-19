/**
 * @file HashMapTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/06/2018
 *
 * @brief Test Cases for @c HashMap implementations in C
 *
 */

#include "HashMap.h"

int HashMapTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Hash Map             |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	HashMap *map;

	size_t hash, result;

	Status st = map_init_map(&map, 31, map_hash_sdbm);

	print_status_repr(st);

	map->hash_function("Hello World", &hash);

	printf("\nHash: %zu", hash);

	map->hash_function("Hello World!", &hash);

	printf("\nHash: %zu", hash);
	
	map->hash_function("One ring to rule them all, one ring to find them and in the darkness bind them", &hash);

	printf("\nHash: %zu", hash);

	map->hash_function("I like big butts and I can not lie", &hash);

	printf("\nHash: %zu", hash);

	map->hash_function("Gauss", &hash);

	printf("\nHash: %zu", hash);

	map_insert(map, "Hello World!", 1);
	map_insert(map, "Hello World", 2);
	map_insert(map, "Fire and Blood", 3);
	map_insert(map, "Hear me Roar", 4);
	map_insert(map, "Ours is the Fury", 5);
	map_insert(map, "Winter is Coming", 6);
	map_insert(map, "As High as Honor", 7);
	map_insert(map, "We do not Sow", 8);
	map_insert(map, "Unbowed, Unbent, Unbroken", 9);
	map_insert(map, "Growing Strong", 10);
	map_insert(map, "Lorem Ipsum", 11);
	map_insert(map, "Thomas Edson", 12);
	map_insert(map, "Alan Turing", 13);
	map_insert(map, "Bernhard Riemann", 14);
	map_insert(map, "Leonhard Euler", 15);
	map_insert(map, "Carl Friedrich Gauss", 16);
	map_insert(map, "Isaac Newton", 17);
	map_insert(map, "Winter is Coming", 18); // Allowed
	map_insert(map, "Isaac Newton", 19);     // Allowed

	map_display_map(map);

	map_count_collisions(map, &result);
	printf("\nTotal collisions: %zu", result);
	map_count_collisions_max(map, &result);
	printf("\nTotal max collisions: %zu", result);
	map_count_empty(map, &result);
	printf("\nTotal empty spots: %zu", result);
	map_count_entries(map, &result);
	printf("\nTotal insertions: %zu", result);
	printf("\nTotal size: %zu", map->size);
	
	int value;

	char *s1 = "Isaac Newton";     // Collision with 6 and 17
	char *s2 = "Hello World!";     // Collision with Gauss
	char *s3 = "Winter is Coming"; // Collision with 6 and 17
	char *s4 = "Gauss";            // Collision with Hello World!
	char *s5 = "One ring to rule them all!"; // Shouldn't find

	st = map_search(map, s1, &value);
	print_status_repr(st);
	printf("\nValue for key %s is %d", s1, value);
	st = map_search(map, s2, &value);
	print_status_repr(st);
	printf("\nValue for key %s is %d", s2, value);
	st = map_search(map, s3, &value);
	print_status_repr(st);
	printf("\nValue for key %s is %d", s3, value);
	st = map_search(map, s4, &value);
	print_status_repr(st);
	printf("\nValue for key %s is %d", s4, value);
	st = map_search(map, s5, &value);
	print_status_repr(st);
	printf("\nValue for key %s is %d", s5, value);

	map_delete_map(&map);

	size_t size = 1200;

	map_init_map(&map, size, map_hash_djb2);

	size_t i, j;
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

		map_insert(map, str, rand());
	}

	map_display_map(map);

	map_count_collisions(map, &result);
	printf("\nTotal collisions: %zu", result);
	map_count_collisions_max(map, &result);
	printf("\nTotal max collisions: %zu", result);
	map_count_empty(map, &result);
	printf("\nTotal empty spots: %zu", result);
	map_count_entries(map, &result);
	printf("\nTotal insertions: %zu", result);
	printf("\nTotal size: %zu", map->size);

	map_delete_map(&map);

	printf("\n");
	return 0;
}