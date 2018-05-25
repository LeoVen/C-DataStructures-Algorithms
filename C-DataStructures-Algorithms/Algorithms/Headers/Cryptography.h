/**
 * @file Cryptography.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 15/05/2018
 *
 * @brief Header File for Cryptography functions
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Algorithms.h"

	Status caesar_cipher(char *string, char **result, int shifts);
	Status caesar_decipher(char *string, char **result, int shifts);

#ifdef __cplusplus
}
#endif