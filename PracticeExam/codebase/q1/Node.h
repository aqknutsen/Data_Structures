/**
*	@file Node.h
*	@date 2014.02.23
*	@author John Gibbons
*/

#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
	public:
	/** @pre none
	*   @post Node is created with pointers pointing to nullptr
	*/
	Node();
	
	/** @pre m_value is a valid T
	*   @post none
	*   @return m_value
	*/
	T getValue();

	/** @pre Input parameter, value, is a valid T
	*   @post m_value is set to value
	*/
	void setValue(T value);


	/** @pre none
	*   @post none
	*   @return A pointer to the next node if it exists, otherwise nullptr
	*/
	Node<T>* getNext();

	/** @pre Input parameter, next, is a valid Node<T>* or nullptr
	*   @post m_next is set to next
	*/
	void setNext(Node<T>* next);


	/** @pre none
	*   @post none
	*   @return A pointer to the previous node if it exists, otherwise nullptr
	*/
	Node<T>* getPrevious();

	/** @pre Input parameter, prev, is a valid Node<T>* or nullptr
	*   @post m_previous is set to prev
	*/
	void setPrevious(Node<T>* prev);
	
	
	private:
	T m_value;
	Node<T>* m_next;
	Node<T>* m_previous;
};

#include "Node.hpp"

#endif
