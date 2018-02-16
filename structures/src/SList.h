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
	SListNode* getNext() { return _next }; //returns pointer to next object 
	T* getData() { return _data }; //returns pointer to object of T type

	/* Setters */
	void setNext(SListNode<T>* node) { _next = node }; //sets pointer to next SListNode
	void setData(T* data) { _data = data }; //sets pointer to object of T* type

	/* Other Methods */
	friend std::ostream& operator << (std::ostream& o, SListNode& n);
};

template<typename T>
class SList
{
private:
	SListNode* _head;
	int _numNodes;

public:
	/* Constructors and Destructors */
	SList(SListNode<T>* head = NULL, int num = 0);
	~SList();

	/* Getters */
	SListNode* getHead() { return _head };
	int getNumNodes() { return _numNodes };

	/* Other methods*/
	bool insertBefore(SListNode* node);
	bool insertAfter(SListNode* node);
	bool deleteNode(SListNode* node);
	bool sort(/* add ability to sort based on function pointer */);
	friend std::ostream& operator << (std::ostream& o, SList& l);
};

/***********************************************************************************************/
/* CONSTRUCTORS AND DESCRUCTORS */
/***********************************************************************************************/
/* Default Constructor SList */
template<typename T>
SList<T>::SList(SListNode<T>* head = NULL, int num = 0)
	:_head(head), numNodes(num)
{
}

/* Default Destructor SList*/
template<typename T>
SList<T>::~SList()
{
	SListNode* temp = _head;
	while (temp != NULL)
	{
		_head = temp->getNext();
		delete temp;
		temp = _head;
	}
}

/* Default Constructor SListNode */
template<typename T>
SListNode<T>::SListNode(SListNode* next = NULL, T* data = NULL)
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
bool SList<T>::insertBefore(SListNode* node, SListNode* newNode)
{
	// add code for inserting a new node before passed node
}

template<typename T>
bool SList<T>::insertAfter(SListNode* node, SListNode* newNode)
{
	// add code for inserting a new node after passed node
}

template<T>
std::ostream& SListNode<T>::operator << (std::ostream& o, SListNode& n)
{
	std::cout << _data;
}

template<T>
std::ostream& SList<T>::operator << (std::ostream& o, SList& l)
{
	SListNode* temp = l.getHead();
	while (temp != NULL)
	{
		std::cout << temp << std::endl;
		temp = temp->getNext();
	}
}

#endif//SLIST_H