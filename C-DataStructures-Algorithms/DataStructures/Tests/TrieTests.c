/**
 * @file TrieTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/06/2018
 *
 * @brief Test Cases for @c Trie implementations in C
 *
 */

#include "Trie.h"

int TrieTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |                C Trie               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Trie *trie;

	tri_init_tree(&trie);

	tri_insert(trie, "to");
	tri_insert(trie, "tea");
	tri_insert(trie, "ted");
	tri_insert(trie, "tin");
	tri_insert(trie, "ten");
	tri_insert(trie, "tender");
	tri_insert(trie, "tennis");
	tri_insert(trie, "tentacle");
	tri_insert(trie, "tension");

	tri_display(trie);

	printf("\n");
	return 0;
}