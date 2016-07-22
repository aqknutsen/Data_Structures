/**
*	@file Node.hpp
*	@date 2014.02.23
*	@author John Gibbons
*/


template <typename T>
Node<T>::Node()
{
	m_next = nullptr;
	m_previous = nullptr;
}


template <typename T>
T Node<T>::getValue()
{
	return(m_value);
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

template <typename T>
Node<T>* Node<T>::getPrevious()
{
	return(m_previous);
}


template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
	m_previous = prev;
}
