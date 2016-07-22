/**
*	@file StackableAnything.h
*	@author John Gibbons
*	@date 2014.02.02
*	Updated 2014.09.10
		-Change of previous to m_previous
		-Change of value to m_value
*/

#ifndef STACKABLEANYTHING_H
#define STACKABLEANYTHING_H

template <typename T> 
class StackableAnything
{
	public:
	/**
	*   @pre none
	*   @post StackableAnything is created with the value, t, stored inside
	*   @return an empty stack
	*/
	StackableAnything(T value);

	/**
	*   @pre prev is a valid pointer
	*   @post m_previous is set to prev
	*   @return none
	*/
	void setPrevious(StackableAnything<T>* prev);

	/**
	*   @pre none
	*   @post none
	*   @return pointer to another StackableAnything or nullptr
	*/
	StackableAnything<T>* getPrevious() const;


	/**
	*   @pre val is a valid T
	*   @post m_value is set to val
	*   @return none
	*/
	void setValue(T value);


	/**
	*   @pre none
	*   @post none
	*   @return m_value
	*/
	T getValue() const;

	private:
	StackableAnything* m_previous;
	T m_value;	

};

#include "StackableAnything.hpp"

#endif
