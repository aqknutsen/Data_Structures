/**
*	@file StackableAnything.hpp
*	@author John Gibbons
*	@date 2014.02.02
*	Updated 2014.09.10
		-Change of previous to m_previous
		-Change of value to m_value
*/

template <typename T>  
StackableAnything<T>::StackableAnything(T value)
{
	m_previous = nullptr;
	m_value = value;
}

template <typename T>
StackableAnything<T>* StackableAnything<T>::getPrevious() const
{
	return(m_previous);
}

template <typename T>  
void StackableAnything<T>::setPrevious(StackableAnything<T>* prev)
{
	m_previous = prev;
}

template <typename T>
T StackableAnything<T>::getValue() const
{
	return(m_value);
}

template <typename T>
void StackableAnything<T>::setValue(T value)
{
	m_value = value;
}


