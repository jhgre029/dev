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

/* Headers: */
#include "SList.cpp"

/***********************************************************************************************/
/* CLASS DEFINITION */
/***********************************************************************************************/
template<typename T>
class SListNode
{
private:
	SListNode* _next;
	T* _data;
	static SListNode* _head;
	static int _numNodes;

public:
	/* Constructors and Destructors */
	SListNode(SListNode* next = NULL, T* data = NULL);
	~SListNode();

	/* Getters */
	SListNode* getNext() { return _next }; //returns pointer to next object 
	T* getData() { return _data }; //returns pointer to object of T type
	static SListNode* getHead() { return _head }; //returns pointer to head node
	static int getNumNodes() { return _numNodes }; //returns number of nodes in list 

	/* Setters */
	void setNext(SListNode* node) { _next = node }; //sets pointer to next SListNode
	void setData(T* data) { _data = data }; //sets pointer to object of T* type
	static void setHead(SListNode* node) { _head = node }; //sets pointer to head node
	static void setNumNodes(int numNodes) { _numNodes = numNodes }; //sets number of nodes

	/* Other Methods */
	bool insertBefore(SListNode* node);
	bool insertAfter(SListNode* node);
};

/***********************************************************************************************/
/* STATIC VARIABLES */
/***********************************************************************************************/
template<typename T>
SListNode<T>* SListNode<T>::_head = NULL;

template<typename T>
int SListNode<T>::_numNodes = 0;

/***********************************************************************************************/
/* CONSTRUCTORS AND DESCRUCTORS */
/***********************************************************************************************/
/* Default Constructor */
template<typename T>
SListNode<T>::SListNode(SListNode* next = NULL, T* data = NULL)
	:_next(next), _data(data)
{
}

/* Default Destructor */
template<typename T>
SListNode<T>::~SListNode()
{
	SListNode* temp = _head;
	if (this == _head)
	{
		setHead(_head->getNext());
	}

	else
	{
		while (temp != NULL)
		{
			if (this == temp->getNext())
				temp->setNext(this->_next);

			temp = temp->getNext();
		}
	}
	delete this->_data;
	_numNodes = _numNodes - 1;
}

/***********************************************************************************************/
/* OTHER METHODS */
/***********************************************************************************************/

/* Insert Before */
template<typename T>
bool SListNode<T>::insertBefore(SListNode* node)
{
	bool result = true;
	if (node == NULL)
	{
		result = false;
	}

	else if (_head)
	{

	}

	else if (_head == node)
	{
		node->setNext(_head);
		node->setHead(node);
	}
	
	else
	{
		SListNode* temp = _head;
		while (temp->_next != node)
			temp = temp->_next;

		node->setNext(temp->_next);
		temp->setNext(node);
	}
}

template<typename T>
bool SListNode<T>::insertAfter(SListNode* node)
{
	
}

#endif//SLIST_H