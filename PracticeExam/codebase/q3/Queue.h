/**
*	@file Queue.h
*	@author John Gibbons
*	@date 2014.04.02
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue
{
	public:

	/**
	*	@post Creates an empty queue
	*/
	Queue();

	/**
	*	@post Deletes all entries in the queue
	*/
	~Queue();

	/**
	*	@return True if the queue is empty, false otherwise
	*/
	bool isEmpty() const;

	/** 
	*	@post Entry added to back of queue
	*	@param newEntry The object to be added as a new entry
	*/
	void enqueue(const T newEntry);

	/** 
	*	@pre The queue is not empty
	*	@post Front of the queue is removed and placed in the back of the queue
	*	@return none
	*	@throws PreconditionViolationException
	*/
	void backOfTheLine() throw (std::runtime_error);

	/** 
	*	@pre none
	*	@post Front of the queue is removed
	*	@return The value of the entry at the front of the queue
	*	@throws PreconditionViolationException
	*/
	T dequeue() throw(std::runtime_error);

	/** 
	*	@pre The queue is not empty
	*	@post The value at the front is returned and the queue is unchanged
	*	@return The value of the entry at the front of the queue
	*	@throws PreconditionViolationException
	*/
	T peekFront() const throw(std::runtime_error);

	/** 
	*	@pre The queue is not empty
	*	@post The size is returned and the queue is unchanged
	*	@return Returns the size of the queue
	*/
	int size() const;

	/**
	*	@pre none
	*	@post prints the contents of the queue or "Queue Empty" if it is empty
	*	@return none
	*/
	void print() const;

	protected:
	int m_size;
	Node<T>* m_front;
	Node<T>* m_back;

};

#include "Queue.hpp"

#endif


