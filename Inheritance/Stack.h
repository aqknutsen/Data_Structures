/**
*	@file : Stack.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: This class is a derived class of the StackInterface interface. All pure virtual methods of the StackInterface class are implemented.
*   @brief: This class contains methods that push a value onto the front of a Stack, pop a value off the front of a Stack, and look at the value in the front of a Stack.
*   @brief: Furthermore, this class contains methods that see if a Stack is empty and a method that returns the size of a stack
*/



/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/




#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED



#include "StackInterface.h" // We include are interface StackInterface so we can use it
#include "Node.h" // We include the Node class since Stacks are composed of Node objects


template <typename T> // We template the Stack class
class Stack: public StackInterface<T> { // We inhert the StackInterface interface for our Stack class


public:

    /**
     * @pre - None
     * @post - This constructor initializes m_front to nullptr and m_size to 0
     * @param - None
     */
      Stack();


      /**
       * @pre - We assume each Node has a valid T value and points to valid Node pointer or Node object
       * @post - This method deletes all Node objects until a Stack is empty
       * @param - None
       */
     ~Stack();


     /**
      * @pre - We assume m_size has been initialized (it is at construction time)
      * @post - This method checks if a Stack is empty. If the Stack is empty, the method returns true. If the Stack is not empty, the method returns false
      * @param - None
      * @return - bool - Returns true if the Stack is empty and returns false if the Stack is not empty
      */
      bool isEmpty() const;


     /**
     * @pre - We assume each Node object contains a valid T value and valid m_next pointer that either points to another Node object or nullptr.
     * @post - This method adds a new Node object to the front of a Stack. If the Stack is empty, a new Node is made, m_front points at the new Node, and the next pointer points to nullptr. We increase m_size by one.
     * @post - If the Stack is not empty, the a New node is created and m_front is set to point to it. The m_front next Node points to the second Node object. We increase m_size by one.
     * @post - The m_next pointer of the second to last Node object points to the newly created Node object. The m_back pointer is set to the newly created object. The m_size variable is increased by one.
     * @param - T newEntry - Represents the T value that is added to the new Node object
     * @return - None
     */
     void push(const T newEntry);


     /**
     * @pre - We assume each Node object contains a valid T value and valid m_next pointer that either points to another Node object or nullptr.
     * @post - This method removes the front Node object in a Stack.
     * @post - If the Stack is empty, we throw a PreconditionViolationException because there is no Node to delete.
     * @post - If the Stack is of size 1, we delete the only Node, set m_front equal to nullptr, reduce the size by one, and return the T value in the Node that was removed.
     * @post - If the Stack is greater than size 1, we delete the front Node, set m_front equal to the second Node, reduce the size by one, and return the T value in the Node that was removed.
     * @param - None
     * @return - T - Returns the T value of the Node object that was removed
     */
     T pop() throw(PreconditionViolationException);


     /**
     * @pre - We assume the front Node object contains a valid T value.
     * @post - This method returns the T value of the front Node object in a Stack. If the Stack is empty, we throw a PreconditionViolationException because there is no value to return. Otherwise, we return the T value.
     * @param - None
     * @return - T -  Returns the T value of the Node object at the front of a Stack.
     */
     T peek() const throw(PreconditionViolationException);


     /**
     * @pre - None
     * @post - This method returns the int value m_size representing the size of a Stack
     * @param - None
     * @return - int - Represents the size of a Stack
     */
     int size() const;

private:

     Node<T>* m_front; // We use m_front as a private variable that will point to the front Node object in a stack

     int m_size; // This m_size variable will hold the size of a Stack


};


#include "Stack.hpp" // We include our Stack.hpp file

#endif // STACK_H_INCLUDED
