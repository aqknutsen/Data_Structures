
/**
*	@file : Stack.hpp
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: Implementation of the Stack class
*/


template<typename T> // We use the templated type T in this method
Stack<T>::Stack() {
    m_front = nullptr; // We initialize m_front to nullptr at construction time
    m_size = 0; // We initialize m_size to 0 at construction time
}

template <typename T> // We use the templated type T in this method
Stack<T>::~Stack() { // A destructor that is used to delete all Node objects in a Stack

    while (m_front != nullptr) { // While the m_front pointer is not pointing to null, this loop runs

        Node<T>* temp = m_front; // We initially set our temp Node to point to the the front Node

        m_front = m_front->getNext(); // We move the front node to the next node

        delete temp; // We delete the node pointing at by temp

        m_size--; // We reduce the size by one
    }
}



template <typename T> // We use the templated type T in this method
bool Stack<T>::isEmpty() const {

    if (m_size > 0) { // If the size of the list is greater than 0, we return false because the list is not empty

        return(false);
    }

    else { // If the size of the list is 0, we return true because the list is empty

        return(true);
    }


}


template <typename T> // We use the templated type T in this method
void Stack<T>::push(const T newEntry){

    if (isEmpty()) { // If the list isEmpty(), this if statement runs

        m_front = new Node<T>(); // We create a new node and set m_front pointer equal to it
        m_front->setValue(newEntry); // We set the value of the front node object equal to the parameter passed in
        m_front->setNext(nullptr); // We point the m_next pointer to nullptr since the list is only of size one

        m_size++; // We increase the size of the list
    }

    else { // If the list already exists, this else statement runs
        Node<T>* temp = m_front; // We create a temporary node and set it so that it points at the front node object (about to be the second node object)

        m_front = new Node<T>(); // We create a new Node and set m_front pointing to it
        m_front->setValue(newEntry); // We set the value of the front Node object to the value passed in as a parameter
        m_front->setNext(temp); // We set the m_next pointer of the front Node object so that it points to the second object

        m_size++; // We increaase the size of the list by one
    }

}


template <typename T> // We use the templated type T in this method
T Stack<T>::pop() throw (PreconditionViolationException) {

    if(isEmpty()) { // If the Stack empty, there is no value to delete

        throw PreconditionViolationException("Exception: Pop attempted on an empty stack"); // We throw a PreconditionViolationException with a message
    }

    else if (m_size == 1) { // If the Stack is of size one, this else if statement runs

        Node<T>* temp; // We create a temporary node
        temp = m_front; // We set the temporary node so that it points at the front Node object

        T value = m_front->getValue(); // We get the T value of the Node object about to be deleted

        m_front=nullptr; // We set the m_front pointer to nullptr since the list is about to be empty

        delete temp; // We delete the front Node that is pointed at by temp

        m_size--; // We reduce the size by one

        return(value); // We return the T value of the Node object that was deleted

    }

    else { // If the Stack is of size greater than one, this else statement runs

        Node<T>* temp; // We create a temporary node

        temp = m_front; // We set the temporary node so that it points at the front Node object

        T value = m_front->getValue(); // We get the T value of the Node object about to be deleted

        m_front=m_front->getNext(); // We move the front pointer to the next Node object

        delete temp; // We delete the front Node that is pointed at by temp

        m_size--; // We reduce the size by one

        return(value); // We return the T value of the Node object that was deleted

    }

}


template <typename T> // We use the templated type T in this method
T Stack<T>::peek() const throw(PreconditionViolationException) {

    if (isEmpty()) { // If the Stack is empty, we throw a PreconditionVioaltionException with a message

        throw PreconditionViolationException("Exception: Peek attempted on an empty stack");
    }

    else { // If the Stack is not empty, we return the T value in the front Node object

        return(m_front->getValue());
    }

}


template <typename T> // We use the templated type T in this method
int Stack<T>::size() const {

 return(m_size); // We return the size of the Stack

}


template <typename T> // We use the templated type T in this method
void Stack<T>::print() const {

    if (isEmpty()) { // If the Stack is empty, we print a message saying so

        std::cout<<"Stack Empty";
    }

    else { // If the Stack is not empty, this else statement runs

        Node<T>* temp = m_front; // We create a temporary pointer that poinst to the first Node object

        while(temp!=nullptr) { // We loop through all the Node objects in the Stack

           T value = temp->getValue(); // We get the value for each Node object in the Stack

           std::cout<<value << " "; // We print the value

           temp = temp->getNext(); // We go to the next Node object

        }

    }

}


template <typename T> // We use the templated type T in this method
bool Stack<T>::operator<(const StackInterface<T> & rhs)const {

    if (m_size < rhs.size()) { // If the Stack passed in as a parameter, has a size greater than the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }

}


template <typename T> // We use the templated type T in this method
bool Stack<T>::operator<=(const StackInterface<T> & rhs)const {

    if (m_size <= rhs.size()) { // If the Stack passed in as a parameter, has a size greater than or equal to the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }

}


template <typename T> // We use the templated type T in this method
bool Stack<T>::operator>(const StackInterface<T> & rhs)const {

    if (m_size > rhs.size()) { // If the Stack passed in as a parameter, has a size less than the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }

}

template <typename T> // We use the templated type T in this method
bool Stack<T>::operator>=(const StackInterface<T> & rhs)const {

    if (m_size >= rhs.size()) { // If the Stack passed in as a parameter, has a size less than or equal to the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }

}

template <typename T> // We use the templated type T in this method
bool Stack<T>::operator==(const StackInterface<T> & rhs)const {

    if (m_size == rhs.size()) { // If the Stack passed in as a parameter, has a size equal to the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }

}

template <typename T> // We use the templated type T in this method
bool Stack<T>::operator!=(const StackInterface<T> & rhs)const {

    if (m_size != rhs.size()) { // If the Stack passed in as a parameter, has a size not equal to the Stack this method is called for, we return true. Otherwise, we return false

        return(true);
    }

    else {
        return(false);

    }
}




