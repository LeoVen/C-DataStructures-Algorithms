/*
 * StructureConversions.h
 *
 * Author: Leonardo Vencovsky
 * Created on 02/04/2018
 *
 * Structure Conversions Header in C
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "..\Core\Core.h"
#include "..\Core\Structures.h"

	// +-------------------------------------+
	// |              SLL -> X               |
	// +-------------------------------------+
	Status convert_sll_to_array(SinglyLinkedList *sll, Array **array);

	Status convert_sll_to_darray(SinglyLinkedList *sll, DynamicArray **darr);

	// +-------------------------------------+
	// |              DAR -> X               |
	// +-------------------------------------+

	Status convert_darray_to_sll(DynamicArray *darr, SinglyLinkedList **sll);

	// +-------------------------------------+
	// |              AAR -> X               |
	// +-------------------------------------+

	Status convert_array_to_darray(Array *arr, DynamicArray **darr);

#ifdef __cplusplus
}
#endif