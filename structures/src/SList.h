/* Name: Jacob Grendahl
 * NetID: jhgrendahl
 * Date: 2018-02-16
 * Project: structures
 * File: SList.h
 */
 
/* Description: */
 
#ifndef SLIST_H
#define SLIST_H
/* Libraries: */
#include <iostream>
#include <fstream>
#include <string>

/* Headers: */

/***********************************************************************************************/
/* CLASS DEFINITIONS */
/***********************************************************************************************/
template<typename T>
class SListNode
{
private:
	SListNode* _next;
	T* _data;

public:
	/* Constructors and Destructors */
	SListNode(SListNode<T>* next = NULL, T* data = NULL);
	~SListNode();

	/* Getters */
	SListNode* getNext() { return _next; }; //returns pointer to next object 
	T* getData() { return _data; }; //returns pointer to object of T type

	/* Setters */
	void setNext(SListNode<T>* node) { _next = node; }; //sets pointer to next SListNode
	void setData(T* data) { _data = data }; //sets pointer to object of T* type

	/* Other Methods */
	friend std::ostream& operator << (std::ostream& o, SListNode<T>& n)
	{
		o << *n->getData() << std::endl;
		return o;
	}
};

template<typename T>
class SList
{
private:
	SListNode<T>* _head;
	int _numNodes;

public:
	/* Constructors and Destructors */
	SList(SListNode<T>* head = NULL, int num = 0);
	~SList();

	/* Getters */
	SListNode<T>* getHead() { return _head; };
	int getNumNodes() { return _numNodes; };

	/* Setters */
	void setHead(SListNode<T>* node) { this->_head = node; };
	void setNumNodes(int num) { this->_numNodes = num; };
	void incNumNodes() { _numNodes += 1; };
	void decNumNodes() { _numNodes -= 1; };

	/* Other methods*/
	bool insertBefore(SListNode<T>* node, SListNode<T>* newNode);
	bool insertAfter(SListNode<T>* node, SListNode<T>* newNode);
	bool deleteNode(SListNode<T>* node);
	bool sort(/* add ability to sort based on function pointer */);
	friend std::ostream& operator << (std::ostream& o, SList<T>& l)
	{
		SListNode<T>* temp = l.getHead();
		while (temp != NULL)
		{
			o << *temp->getData() << std::endl;
			temp = temp->getNext();
		}
		return o;
	}
};

/***********************************************************************************************/
/* CONSTRUCTORS AND DESCRUCTORS */
/***********************************************************************************************/
/* Default Constructor SList */
template<typename T>
SList<T>::SList(SListNode<T>* head = NULL, int num = 0)
	:_head(head), _numNodes(num)
{
}

/* Default Destructor SList*/
template<typename T>
SList<T>::~SList()
{
	SListNode<T>* temp = this->getHead();
	while (temp != NULL)
	{
		this->setHead(temp->getNext());
		delete temp;
		temp = this->getHead();
	}
}

/* Default Constructor SListNode */
template<typename T>
SListNode<T>::SListNode(SListNode<T>* next = NULL, T* data = NULL)
	:_next(next), _data(data)
{
}

/* Default Destructor SListNode */
template<typename T>
SListNode<T>::~SListNode()
{
	delete this->_data;
}

/***********************************************************************************************/
/* OTHER METHODS */
/***********************************************************************************************/

/* Insert Before */
template<typename T>
bool SList<T>::insertBefore(SListNode<T>* node, SListNode<T>* newNode)
{
	/* Empty node */
	if (newNode == NULL)
	{
		std::cout << "Cannot insert empty node into list" << std::endl;
		return false;
	}

	/* Empty list */
	else if (this->getHead() == NULL)
	{
		this->setHead(newNode);
		this->setNumNodes(1);
		return true;
	}

	/* In front of head node */
	else if (node == this->getHead())
	{
		newNode->setNext(this->getHead());
		this->setHead(newNode);
		this->incNumNodes();
		return true;
	}

	/* Assumes NULL is end of list */
	else
	{
		SListNode<T>* temp = this->getHead();
		while (temp->getNext() != node)
			temp = temp->getNext();

		newNode->setNext(node);
		temp->setNext(newNode);
		this->incNumNodes();
		return true;
	}
}

template<typename T>
bool SList<T>::insertAfter(SListNode<T>* node, SListNode<T>* newNode)
{
		/* Empty node */
	if (newNode == NULL)
	{
		std::cout << "Cannot insert empty node into list" << std::endl;
		return false;
	}

	/* Empty list */
	else if (this->getHead() == NULL)
	{
		this->setHead(newNode);
		this->setNumNodes(1);
		return true;
	}

	/* After last node */
	else if (node == NULL)
	{
		SListNode<T>* temp = this->getHead();
		while (temp->getNext() != NULL)
			temp = temp->getNext();

		newNode->setNext(NULL);
		temp->setNext(newNode);
		this->incNumNodes();
		return true;
	}

	else
	{
		newNode->setNext(node->getNext());
		node->setNext(newNode);
		this->incNumNodes();
		return true;
	}
}

template<typename T>
bool SList<T>::deleteNode(SListNode<T>* node)
{
	/* Empty list */
	if (this->getHead() == NULL)
	{
		std::cout << "List is empty.  No nodes to delete" << std::endl;
		return false;
	}

	/* Null Node */
	else if (node == NULL)
	{
		std::cout << "Cannot Delete NULL node" << std::endl;
		return false;
	}

	/* Head Node */
	else if (this->getHead() == node)
	{
		this->setHead(node->getNext());
		delete node;
		return true;
	}

	/* All other nodes (including last node) */
	else
	{
		SListNode<T>* temp = this->getHead();
		while (temp->getNext() != node)
			temp = temp->getNext();

		temp->setNext(NULL);
		delete node;
		return true;
	}
}

#endif//SLIST_H