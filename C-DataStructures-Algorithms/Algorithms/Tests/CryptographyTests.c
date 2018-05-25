/**
 * @file CryptographyTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 15/05/2018
 *
 * @brief Test Cases for Cryptography Algorithms
 *
 */

#include "..\..\Core\Core.h"
#include "..\..\Core\Algorithms.h"

int CryptographyTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |            C Cryptography           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	char *cipher = NULL, *decipher = NULL;

	int shifts = 10;

	char * string = "H ello World";

	printf("\nString   : %s", string);

	caesar_cipher(string, &cipher, shifts);

	printf("\nCipher   : %s", cipher);

	caesar_decipher(cipher, &decipher, shifts);

	printf("\nDecipher : %s", decipher);

	free(cipher);
	free(decipher);

	printf("\n");

	cipher = NULL;
	decipher = NULL;

	char * str = "One Ring to Rule them All";

	printf("\nString   : %s", str);

	caesar_cipher(str, &cipher, shifts);

	printf("\nCipher   : %s", cipher);

	caesar_decipher(cipher, &decipher, shifts);

	printf("\nDecipher : %s", decipher);

	free(cipher);
	free(decipher);

	printf("\n");
	return 0;
}