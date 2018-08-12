/**
 * @file UserInput.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/06/2018
 *
 * @brief Header File for UserInput functions
 *
 */

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "Core.h"

	int input_int(const char *message);
	size_t input_size_t(const char *message);
	char input_char(const char *message);
	char *input_string(size_t max_size, const char *message);

#ifdef __cplusplus
}
#endif