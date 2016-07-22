
/**
*	@file : Node.h
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: This class includes getters and setters for an int m_value of a Node object. Also, this class includes getters and setters for a front and back pointer of a Node object.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*
* The name you choose is up to you. Convention is to use the name of your header file
* in all caps, replacing the period with an underscore.
*/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>

template <typename T> // This class is a template class. This way we can use whatever data type we want.
class Node {

public:
    /**
     * @pre - None
     * @post - This constructor initializes the m_value variable to the default template constructor. Also, the pointers m_next and m_previous are set to nullptr.
     * @param - None
     */
    Node();


    /**
     * @pre - We assume the parameter passed in is a valid data type T
     * @post - This method sets the m_value to the parameter passed in
     * @param - T val
     * @return - None
     */
    void setValue(T val);


    /**
     * @pre - We assume the T m_value has been initialized
     * @post - This method returns the value of m_value
     * @param - None
     * @return - Returns the int m_value
     */
    T getValue();


    /**
     * @pre - We assume the Node pointer passed in as a parameter points at a valid object or nullptr
     * @post - This method sets the pointer m_previous to the pointer passed in as a parameter
     * @param - Node* next - Represents the next pointer
     * @return - None
     */
    void setPrevious(Node<T>* next);


    /**
     * @pre - We assume the m_previous Node pointer has been initialized to nullptr or points at a valid object
     * @post - This method returns the pointer m_previous
     * @param - None
     * @return - Node* m_previous - Returns the m_previous pointer
     */
    Node<T>* getPrevious();


    /**
     * @pre - We assume the Node passed in as a parameter points at a valid object or nullptr
     * @post - This method sets the pointer m_next to the pointer passed in as a parameter
     * @param - Node* prev - Represents the previous pointer
     * @return - None
     */
    void setNext(Node<T>* prev);


    /**
     * @pre - We assume the m_next Node pointer has been initialized to nullptr or points at a valid object
     * @post - This method returns the pointer m_next
     * @param - None
     * @return - Node* m_next - Returns the m_next pointer
     */
    Node<T>* getNext();


private:
    T m_value; // Represents the value stored in each Node object
    Node<T>* m_previous; // Represents the pointer of the Node Object that will point to another Node object behind it
    Node<T>* m_next; // Represents the pointer of the Node Object that will point to another Node object in front of it
};
#include "Node.hpp" // We include the "Node.hpp" file

#endif
