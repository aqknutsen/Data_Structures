/**
*	@file : StackInterface.h
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: This class is an interface (contains all pure virtual methods). All methods are pure virtual and will be redfined in the stack class. The constructor is virtual as well.
*   @brief: This class contains methods that push a value onto the front of a Stack, pop a value off the front of a Stack, and look at the value in the front of a Stack.
*   @brief: Furthermore, this class contains methods that see if a Stack is empty, return the size of a Stack, and print the elements of a Stack
*   @brief: Finally, the operators <,<=,>, >=,==,and != are all redefined to compare the sizes of two Stacks
*/



/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/


#ifndef STACKINTERFACE_H_INCLUDED
#define STACKINTERFACE_H_INCLUDED


#include "PreconditionViolationException.h" // We include the PreconditionViolationException class since our methods pop and peek will throw exceptions


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


    /**
     * @pre -  We assume m_front points to nullptr or a valid object. We assume each Node object has an initialized T value and a m_next pointer that points to nullptr or to another Node object.
     * @post - This method prints each T value in a Stack.
     * @param - None
     * @return - None
     */
    virtual void print() const = 0;


    /**
     * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
     * @post - This method compares the size of two Stack
     * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
     * @return - bool - Returns true if the Stack passed in as a parameter has a size greater than the size of the Stack for which the method was called. Otherwise, the method returns false.
     */
    virtual bool operator< (const StackInterface<T>& rhs) const = 0;


    /**
    * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
    * @post - This method compares the size of two Stack
    * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
    * @return - bool - Returns true if the Stack passed in as a parameter has a size greater than or equal to the size of the Stack for which the method was called. Otherwise, the method returns false.
    */
    virtual bool operator<= (const StackInterface<T>& rhs) const = 0;


    /**
    * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
    * @post - This method compares the size of two Stack
    * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
    * @return - bool - Returns true if the Stack passed in as a parameter has a size less than to the size of the Stack for which the method was called. Otherwise, the method returns false.
    */
    virtual bool operator > (const StackInterface<T>& rhs) const = 0;


    /**
    * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
    * @post - This method compares the size of two Stack
    * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
    * @return - bool - Returns true if the Stack passed in as a parameter has a size less than or equal to the size of the Stack for which the method was called. Otherwise, the method returns false.
    */
    virtual bool operator>= (const StackInterface<T>& rhs) const = 0;


    /**
    * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
    * @post - This method compares the size of two Stack
    * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
    * @return - bool - Returns true if the Stack passed in as a parameter has a size equal to the size of the Stack for which the method was called. Otherwise, the method returns false.
    */
    virtual bool operator== (const StackInterface<T>& rhs) const = 0;


    /**
    * @pre - We assume m_size has been initialized and the size method of the StackInterface class implemented in Stack.hpp functions properly.
    * @post - This method compares the size of two Stack
    * @param - const StackInterface<T>& rhs - We pass a StackInterface object by reference; however, since we cant create objects of StackInterface, we will pass Stack objects as parameters for this method (polymorphism).
    * @return - bool - Returns true if the Stack passed in as a parameter has a size not equal to the size of the Stack for which the method was called. Otherwise, the method returns false.
    */
    virtual bool operator!= (const StackInterface<T>& rhs) const = 0;



};


#endif
