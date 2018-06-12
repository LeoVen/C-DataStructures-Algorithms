/**
 * @file Trie.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/06/2018
 *
 * @brief Source file for @c Trie implementations in C
 *
 */

#include "Trie.h"

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status tri_init_tree(Trie **trie)
{
	(*trie) = malloc(sizeof(Trie));

	if (!(*trie))
		return DS_ERR_ALLOC;

	(*trie)->depth = 0;
	(*trie)->size = 0;

	TrieNode *root;

	Status st = tri_init_node(&root);

	if (st != DS_OK)
		return st;

	(*trie)->root = root;

	return DS_OK;
}

Status tri_init_node(TrieNode **node)
{
	(*node) = malloc(sizeof(TrieNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		((*node)->children)[i] = NULL;

	(*node)->is_end = false;

	(*node)->letter = '\0';

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

Status tri_make_node(TrieNode **node, char letter)
{
	(*node) = malloc(sizeof(TrieNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		((*node)->children)[i] = NULL;

	(*node)->is_end = false;

	(*node)->letter = letter;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status tri_insert(Trie *trie, char *word)
{
	if (trie == NULL)
		return DS_ERR_NULL_POINTER;

	size_t len = strlen(word);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	if (!tri_is_valid_string(word))
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	size_t i, idx;

	TrieNode *scan = trie->root;

	for (i = 0; i < len; i++) {

		idx = tri_char_to_index((char)tolower(word[i]));

		if ((scan->children)[idx] == NULL) {
			
			st = tri_make_node(&((scan->children)[idx]), (char)tolower(word[i]));

			if (st != DS_OK)
				return st;
		}

		scan = (scan->children)[idx];
	}

	scan->is_end = true;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

//Status tri_remove(Trie *trie, char *word)

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status tri_display(Trie *trie)
{
	if (trie == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = tri_display_subtree(trie->root, 0);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status tri_display_subtree(TrieNode *node, size_t level)
{
	size_t i, j;

	printf("\n");

	if (level != 0)
		for (j = 0; j < level - 1; j++)
			printf("|   ");

	printf("%c", node->letter);

	if (node->is_end)
		printf("*");

	for (i = 0; i < 26; i++)
	{
		if (node->children[i] != NULL)
		{
			tri_display_subtree(node->children[i], level + 1);
		}
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

//Status tri_delete(TrieNode **node)
//Status tri_erase(Trie *trie)

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool tri_is_valid_string(char *str)
{
	size_t i = 0;

	while (str[i])
	{
		if (!isalpha(str[i]))
			return false;

		i++;
	}

	return true;
}

//bool tri_has_word(Trie *trie, char *word)

//Status tri_word_random(Trie *trie)

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

// +-------------------------------------------------------------------------------------------------+
// |                                              Util                                               |
// +-------------------------------------------------------------------------------------------------+

size_t tri_char_to_index(char c)
{
	return (int)c - (int)'a';
}