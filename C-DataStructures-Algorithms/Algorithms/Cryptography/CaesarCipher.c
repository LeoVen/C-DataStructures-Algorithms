/**
 * @file CaesarCipher.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 15/05/2018
 *
 * @brief Source file for Caesar Cipher implementations in C
 *
 */

#include "Cryptography.h"

Status caesar_cipher(char *string, char **result, int shifts)
{
	if (shifts < 1 || shifts > 25)
		return DS_ERR_INVALID_ARGUMENT;

	size_t len = strlen(string);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	(*result) = malloc(sizeof(char) * len + 1);
	
	if (!(*result))
		return DS_ERR_ALLOC;

	int i, s;
	for (i = 0; string[i] != '\0'; i++)
	{
		s = string[i];
		if (isupper(string[i]))
		{
			(*result)[i] = ((s + shifts - 65) % 26) + 65;
		}
		else if (islower(string[i]))
		{
			(*result)[i] = ((s + shifts - 97) % 26) + 97;
		}
		else
			(*result)[i] = s;
	}

	(*result)[len] = '\0';

	return DS_OK;
}

Status caesar_decipher(char *string, char **result, int shifts)
{
	if (shifts < 1 || shifts > 25)
		return DS_ERR_INVALID_ARGUMENT;

	size_t len = strlen(string);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	(*result) = malloc(sizeof(char) * len + 1);

	if (!(*result))
		return DS_ERR_ALLOC;

	shifts = 26 - shifts;

	int i, s;
	for (i = 0; string[i] != '\0'; i++)
	{
		s = string[i];
		if (isupper(string[i]))
		{
			(*result)[i] = ((s + shifts - 65) % 26) + 65;
		}
		else if (islower(string[i]))
		{
			(*result)[i] = ((s + shifts - 97) % 26) + 97;
		}
		else
			(*result)[i] = s;
	}

	(*result)[len] = '\0';

	return DS_OK;
}