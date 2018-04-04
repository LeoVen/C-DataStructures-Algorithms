/*
 * VectorTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Test Cases for Vector Implementations in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\Vector.h"

int VectorTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Vector               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	// Vector Sum
	printf("\n---------- Vector Sum ----------");
	Vector *v1;
	buildNormalVector(12.1, -3.7, 0.3, &v1);
	displayVector(v1);
	printf("+");
	Vector *v2;
	buildNormalVector(1.1, -13.7, 4.3, &v2);
	displayVector(v2);
	printf("=");
	Vector *v3 = vectorSum(v1, v2);
	displayVector(v3);

	// Vector Subtraction
	printf("\n------ Vector Subtraction ------");
	Vector *v4 = vectorSubtraction(v1, v2);
	displayVector(v1);
	printf("-");
	displayVector(v2);
	printf("=");
	displayVector(v4);

	// Modulus
	printf("\n-------- Vector Modulus --------");
	Vector *v5;
	buildNormalVector(6.0, 2.0, 3.0, &v5);
	displayVector(v5);
	printf("Modulus: %.2lf\n", vectorModulus(v5));

	double a = 3.2;
	printf("\nScalar Multiplication by %.2lf", a);
	vectorScalarProduct(v5, a);
	displayVector(v5);

	printf("\n---------- Dot Product ----------");
	Vector *v6;
	buildNormalVector(3.0, -1.0, 6.0, &v6);
	displayVector(v6);
	Vector *v7;
	buildNormalVector(2.0, 1.0, -4.0, &v7);
	displayVector(v7);
	printf("\nDot Product: %.2lf", vectorDotProduct(v6, v7));

	printf("\n---- Angle between two Vectors ----");
	Vector *v8;
	buildNormalVector(1.0, 0.0, 3.0, &v8);
	displayVector(v8);
	Vector *v9;
	buildNormalVector(5.0, 5.0, 0.0, &v9);
	displayVector(v9);
	printf("\nAngle between the two: %.4lf radians", vectorAngle(v8, v9));
	

	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v5);
	free(v6);
	free(v7);
	free(v8);
	free(v9);
	printf("\n");
	return 0;
}