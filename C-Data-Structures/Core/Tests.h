/*
 * CTests.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header to Include Structure Test Functions in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	int SinglyLinkedListTests();
	int DoublyLinkedListTests();
	int CircularLinkedListTests();
	int StackTests();

	int ArrayTests();
	int DynamicArrayTests();

	int VectorTests();

	int SortingTests();

	int ConversionTests();

#ifdef __cplusplus
}
#endif