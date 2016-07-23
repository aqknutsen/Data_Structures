/**
*	@file : LinkedList.h
*	@author :  Alec Knutsen
*	@date : 2014.02.06
*	@brief: This class contains methods for deleting from the back and front of a linked list. Also, this class contains methods that allow a Node object to be added to the front or back of a linkedlist
*   @brief: This class has methods to print the values within the linkedlist, and also has a method for searching for a value in the linkedlist.
    @brief: This class has methods that return the linkedlist size and check if the linkedlist is empty.
*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <iostream> // We include iostream for printing the list

class LinkedList {
public:

    /**
     * @pre - None
     * @post - This constructor initializes m_front to nullptr and m_size to 0
     * @param - None
     */
    LinkedList();


    /**
     * @pre - None
     * @post - This destructor uses the isEmpty() method and the removeFront() method to delete all Node objects until the linkedlist is empty
     * @param - None
     */
    ~LinkedList();


    /**
     * @pre - We assume m_size has been initialized (it is at construction time)
     * @post - This method checks if the linkedlist is empty. If the list is empty, the method returns true. If the list is not empty, the method returns false
     * @param - None
     * @return - bool - Returns true if the list is empty and returns false if the list not empty
     */
    bool isEmpty() const;


    /**
     * @pre - We assume m_size has been initialized (it is at construction time)
     * @post - This method returns the variable m_size representing the size of the linkedlist
     * @param - None
     * @return - int m_size - Returns the value of m_size representing the size of the linkedlist
     */
    int size() const;


    /**
     * @pre - We assume m_front points to nullptr or a valid object. We assume each Node object has an initialized integer and a m_next pointer that points to nullptr or to another Node object.
     * @post - This method searches through the linkedlist looking for a value. If the value is found, the method returns true. If the value is not found, the method returns false
     * @param - int value - Represents the value that is search for
     * @return - bool - If the value is found, the method returns true. If the value is not found, the method returns false
     */
    bool search(int value) const;


    /**
     * @pre -  We assume m_front points to nullptr or a valid object. We assume each Node object has an initialized integer and a m_next pointer that points to nullptr or to another Node object.
     * @post - This method prints each int value in the linkedlist.
     * @param - None
     * @return - None
     */
    void printList() const;


    /**
     * @pre - If the linkedlist is not empty, we assume each Node object has a valid integer and a valid pointer that either points to the next Node object or nullptr. Also, we increase the size of the list by one.
     * @post - This method adds a new Node object to the end of the linkedlist. The m_next pointer of the new object is set to null and the previous Node pointer points to the newly created Node object.
     * @param - int value - Represents the int value that is added to the last Node object
     * @return - None
     */
    void addBack(int value);


    /**
     * @pre - None
     * @post - This method adds a new Node object to the front of the linkedlist. The m_next pointer of the new object is set to the second node object or nullptr if the list was initially empty. The m_front pointer points to the newly created Node object. We increase the size of the list by one.
     * @param - int value - Represents the int value that is added to the first Node object
     * @return - None
     */
    void addFront(int value);


    /**
     * @pre - We assume each Node object contains a valid integer and a pointer that either points to another Node object or nullptr.
     * @post - If the linkedlist is empty, we return false because there is nothing to delete.
     * @post - If the linkedlist is of size one, we call the removeFront method to delete the one Node object. We reduce the m_size by one and return true.
     * @post - If the linkedlist is of size greater than one, we delete the last Node object in the list. We loop until we get to the last Node object, and then we delete the Node object. The m_next pointer of the second to last object now points to nullptr. We reduce m_size by one and return true.
     * @param - None
     * @return - bool - Returns true if a Node object is deleted; otherwise, returns false
     */
    bool removeBack();


    /**
     * @pre - None
     * @post - If the linkedlist is empty, we return false because there is nothing to delete.
     * @post - If the linkedlist is not empty, we create a temporary node pointer that points to the first Node object. We delete the node object, and then we set m_front to point to the new front Node object. We reduce m_size by one and return true.
     * @param - None
     * @return - bool - Returns true if a Node object is deleted; otherwise, returns false
     */
    bool removeFront();


private:

    Node* m_front; // This pointer variable is going to be used to point to the front Node object in a linkedlist

    int m_size; // This varaible will hold the size of the linkedlist
};


#endif
