/**
*	@file : Node.h
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: This class includes getters and setters for an T m_value. Also, this class includes getters and setters for a pointer m_next.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<typename T> // We create a templated class of type T
class Node {
public:

    /**
     * @pre - None
     * @post - This constructor initializes the m_value variable to the default value of the constructor T() and sets the pointer m_next = nullptr
     * @param - None
     */
    Node();


    /**
     * @pre - We assume the parameter passed in is a valid integer
     * @post - This method sets the m_value to the parameter passed in
     * @param - T val
     * @return - None
     */
    void setValue(T val);


    /**
     * @pre - We assume the T m_value has been initialized
     * @post - This method returns the value of m_value
     * @param - None
     * @return - Returns T m_value
     */
    T getValue();


    /**
     * @pre - We assume the Node passed in as a parameter points at a valid object or nullptr
     * @post - This method sets the pointer m_next to the pointer passed in as a parameter
     * @param - Node* prev - Represents the previous pointer
     * @return - None
     */
    void setNext(Node* prev);


    /**
     * @pre - We assume the m_next Node pointer has been initialized to nullptr or points at a valid object
     * @post - This method returns the pointer m_next
     * @param - None
     * @return - Node* m_next - Returns the m_next pointer
     */
    Node* getNext();


private:

    T m_value; // This variable will hold T value for each Node object

    Node* m_next; // This pointer will point to the next Node Object
};

#include "Node.hpp" // We include the "Node.hpp" file

#endif
