/**
*	@file : LinkedList.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.06
*	@brief: Implementation of the linkedlist class
*/

#include "LinkedList.h"

LinkedList::LinkedList() {
    m_front = nullptr; // We initialize m_front to nullptr at construction time
    m_size = 0; // We initialize m_size to 0 at constrcution time
}


LinkedList::~LinkedList() { // A destructor that is used to delete all Node objects

    while (isEmpty() == false) { // While the list is not empty, this loop runs
        removeFront(); // We remove the front of the list until the list is empty
    }
}


bool LinkedList::isEmpty() const {

    if (m_size > 0) { // If the size of the list is greater than 0, we return false because the list is not empty
        return(false);
    }

    else { // If the size of the list is 0, we return true because the list is empty
        return(true);
    }

}


int LinkedList::size() const {
    return(m_size); // We return the size of the linkedlist
}


bool LinkedList::search(int value) const {

    Node* temp; // We create a temporary node pointer
    temp = m_front; // We set the temporary node pointer equal to m_front so that it points to the first Node Object

    while(temp!=nullptr) { // We run the loop until we get to the last Node object

        if (temp->getValue() == value) { // Searches for the value in the Node object the pointer is pointing to
            return(true); // If the searched value is found, we return true
        }
        temp = temp->getNext(); // Moves pointer from previous position to next position
    }
    return(false); // If the value is not found after the while loop is done, we return false
}


void LinkedList::printList() const {
    Node* temp = m_front; // We create a temporary pointer that poinst to the first Node objevct
    while(temp!=nullptr) { // We loop through all the Node objects in the linkedlist
       int value = temp->getValue(); // We get the value for each Node object in the linkedlist
       std::cout<<value << " "; // We print the value
       temp = temp->getNext(); // We go to the next Node object
    }
}


void LinkedList::addBack(int value) {

    if(isEmpty()) { // If the list is empty, we create one new Node object
        m_front = new Node();  // We create a new node and set m_front equal to the new Node
        m_front->setValue(value); // We set the value of the new_node to the value passed in as a parameter
        m_front->setNext(nullptr); // We set the next pointer equal to null since the linkedlist is only of size 1
        m_size++; // We increase the size of the list by one
    }

    else { // We have a list already
        Node* temp = m_front; // We create a new temp Node and set it equal to m_front
        Node* temp2 = new Node(); // We create another temp Node. This temp node will be our new Node object at the back
        temp2->setNext(nullptr); // We set the m_next pointer of the last Node object equal to nullptr
        temp2 -> setValue(value); // We set the value passed in as a parameter to the last Node object value

        while(temp->getNext()!=nullptr) { // We loop through all the Node objects until we reach the second to last Node object
            temp = temp->getNext();
        }
        temp->setNext(temp2); // We point the pointer of the 2nd to last object to the last object
        m_size++; // We increase the size of the list by one
    }

}

void LinkedList::addFront(int value) {



    if (isEmpty()) { // If the list isEmpty(), this if statement runs
        m_front = new Node(); // We create a new node and set m_front pointer equal to it
        m_front->setValue(value); // We set the value of the front node object equal to the parameter passed in
        m_front->setNext(nullptr); // We point the m_next pointer to nullptr since the list is only of size one
        m_size++; // We increase the size of the list
    }

    else { // If the list already exists, this else statement runs
        Node* temp = m_front; // We create a temporary node and set it so that it points at the front node object (about to be the second node object)
        m_front = new Node(); // We create a new Node and set m_front pointing to it
        m_front->setValue(value); // We set the value of the front Node object to the value passed in as a parameter
        m_front->setNext(temp); // We set the m_next pointer of the front Node object so that it points to the second object
        m_size++; // We increaase the size of the list by one
    }
}

bool LinkedList::removeBack() {

    if(isEmpty()) { // If the list is empty, there is no value to remove, so we return false
        return(false); // We return false if the size is not reduced
    }
    else if (m_size ==1) { // If the size is one, we call the removeFront method to remove the value since it does not matter if the value is removed from the back or front
        removeFront(); // Call of the removeFront method
        m_size--; // We reduce the m_size by one
        return(true); // We return true if the size is reduced
    }
    else {
        Node* temp1 = m_front; // We create a temp pointer that points to the front Node object
        Node* temp2 = m_front; // We create another temp pointer that points to the front Node object

        while(temp1->getNext()!=nullptr) { // We loop through all the node objects until temp1 is set to the last Node object
            temp1 = temp1->getNext();
        }

        while (temp2->getNext()!=temp1) { // We loop through all the node objects until temp2 is set to the second to last Node object
            temp2 = temp2->getNext();
        }

        delete temp1; // We delete the last Node object which is pointed at by temp1
        temp2->setNext(nullptr); // The second to last object becomes the last object. Thus, we set the pointer of the last Node object to nullptr
        m_size--; // We reduce the size of the linkedlist
        return(true); // We return true since a Node object is removed

    }

}

bool LinkedList::removeFront() {

    if(isEmpty()) { // If the linkedlist is empty, there is no value to delete
        return(false); // We return false since there is no value to delete
    }
    else { // If the linkedlist is not empty, this else statement runs
        Node* temp; // We create a temporary node
        temp = m_front; // We set the temporary node so that it points at the front Node object
        m_front=m_front->getNext(); // We move the front pointer to the next Node object
        delete temp; // We delete the front Node that is pointed at by temp
        m_size--; // We reduce the size by one
        return(true); // We return true since the value is deleted

    }
}
