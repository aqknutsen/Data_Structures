/**
*	@file : DoubleLinkedList.hpp
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: Implementation of the DoubleLinkedList class
*/

template<typename T> // We use the templated type T in this method
DoubleLinkedList<T>::DoubleLinkedList() {
    m_front = nullptr; // We initialize m_front to nullptr at construction time
    m_back = nullptr; // We initialize m_back to nullptr at construction time
    m_size = 0; // We initialize m_size to 0 at construction time
}

template <typename T> // We use the templated type T in this method
DoubleLinkedList<T>::~DoubleLinkedList() { // A destructor that is used to delete all Node objects

    while (m_front != nullptr) { // While the m_front pointer is not pointing to null, this loop runs
        Node<T>* temp = m_front; // We initially set our temp Node to point to the the front Node
        m_front = m_front->getNext(); // We move the front node to the next node
        delete temp; // We delete the node pointing at by temp
        m_size--; // We reduce the size by one
    }
}

template <typename T> // We use the templated type T in this method
bool DoubleLinkedList<T>::isEmpty() const {

    if (m_size > 0) { // If the size of the list is greater than 0, we return false because the list is not empty
        return(false);
    }

    else { // If the size of the list is 0, we return true because the list is empty
        return(true);
    }

}

template <typename T> // We use the templated type T in this method
int DoubleLinkedList<T>::size() const {
    return(m_size); // We return the size of the DoubleLinkedList
}

template <typename T>// We use the templated type T in this method
void DoubleLinkedList<T>::pushFront(T value) {



    if (isEmpty()) { // If the list isEmpty(), this if statement runs
        Node<T>* temp = new Node<T>(); // We create a new Node object
        temp->setValue(value); // We set the value of the Node object equal to the parameter passed in
        temp->setNext(nullptr); // We point the m_next pointer to nullptr since the list is only of size one
        temp->setPrevious(nullptr); // We point the m_previous pointer to nullptr since the list is only of size one
        m_front = temp; // We set m_front to point to the one Node object
        m_back = temp; // We set m_back to point to the one Node object
        m_size++; // We increase the size of the list
    }

    else { // If the list already exists, this else statement runs
        Node<T>* temp = new Node<T>(); // We create a temporary node
        temp->setValue(value); // We set the value of our new Node to the parameter passed in
        temp->setNext(m_front); // We set the m_next pointer of our new Node object to the second Node object
        temp->setPrevious(nullptr); // We set the m_previous pointer of our new Node object equal to nullptr
        m_front->setPrevious(temp); // We set the m_previous pointer of the second Node object equal to our new Node object
        m_front = temp; // We move the m_front pointer to our front Node object
        m_size++; // We increase the size of the list by one
    }
}

template <typename T> // We use the templated type T in this method
void DoubleLinkedList<T>::pushBack(T value) {

    if(isEmpty()) { // If the list is empty, we create one new Node object
        pushFront(value); // We use the pushFront method to make a new Node object since the list is only of size one
        m_size++; // We increase the size of the list by one
    }

    else { // We have a list already

        Node<T>* temp2 = new Node<T>(); // We create a temp Node for our new Node object
        temp2->setNext(nullptr); // We set the m_next pointer of the newt Node object equal to nullptr
        temp2->setValue(value); // We set the value passed in as a parameter to the new Node object value

        Node<T>* temp = m_front; // We create a new temp Node and set it equal to m_front
        while(temp->getNext()!=nullptr) { // We loop through all the Node objects until we reach the second to last Node object
            temp = temp->getNext();
        }
        temp->setNext(temp2); // We point the m_next pointer of the 2nd to last object to the last object
        temp2->setPrevious(temp); // We set the m_previous pointer of the last Node object equal to the second to last Node object
        m_back = temp2; // We set m_back equal to the newly created Node
        m_size++; // We increase the size of the list by one
    }

}

template <typename T> // We use the templated type T in this method
bool DoubleLinkedList<T>::remove(T value) {
    Node<T>* temp = find(value); // We call the find method. If the value is found, this method will return the Node object containing the value. If the value is not found, the method returns nullptr

    if (temp == nullptr) { // If the value is not found, we return false
        return(false);
    }
    else if (isEmpty()) { // If the list is empty, we return false
        return(false);
    }
    else if(m_front == temp && m_back == temp) { // If the size of the list is one, and the value is found in this Node this statement runs
        delete temp; // We delete the node
        m_front = nullptr; // We set m_front equal to nullptr since the list is empty
        m_back = nullptr; // We set m_back equal to nullptr since the list is empty
        m_size--; // We reduce the size of the list by one
        return(true); // We return true since a value was deleted
    }
    else if (m_front == temp) { // If the value is found in the front Node object, this else if statement runs
        m_front = m_front->getNext(); // We move the m_front pointer to the second Node object
        m_front->setPrevious(nullptr); // We set the m_previous value of the second Node object equal to nullptr
        delete temp; // We delete the first Node object
        m_size--; // We reduce the size of the list by one
        return(true); // We return true since a value was deleted
    }
    else if (m_back == temp) { // If the value is found in the last Node object, this else if statement runs
        m_back = m_back->getPrevious(); // We set the m_back pointer to the second to last Node object
        m_back->setNext(nullptr); // We set the m_next value of the last Node object equal to nullptr
        delete temp; // We delete the last Node object
        m_size--; // We reduce the size of the list by one
        return(true); // We return true since a value was deleted
    }
    else { // If the value is found in some middle Node, this else statement runs
        temp->getPrevious()->setNext(temp->getNext()); // We set m_next of the previous Node object to the Node object beyond the next Node
        temp->getNext()->setPrevious(temp->getPrevious()); // We set m_previous of the next Node object to the Node object beyond the previous Node
        delete(temp); // We delete the Node object containing the value in the middle
        m_size--;  // We reduce the size of the list by one
        return(true); // We return true since a value was deleted
    }


}

template <typename T> // We use the templated type T in this methods
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error) {
    Node<T>* temp; // We create a temporary node pointer
    temp = find(listValue); // We call the find method. If the value is found, this method will return the Node object containing the value. If the value is not found, the method returns nullptr. Temp stores the returned Node.
    if (temp == m_front && m_front!=nullptr) { // If the list is found in the front Node, and the list is not empty this if statement runs. We use the pushFront method to put a new Node in the front of the list, and we increase the size by one
        pushFront(newValue);
        m_size++;
    }
    else if (temp == nullptr) { // If the value is not found in the list, we throw an error and print a message
        throw std:: runtime_error ("Value not found!");
    }
    else { // If the value is found in a Node that is not the front Node, this else statement runs
        Node<T>*temp2 = temp->getPrevious(); // We get the Node previous to the Node that contains the value

        Node<T>* temp1 = new Node<T> (); // We create a new Node temp1
        temp1->setValue(newValue); // We set the value of temp1 equal to the newValue passed in as a parameter

        temp2->setNext(temp1); // We set the m_next pointer of the Node object behind the new Node object equal to the new Node object
        temp->setPrevious(temp1); // We set the m_previous pointer of the Node object in front of the new Node object equal to the new Node object
        temp1->setPrevious(temp2); // We set the m_previous pointer of the new Node to the previous Node
        temp1->setNext(temp); // We set the m_next pointer of the new Node to the next Node
        m_size++; // We increase size by one
    }

}

template <typename T> // We use the templated type T in this method
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error) {
    Node<T>* temp; // We create a temporary node pointer
    temp = find(listValue); // We call the find method. If the value is found, this method will return the Node object containing the value. If the value is not found, the method returns nullptr. Temp stores the returned Node.
    if (temp == m_back && m_back!=nullptr) { // If the value is found in the back Node and the list is not empty, we use the pushBack method to put a new Node in the back of the list, and we increase the size by one
        pushBack(newValue);
        m_size++;
    }
    else if (temp == nullptr) { // If the value is not found in the list, we throw an error and print a message
        throw std:: runtime_error ("Value not found!");
    }
    else { // If the value is found in a Node that is not the back Node, this else statement runs
        Node<T>*temp2 = temp->getNext(); // We get the Node behind the Node that contains the value

        Node<T>* temp1 = new Node<T> (); // We create a new Node temp1
        temp1->setValue(newValue); // We set the value of the New node to the parameter passed in

        temp2->setPrevious(temp1);  // We set the m_previous pointer of the back Node object to the new Node object
        temp->setNext(temp1); // We set the m_next pointer of the front Node object to the new Node object
        temp1->setPrevious(temp); // We set the m_previous pointer of the new Node object to the previous Node object
        temp1->setNext(temp2); // We set the m_next pointer of the new Node to the next Node
        m_size++; // We increase size by one
    }
}

template <typename T> // We use the templated type T in this method
Node<T>* DoubleLinkedList<T>::find(T value) const {

    Node<T>* temp = m_front; // We create a temporary node pointer that points to the front Node


    while(temp!=nullptr) { // We run the loop until we get to the last Node object

        if (temp->getValue() == value) { // Searches for the value in the Node object the pointer is pointing to
            return(temp); // If the searched value is found, we return the Node object that contains the value
        }
        temp = temp->getNext(); // Moves pointer from previous position to next position
    }
    return(nullptr); // If the value is not found, we return nullptr
}

template <typename T> // We use the templated type T in this method
void DoubleLinkedList<T>::printList() const {
    Node<T>* temp = m_front; // We create a temporary pointer that points to the first Node object
    while(temp!=nullptr) { // We loop through all the Node objects in the DoubleLinkedList
       if (temp->getNext()== nullptr) { // If the value is in the last Node object, we print the value with no comma
        T value = temp->getValue(); // We get the value for the Node object in the DoubleLinkedList
        std::cout<<value; // We print the value with no comma
        temp = temp->getNext(); // We go to the next Node object
       }
       else { // If the value is in not in the last Node object, we print the value with a comma
           T value = temp->getValue(); // We get the value for each Node object in the DoubleLinkedList
           std::cout<<value << ","; // We print the value with a comma
           temp = temp->getNext(); // We go to the next Node object
       }
    }

}

