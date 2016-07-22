/**
*	@file : StackInterface.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: This class is an interface (contains all pure virtual methods). All methods are pure virtual and will be redfined in the stack class. The destructor is virtual as well.
*   @brief: This class contains methods that push a value onto the front of a Stack, pop a value off the front of a Stack, and look at the value in the front of a Stack.
*   @brief: Furthermore, this class contains methods that see if a Stack is empty and returns the size of a stack
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/


#ifndef STACKINTERFACE_H_INCLUDED
#define STACKINTERFACE_H_INCLUDED

#include "PreconditionViolationException.h" // We inherit from the PVE class to throw exceptions for the methods pop and peek.


template <typename T> // We make StackInterface a templated class


class StackInterface {


public:


    /**
     * @pre - None
     * @post - A virtual destructor allows for a pointer to the interface class (e.g. StackInterface) to be able to virtually call the destructor of the derived class when being deleted
     * @param - None
     */
    virtual ~StackInterface() {};


    /**
     * @pre - We assume m_size has been initialized (it is at construction time)
     * @post - This method checks if a Stack is empty. If the Stack is empty, the method returns true. If the Stack is not empty, the method returns false
     * @param - None
     * @return - bool - Returns true if the Stack is empty and returns false if the Stack is not empty
     */
    virtual bool isEmpty() const = 0;


    /**
    * @pre - We assume each Node object contains a valid T value and valid m_next pointer that either points to another Node object or nullptr.
    * @post - This method adds a new Node object to the front of a Stack. If the Stack is empty, a new Node is made, m_front points at the new Node, and the next pointer points to nullptr. We increase m_size by one.
    * @post - If the Stack is not empty, the a New node is created and m_front is set to point to it. The m_front next Node points to the second Node object. We increase m_size by one.
    * @post - The m_next pointer of the second to last Node object points to the newly created Node object. The m_back pointer is set to the newly created object. The m_size variable is increased by one.
    * @param - T newEntry - Represents the T value that is added to the new Node object
    * @return - None
    */
    virtual void push(const T newEntry) = 0;


    /**
     * @pre - We assume each Node object contains a valid T value and valid m_next pointer that either points to another Node object or nullptr.
     * @post - This method removes the front Node object in a Stack.
     * @post - If the Stack is empty, we throw a PreconditionViolationException because there is no Node to delete.
     * @post - If the Stack is of size 1, we delete the only Node, set m_front equal to nullptr, reduce the size by one, and return the T value in the Node that was removed.
     * @post - If the Stack is greater than size 1, we delete the front Node, set m_front equal to the second Node, reduce the size by one, and return the T value in the Node that was removed.
     * @param - None
     * @return - T - Returns the T value of the Node object that was removed
     */
    virtual T pop() throw(PreconditionViolationException) = 0;

    /**
     * @pre - We assume the front Node object contains a valid T value.
     * @post - This method returns the T value of the front Node object in a Stack. If the Stack is empty, we throw a PreconditionViolationException because there is no value to return. Otherwise, we return the T value.
     * @param - None
     * @return - T -  Returns the T value of the Node object at the front of a Stack.
     */
    virtual T peek() const throw(PreconditionViolationException) = 0;


    /**
     * @pre - None
     * @post - This method returns the int value m_size representing the size of a Stack
     * @param - None
     * @return - int - Represents the size of a Stack
     */
    virtual int size() const = 0;


};


#endif
