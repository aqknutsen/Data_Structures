/**
*	@file : DoubleLinkedList.h
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: This class contains methods for deleting a Node object with a specific value from a Linked List.
    @brief: Also, this class contains methods that allow a Node object to be added:
                To the front of a DoubleLinkedList.
                To the back of a DoubleLinkedList.
                Behind a certain Node Object in a DoubleLinkedList.
                In front of a certain Node Object in a DoubleLinkedList.
*   @brief: This class has methods to print the values within a DoubleLinkedList, and it also has a method for searching for a value in a DoubleLinkedList.
    @brief: This class has methods that return a size of a DoubleLinkedList and check if a DoubleLinkedList is empty.
    @brief: Finally, this class has a constructor and a destructor, used to delete all Node objects in a LinkedList.
*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <iostream> // We include the <iostream> library for printing the list
#include <stdexcept> // We include the <stdexcept> library for the insertAhead and insertBehind methods
#include <string> // We include the <string? library

template <typename T> // We make a templated class with typename T
class DoubleLinkedList {
public:

    /**
     * @pre - None
     * @post - This constructor initializes m_front to nullptr, m_back to nullptr, and m_size to 0.
     * @param - None
     */
    DoubleLinkedList();


    /**
     * @pre - None
     * @post - This destructor deletes all Node objects until the DoubleLinkedList is empty
     * @param - None
     */
    ~DoubleLinkedList();


    /**
     * @pre - We assume m_size has been initialized (it is at construction time)
     * @post - This method checks if the DoubleLinkedList is empty. If the list is empty, the method returns true. If the list is not empty, the method returns false
     * @param - None
     * @return - bool - Returns true if the list is empty and returns false if the list not empty
     */
    bool isEmpty() const;


    /**
     * @pre - We assume m_size has been initialized (it is at construction time)
     * @post - This method returns the variable m_size representing the size of the DoubleLinkedList
     * @param - None
     * @return - int m_size - Returns the value of m_size representing the size of the DoubleLinkedList
     */
    int size() const;


   /**
     * @pre - We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr.
     * @post - This method adds a new Node object to the front of a DoubleLinkedList
     * @post - The m_next pointer of the new object is set to the second node object or nullptr if the list was initially empty. The m_previous of the new Node object is set to nullptr
     * @post - The m_front pointer points to the newly created Node object. The second node object is set to the newly created Node object if the DoubleLinkedList was not empty. We increase the size of the list by one.
     * @param - T value - Represents the T value that is added to the first Node object
     * @return - None
     */
    void pushFront(T value);


     /**
     * @pre - We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr.
     * @post - This method adds a new Node object to the back of a DoubleLinkedList. If the DoubleLinkedList is empty, the pushFront method is use to add a Node object to create a DoubleLinkedList
     * @post - If the DoubleLinkedList is not empty, the m_next pointer of the new object is set to nullptr. The m_previous pointer is sent to the second to the second to last Node object.
     * @post - The m_next pointer of the second to last Node object points to the newly created Node object. The m_back pointer is set to the newly created object. The m_size variable is increased by one.
     * @param - T value - Represents the T value that is added to the first Node object
     * @return - None
     */
    void pushBack(T value);


    /**
     * @pre - We assume the find method of the DoubleLinkedList class functions properly. We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr.
       @post - This method tries to delete a Node object that contains the parameter passed in.
         * @post - If the DoubleLinkeList is empty, we return false because there is nothing to delete.
         * @post - If the parameter found passed in is not in any of the Node objects, we return false because there is nothing to delete.
         * @post - If the size of the DoubleLinkedList is one and the parameter passed in is found in this object, the Node object is deleted, m_front and m_back are set to nullptr, and the size is reduced by one. We return true.
         * @post - If the parameter is found in the front Node object in the DoubleLinkedList, the m_front pointer is moved to the second Node object,
                   the m_previous pointer of the second Node object is set to nullptr, and the front Node object is deleted. The size is also reduced by one, and we return true.
         * @post - If the parameter is found in the last Node object in the DoubleLinkedList, the m_back pointer is moved to the second to last Node object,
                   the m_next pointer of the second to last Node object is set to nullptr, and the back Node object is deleted. The size is also reduced by one, and we return true.
         * @post - If the parameter is found in some middle Node object, the Node object before m_next is set to the Node object after, and the Node object after m_previous is set to the Node object before.
               The Node object is deleted, the size is reduced by one, and we return true.
     * @param - None
     * @return - bool - Returns true if a Node object is deleted; otherwise, returns false
     */
    bool remove(T value);

     /**
     * @pre - We assume the find method and pushFront method of the DoubleLinkedList class function properly. We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr. We assume listValue is in the list.
     * @post - This method attempts to insert a new Node object before a Node object where T listvalue is found.
         * @post - If the listValue is found in the front Node, we call the pushFront method to add a new Node object to the front of the list. We increase the size by one.
         * @post - If the listValue is not found, throw the std runtime_error.
         * @post - If the listValue is found in not the front Node object, we create a new Node object. The m_next and m_previous pointers are set to the previous and next Node respectively.
                   The m_next pointer of the previous Node is set to the new Node. The m_previous pointer of the next Node is set to the new Node. We increase the m_size by one.
     * @param - T listValue - Represents the value to be looked for in the Node object, T newValue - Represents the new value put in the new node object.
     * @return - None
     */
    void insertAhead(T listValue, T newValue) throw (std::runtime_error);


      /**
     * @pre - We assume the find method and pushBack method of the DoubleLinkedList class function properly. We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr. We assume listValue is inthe list.
     * @post - This method attempts to insert a new Node object behind a Node object where T listvalue is found.
         * @post - If the listValue is found in the back Node, we call the pushBack method to add a new Node object to the back of the list. We increase the size by one.
         * @post - If the listValue is not found, throw the std runtime_error.
         * @post - If the listValue is found in not the back Node object, we create a new Node object. The m_next and m_previous pointers are set to the previous and next Node respectively.
                   The m_next pointer of the previous Node is set to the new Node. The m_previous pointer of the next Node is set to the new Node. We increase the m_size by one.
     * @param - T listValue - Represents the value to be looked for in the Node object, T newValue - Represents the new value put in the new node object.
     * @return - None
     */
    void insertBehind(T listValue, T newValue) throw (std::runtime_error);


    /**
     * @pre - We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr. We assume the T value passed in is valid. We assume T is comparable with ==.
     * @post - This method searches through the DoubleLinkedList looking for a value in each Node object. If the value is found, the method returns the Node object with the value. If the value is not found, the method returns nullptr.
     * @param - T value - Represents the value that is search for
     * @return - Node<T>* - If the value is found, the method returns returns the Node object containing the value. If the value is not found, the method returns nullptr.
     */
    Node<T>* find(T value) const;


    /**
     * @pre -  We assume each Node object contains a valid T value and valid m_next and m_previous pointers that either point to another Node object or nullptr. We assume type T is overloaded to be printable via the << operator.
     * @post - This method prints each T value in a DoubleLinkedList.
     * @param - None
     * @return - None
     */
    void printList() const;

    bool removePairs(T value);

    bool isSorted() const;

    void removeAllDuplicates();

    DoubleLinkedList<T>* mergeLists(DoubleLinkedList<T>& list1, DoubleLinkedList<T>& list2) throw(std::runtime_error);

    void sortedInsert(T value) throw(std::runtime_error);


private:

   Node<T>* m_front; // This pointer variable is going to be used to point to the front Node object in a DoubleLinkedList
   Node<T>* m_back; // This pointer variable is going to be used to point to the last Node object in a DoubleLinkedList
   int m_size; // This variable will hold the size of a DoubleLinkedList
};

#include "DoubleLinkedList.hpp" // We include the "DoubleLinkedList.hpp" file

#endif
