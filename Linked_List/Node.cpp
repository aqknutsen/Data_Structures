/**
*	@file : Node.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.06
*	@brief: Implentation of the Node class
*/

#include "Node.h"

Node::Node() {
    m_value = 0; // We initially set m_value equal to 0 at construction time
    m_next = nullptr; // We initially point our pointer at nullptr at construction time
}

void Node::setValue(int val) {
    m_value  = val; // We set the value of m_value to the parameter passed in
}

int Node::getValue() {
    return(m_value); // We return m_value
}

void Node::setNext(Node* prev) {
    m_next = prev; // We set the previous Node pointer to the next node Pointer m_next
}

Node* Node::getNext() {
    return(m_next); // We return the m_next Node
}
