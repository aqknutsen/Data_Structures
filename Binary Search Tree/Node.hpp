/**
*	@file : Node.hpp
*	@author :  Alec Knutsen
*	@date : 2015.04.13
*	@brief: Implementation of the Node class (see .h file for method descriptions)
*/


template <typename T> // We use the templated type T in this method
Node<T>::Node() {


    m_value = T(); // We initially set m_value equal to the default constructor of T at construction time

    m_left = nullptr; // We initially point our m_left pointer at nullptr at construction time

    m_right = nullptr; // We initially point our m_right pointer at nullptr at construction time


}

template <typename T> // We use the templated type T in this method
Node<T>::Node(const Node<T>& other) {


    m_left = nullptr; // We initially set the m_left Node pointer of the copied Node object to nullptr in case the Node object were coping has a left pointer that points to nullptr

    m_right = nullptr; // We initially set the m_right Node pointer of the copied Node object to nullptr in case the Node object were coping has a right pointer that points to nullptr

    m_value = other.m_value; // We  copy the m_value into our newly created Node object from the Node object we are copying

    if (other.m_left!= nullptr) { // If the Node object has a valid left pointer, we copy it into the m_left pointer of our newly created Node object


        m_left = new Node<T>(*((other.m_left)));


    } // End of if


    if (other.m_right!= nullptr) { // If the Node object has a valid right pointer, we copy it into the m_right pointer of our newly created Node object


        m_right = new Node<T>(*((other.m_right)));


    } // End of if


}

template <typename T>
Node<T>::Node(T value) {

    this->m_value = value; // We copy the value passed in as a parameter into the current Node. Same as the constructor above except only the value is copied!


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
void Node<T>::setLeft(Node<T>* left) {

    m_left = left; // We set the m_left Node pointer to the left Node pointer passed in as a parameter

}

template <typename T> // We use the templated type T in this method
Node<T>* Node<T>::getLeft() {

    return(m_left); // We return the m_left pointer

}

template <typename T> // We use the templated type T in this method
void Node<T>::setRight(Node<T>* right) {

    m_right = right; // We set the m_right pointer to the previous Node pointer passed in as a parameter

}

template <typename T> // We use the templated type T in this method

Node<T>* Node<T>::getRight() {

    return(m_right); // We return the m_right Node

}
