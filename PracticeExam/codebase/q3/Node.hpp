/**
*	@file Node.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Node<T>::Node() :m_next(nullptr)
{ }


template <typename T>
Node<T>::Node(T value) : m_next(nullptr), m_value(value)
{ }


template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}


template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}


template <typename T>
T Node<T>::getValue() const
{
	return(m_value);
}


template <typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}
