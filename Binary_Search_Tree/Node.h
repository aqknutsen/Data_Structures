/**
*	@file :Node.h
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: This class contains get and set methods for a Node objects left pointer, right pointer, and T value.
*   @brief: Also, this class has three constructors: one that initializes all the object's variables to default values,one that makes a deep copy of the Node itself, and one that copies a value into a node (used in copyhelper in the BST class)
*/




#ifndef NODE_H
#define NODE_H


template <typename T> // We template the class
class Node {


public:



    /**
    * @pre - None
    * @post - This constructor initializes the m_value variable to the default template constructor. Also, the pointers m_left and m_right are set to nullptr.
    * @param - None
    */
    Node();



    /**
    * @pre - We assume the parameter passed in is a valid Node object
    * @post - This constructor makes a deep copy of the Node passed in as a parameter. We create a new Node and copy the value of the Node, the m_left pointer and m_right pointer from other to the new Node
    * @param - const Node<T>& other - Represents the Node that will be deep copied
    */
    Node(const Node<T>& other);


    /**
    * NOTE: This constructor is used in the copyHelper method which makes a deep copy of a BST. Instead of using the above constructor.
    * NOTE: I use this constructor instead because I could not figure out a way to deep copy a BST using the other Node constructor!
    * @pre - We assume the parameter passed in is a valid T value
    * @post - This constructor makes a copy of the T value into a new Node
    * @param - T value - Value that will be copied into a new Node
    */
    Node(T value);


    /**
     * @pre - We assume the parameter passed in is a valid data type T
     * @post - This method sets m_value to the parameter passed in
     * @param - T val - Represents the T value m_value will be set too
     * @return - None
     */
    void setValue(T value);


    /**
     * @pre - We assume the T m_value has been initialized
     * @post - This method returns the value of m_value
     * @param - None
     * @return - Returns T m_value
     */
    T getValue();


     /**
     * @pre - We assume the Node pointer passed in as a parameter points at a valid object or nullptr
     * @post - This method sets the pointer m_left to the pointer passed in as a parameter
     * @param - Node<T>* left - Represents the left pointer
     * @return - None
     */
    void setLeft(Node<T>* left);


    /**
     * @pre - We assume the m_left Node pointer has been initialized to nullptr or points at a valid object
     * @post - This method returns the pointer m_left
     * @param - None
     * @return - Node<T>* - Returns the m_left pointer
     */
    Node<T>* getLeft();


    /**
     * @pre - We assume the Node passed in as a parameter points at a valid object or nullptr
     * @post - This method sets the pointer m_right to the pointer passed in as a parameter
     * @param - Node<T>* right - Represents the right pointer that m_right will be set too
     * @return - None
     */
    void setRight(Node<T>* right);


    /**
     * @pre - We assume the m_right Node pointer has been initialized to nullptr or points at a valid object
     * @post - This method returns the pointer m_right
     * @param - None
     * @return - Node* m_right - Returns the m_right pointer
     */
    Node<T>* getRight();




private:


    Node<T>* m_left; // The current object's left node pointer


    Node<T>* m_right; // The current object's right node pointer



    T m_value; // The current object's T value



};



#include "Node.hpp" // We include the "Node.hpp" file



#endif
