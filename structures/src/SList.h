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

/***********************************************************************************************/
/* CLASS DEFINITION */
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
	void setNext(SListNode* node) { _next = node }; //sets pointer to next SListNode
	void setData(T* data) { _data = data }; //sets pointer to object of T* type

	/* Other Methods */
	bool insertBefore(SListNode* node);
	bool insertAfter(SListNode* node);
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
	SListNode* temp = head;
	while (temp != NULL)
	{
		if (this == temp->getNext())
		{
			temp->setNext(this->_next);
			break;
		}
		temp = temp->getNext();
	}

	delete this->_data;
}

/***********************************************************************************************/
/* OTHER METHODS */
/***********************************************************************************************/

/* Insert Before */
template<typename T>
bool SListNode<T>::insertBefore(SListNode* node)
{
	
}

template<typename T>
bool SListNode<T>::insertAfter(SListNode* node)
{

}

#endif//SLIST_H