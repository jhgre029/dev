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
#include "SList.h"
 
int main(int argc, char* argv[])
{
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
	delete list;
	
	return EXIT_SUCCESS;
}