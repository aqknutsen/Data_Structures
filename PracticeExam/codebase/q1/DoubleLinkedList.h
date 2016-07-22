/**
*	@file DoubleLinkedList.h
*	@date 2014.02.23
*	@author John Gibbons
*/


#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class DoubleLinkedList
{
	public:
	/** @pre none
	*   @post an empty list is created
	*/
	DoubleLinkedList();
	
	/** @pre none
	*   @post All nodes in the list are destroyed	
	*/
	~DoubleLinkedList();

	/* @pre none
	*  @post none
	*  @return the number of nodes in the list
	*/
	int size();

	/*  @pre none
	*   @post none
	*   @return true if the number of nodes in the list is greater than zero, false otherwise
	*/
	bool isEmpty();


	/* @pre none
	*  @post a node is created, value is placed in it, and the node placed at the front of the list	
	*/
	void pushFront(T value);

	/* @pre nodePtr is pointer to a valid node in the list
	*  @post a node is created, newValue is placed in it, and the node placed ahead of the first occurance of listValue. 
	*	Also, size increased by 1.
	*	
	*       Example given list of ints 5, 8, 3, 9 and a new value, 11 is inserted ahead of 8 the new list will be:
	*		5, 11, 8, 3, 9
	*  @throws std::exception if listValue isn't in the list	
	*/
	void insertAhead(T listValue, T newValue) throw (std::runtime_error);

	/* @pre T is comparable with ==
	*  @post none
	*  @return a pointer to the first node in the list (from front to back) that contains the value or nullptr if not found
	*/
	Node<T>* find(T value);	

	/* @pre The type T is overloaded to be printable via the << operator
	*  @post The list is printed to the screen.  Values are seperated by spaces.
	*  @return none
	*/
	void printList() const;

	/* @pre The type T is overloaded to be printable via the << operator
	*  @post The list is printed to the screen in reverse. Values are seperated by spaces.
	*  @return none
	*/
	void printReverse() const;


	private:
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "DoubleLinkedList.hpp"

#endif
