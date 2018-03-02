/* Name: Jacob Grendahl
 * NetID: jhgrendahl
 * Date: 2018-02-16
 * Project: structures
 * File: Graph.cpp
 */
 
/* Description: */
 
/* Libraries: */
#include <iostream>
#include <stdlib.h>
 
/* Headers: */
//#include "SList.h"
#include "Matrix.h"
 
int main(int argc, char* argv[])
{
#ifdef SLIST_H
	SList<int>* list = new SList<int>;
	for (int i = -1; i > -10; i--)
		list->insertBefore(list->getHead(), new SListNode<int>(NULL, new int(i)));

	for (int i = 0; i < 10; i++)
		list->insertAfter(list->getTail(), new SListNode<int>(NULL, new int(i)));

	list->deleteNode(list->getTail());
	list->deleteNode(list->getTail());
	list->deleteNode(list->getTail());
	list->deleteNode(list->getTail());
	list->deleteNode(list->getHead());
	list->deleteNode(list->getHead());
	list->deleteNode(list->getHead());
	list->deleteNode(list->getHead()->getNext());
	std::cout << "Number of Nodes: " << list->getNumNodes() << std::endl;
	std::cout << *list;
	list->qSort(list->getHead(), list->getTail(),NULL);
	delete list;
	
	return EXIT_SUCCESS;
#endif//SLIST_H

#ifdef MATRIX_H
	Matrix<int, 4, 5> A;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			A.values[i][j] = 1;

	Matrix<int, 4, 5> B;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			B.values[i][j] = i + j;

	Matrix<int, 4, 5> C = A + B;
	Matrix<int, 4, 5> D;
	D = B+B;
	auto E = D.transpose();
	std::cout << "Rows: " << A.getRows() << std::endl;
	std::cout << "Columns: " << A.getColumns() << std::endl;
	std::cout << "Matrix A:\n" << A << std::endl;
	std::cout << "Matrix B:\n" << B << std::endl;
	std::cout << "Matrix C:\n" << C << std::endl;
	std::cout << "Matrix D:\n" << D << std::endl;
	std::cout << "Matrix E:\n" << E << std::endl;
	return EXIT_SUCCESS;
#endif//MATRIX_H

}