/**
 * @file DataStructuresTests.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/03/2018
 *
 * @brief Header to Include Structure Test Functions in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	int SinglyLinkedListTests();
	int DoublyLinkedListTests();
	int CircularLinkedListTests();
	int SparseMatrixTests();

	int StackTests();
	//int StaticStackTests();

	int QueueTests();
	int DequeTests();
	int PriorityQueueTests();
	int CircularBufferTests();

	int BinaryTreeTests();
	int BinarySearchTreeTests();

	int ArrayTests();
	int DynamicArrayTests();

	int VectorTests();

	int StructureConversionsTests();

	int StringTests();

	int SortingTests();

#ifdef __cplusplus
}
#endif