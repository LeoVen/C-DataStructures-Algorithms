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

	tri_insert(trie, "rubens");
	tri_insert(trie, "ruber");
	tri_insert(trie, "rubicon");
	tri_insert(trie, "rubicundus");
	tri_insert(trie, "rubber");
	tri_insert(trie, "rubbery");
	tri_insert(trie, "rubiks");
	tri_insert(trie, "rubric");
	tri_insert(trie, "rubicund");
	tri_insert(trie, "ruby");
	tri_insert(trie, "rust");
	tri_insert(trie, "rush");
	tri_insert(trie, "rushing");
	tri_insert(trie, "russian");
	tri_insert(trie, "russia");
	tri_insert(trie, "rustic");
	tri_insert(trie, "rude");
	tri_insert(trie, "rudimentary");
	tri_insert(trie, "rudder");
	tri_insert(trie, "rudeness");
	tri_insert(trie, "ruddy");
	tri_insert(trie, "rum");
	tri_insert(trie, "rumble");
	tri_insert(trie, "rumors");
	tri_insert(trie, "rumour");
	tri_insert(trie, "rummage");
	tri_insert(trie, "ruminate");
	tri_insert(trie, "ruminant");

	tri_display(trie);

	printf("\n");
	return 0;
}