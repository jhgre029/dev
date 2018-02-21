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
		if (&n != NULL)
			o << *n.getData() << std::endl;
		else
			o << "CANNOT OUTPUT NULL NODE" << std::endl;
		return o;
	}
};

template<typename T>
class SList
{
private:
	SListNode<T>* _head;
	SListNode<T>* _tail;
	int _numNodes;

public:
	/* Constructors and Destructors */
	SList(SListNode<T>* head = NULL, SListNode<T>* tail = NULL, int num = 0);
	~SList();

	/* Getters */
	SListNode<T>* getHead() { return _head; };
	SListNode<T>* getTail() { return _tail; };
	int getNumNodes() { return _numNodes; };

	/* Setters */
	void setHead(SListNode<T>* node) { this->_head = node; };
	void setTail(SListNode<T>* node) { this->_tail = node; };
	void setNumNodes(int num) { this->_numNodes = num; };
	void incNumNodes() { _numNodes += 1; };
	void decNumNodes() { _numNodes -= 1; };

	/* Other methods*/
	bool insertBefore(SListNode<T>* node, SListNode<T>* newNode);
	bool insertAfter(SListNode<T>* node, SListNode<T>* newNode);
	bool deleteNode(SListNode<T>* node);
	bool sort();
	friend std::ostream& operator << (std::ostream& o, SList<T>& l)
	{
		if (&l != NULL)
		{
			SListNode<T>* temp = l.getHead();
			while (temp != NULL)
			{
				o << *temp->getData() << std::endl;
				temp = temp->getNext();
			}
		}

		else
		{
			o << "CANNOT OUTPUT NULL LIST" << std::endl;
		}
		return o;
	}
};

/***********************************************************************************************/
/* CONSTRUCTORS AND DESCRUCTORS */
/***********************************************************************************************/
/* Default Constructor SList */
template<typename T>
SList<T>::SList(SListNode<T>* head = NULL, SListNode<T>* tail = NULL, int num = 0)
	:_head(head), _tail(tail), _numNodes(num)
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
	if (this == NULL)
	{
		std::cout << "CANNOT INSERT NODE INTO UNITIALIZED LIST" << std::endl;
		return false;
	}
	/* Empty node */
	else if (newNode == NULL)
	{
		std::cout << "CANNOT INSERT EMPTY NODE INTO LIST" << std::endl;
		return false;
	}

	/* Empty list */
	else if (this->getHead() == NULL)
	{
		this->setHead(newNode);
		this->setTail(newNode);
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
	/* unitialized list */
	if (this == NULL)
	{
		std::cout << "CANNOT INSERT NODE INTO AN UNITIALIZED LIST" << std::endl;
		return false;
	}

	/* Empty node */
	else if (newNode == NULL)
	{
		std::cout << "CANNOT INSERT EMPTY NODE INTO LIST" << std::endl;
		return false;
	}

	/* Empty list */
	else if (this->getHead() == NULL)
	{
		this->setHead(newNode);
		this->setTail(newNode);
		this->setNumNodes(1);
		return true;
	}

	/* After last node */
	else if (node == this->getTail())
	{
		newNode->setNext(NULL);
		this->getTail()->setNext(newNode);
		this->setTail(newNode);
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
	/* unitialized list */
	if (this == NULL)
	{
		std::cout << "CANNOT DELETE NODE FROM UNITIALIZED LIST" << std::endl;
		return false;
	}
	/* Empty list */
	if (this->getHead() == NULL)
	{
		std::cout << "LIST IS EMPTY.  NO NODES TO DELETE" << std::endl;
		return false;
	}

	/* Null Node */
	else if (node == NULL)
	{
		std::cout << "CANNOT DELETE NULL NODE" << std::endl;
		return false;
	}

	/* Head Node */
	else if (this->getHead() == node)
	{
		this->setHead(node->getNext());
		delete node;
		this->decNumNodes();
		return true;
	}

	/* Tail Node */
	else if (this->getTail() == node)
	{
		SListNode<T>* temp = this->getHead();
		while (temp->getNext() != this->getTail())
			temp = temp->getNext();
		temp->setNext(NULL);
		this->setTail(temp);
		delete node;
		this->decNumNodes();
	}

	/* All other nodes (including last node) */
	else
	{
		SListNode<T>* temp = this->getHead();
		while (temp->getNext() != node)
			temp = temp->getNext();

		temp->setNext(node->getNext());
		delete node;
		this->decNumNodes();
		return true;
	}
}

template<typename T>
bool SList<T>::sort()
{
	/* figure out how to sort this bitch */
}

#endif//SLIST_H