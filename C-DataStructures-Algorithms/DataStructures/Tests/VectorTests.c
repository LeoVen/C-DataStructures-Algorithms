/**
 * @file VectorTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 20/03/2018
 *
 * @brief Test Cases for @c Vector Implementations in C
 *
 * Here all functions are tested to assure that they operate as expected. Note
 * that not all test cases are performed.
 *
 */

#include "Vector.h"

int VectorTests(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Vector               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	// Vector Sum
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	printf("\n----------------------- Vector Sum ------------------------");
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	Vector *v1;
	vec_build(12.1, -3.7, 0.3, &v1);
	vec_display(v1);
	printf("+");
	Vector *v2;
	vec_build(1.1, -13.7, 4.3, &v2);
	vec_display(v2);
	printf("=");
	Vector *v3;
	vec_sum(v1, v2, &v3);
	vec_display(v3);

	// Vector Subtraction
	printf("\n\n\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	printf("\n------------------- Vector Subtraction --------------------");
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	Vector *v4;
	vec_subtract(v1, v2, &v4);
	vec_display(v1);
	printf("-");
	vec_display(v2);
	printf("=");
	vec_display(v4);

	// Modulus
	printf("\n\n\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	printf("\n--------------------- Vector Modulus ----------------------");
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	Vector *v5;
	vec_build(6.0, 2.0, 3.0, &v5);
	vec_display(v5);
	double mod;
	vec_mod(v5, &mod);
	printf("Modulus: %.2lf\n", mod);

	double a = 3.2;
	printf("\nScalar Multiplication by %.2lf", a);
	vec_product_scalar(v5, a);
	vec_display(v5);

	printf("\n\n\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	printf("\n----------------------- Dot Product -----------------------");
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	Vector *v6;
	vec_build(3.0, -1.0, 6.0, &v6);
	vec_display(v6);
	Vector *v7;
	vec_build(2.0, 1.0, -4.0, &v7);
	vec_display(v7);
	vec_product_dot(v6, v7, &a);
	printf("\nDot Product: %.2lf", a);

	printf("\n\n\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	printf("\n---------------- Angle between two Vectors ----------------");
	printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----");
	Vector *v8;
	vec_build(1.0, 0.0, 3.0, &v8);
	vec_display(v8);
	Vector *v9;
	vec_build(5.0, 5.0, 0.0, &v9);
	vec_display(v9);
	vec_angle(v8, v9, &a);
	printf("\nAngle between the two: %.4lf radians", a);

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