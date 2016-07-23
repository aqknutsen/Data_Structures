/**
*	@file : Node.hpp
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: Implentation of the Node class
*/


template <typename T> // We use the templated type T in this method
Node<T>::Node() {
    m_value = T(); // We initially set m_value equal to the default constructor of T at construction time
    m_next = nullptr; // We initially point our m_next pointer at nullptr at construction time
    m_previous = nullptr; // We initially point our m_previous pointer at nullptr at construction time
}

template <typename T> // We use the templated type T in this method
void Node<T>::setValue(T val) {
    m_value  = val; // We set the value of m_value to the parameter passed in
}

template <typename T> // We use the templated type T in this method
T Node<T>::getValue() {
    return(m_value); // We return m_value
}

template <typename T> // We use the templated type T in this method
void Node<T>::setPrevious(Node<T>* next) {
    m_previous = next; // We set the m_previous Node pointer to the next Node pointer passed in as a parameter
}

template <typename T> // We use the templated type T in this method
Node<T>* Node<T>::getPrevious() {
    return(m_previous); // We return the m_previous pointer
}

template <typename T> // We use the templated type T in this method
void Node<T>::setNext(Node<T>* prev) {
    m_next = prev; // We set the m_next pointer to the previous Node pointer passed in as a parameter
}

template <typename T> // We use the templated type T in this method
Node<T>* Node<T>::getNext() {
    return(m_next); // We return the m_next Node
}
