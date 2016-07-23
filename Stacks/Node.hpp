/**
*	@file : Node.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: Implentation of the Node class
*/

template <typename T>
Node<T>::Node() {
    m_value = T(); // We initially set m_value equal to the default value of the T constructor at construction time
    m_next = nullptr; // We initially point our pointer at nullptr at construction time
}


template <typename T>
void Node<T>::setValue(T val) {
    m_value  = val; // We set the value of m_value to the parameter passed in
}


template <typename T>
T Node<T>::getValue() {
    return(m_value); // We return m_value
}


template <typename T>
void Node<T>::setNext(Node* prev) {
    m_next = prev; // We set the previous Node pointer to the next node Pointer m_next
}


template <typename T>
Node<T>* Node<T>::getNext() {
    return(m_next); // We return the m_next Node
}
