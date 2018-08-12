/**
 * @file Trie.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/06/2018
 *
 * @brief Header file for @c Trie implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

#ifndef ALPHABET_SIZE

#define ALPHABET_SIZE 26

#endif

	typedef struct TrieNode
	{
		char letter;
		struct TrieNode *children[ALPHABET_SIZE];
		bool is_end;
	} TrieNode;

	typedef struct Trie
	{
		size_t depth;
		size_t size;
		struct TrieNode *root;
	} Trie;

	Status tri_init_tree(Trie **trie);
	Status tri_init_node(TrieNode **node);

	Status tri_make_node(TrieNode **node, char letter);

	Status tri_insert(Trie *trie, char *word);

	//Status tri_remove(Trie *trie, char *word);

	Status tri_display(Trie *trie);
	Status tri_display_subtree(TrieNode *node, size_t level);
	//Status tri_display_content();

	//Status tri_delete(TrieNode **node);
	//Status tri_erase(Trie *trie);

	bool tri_is_valid_string(char *str);
	//bool tri_has_word(Trie *trie, char *word);

	//Status tri_word_random(Trie *trie);

	//size_t tri_height(TrieNode *node);

	//Status tri_traversal_wrapper(Trie *trie, int traversal);
	//Status tri_traversal_preorder(TrieNode *node);
	//Status tri_traversal_inorder(TrieNode *node);
	//Status tri_traversal_postorder(TrieNode *node);

	//Status tri_traversal_leaves(TrieNode *node);

	size_t tri_char_to_index(char c);

#ifdef __cplusplus
}
#endif;
