/**
*	@file Node.h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	public:

	/**
	*	@post Creates a Node. Pointers set to nullptr
	*/
	Node();

	/**
	*	@post Creates a Node. Pointers set to nullptr and value stored.
	*/
	Node(T value);

	/** 
	*	@return Pointer to next node.
	*/
	Node<T>* getNext() const;

	/** 
	*	@pre Value is a valid T
	*	@post The value is stored in the node
	*/
	void setNext(Node<T>* next);

	/** 
	*	@pre The queue is not empty
	*	@post The value at the front is returned and the queue is unchanged
	*	@return The value of the entry at the front of the queue
	*/
	T getValue() const;

	/** 
	*	@pre Value is a valid T
	*	@post The value is stored in the node
	*/
	void setValue(T value);


	protected:
	
	Node<T>* m_next;
	T m_value;

};

#include "Node.hpp"

#endif


