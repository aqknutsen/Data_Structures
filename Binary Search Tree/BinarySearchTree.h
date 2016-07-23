/**
*	@file :BinarySearchTree.h
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: This class implements the BSTI interface. It has methods that allow you to deep copy a BST, check if a BST is empty, add a value to a BST, and print a BST
*/




#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTI.h" // We include the BSTI interface that will be implemented

#include <iostream> // We include iostream since we print data


template <typename T> // We template the class and inherit from the BinarySearchTreeInterface
class BinarySearchTree: public BSTI<T> {


public:

    /**
     * @pre - None
     * @post - Sets m_root to nullptr
     * @param - None
     */
    BinarySearchTree();



    /**
     * @pre - We assume other is a valid BinarySearchtree object. We assume the copyTree helper method functions properly.
     * @post - Copy Constructor: Makes a deep copy of the BinarySearchTree passed in as a parameter using the copyTree helper method
     * @param - const BinarySearchTree<T>& other - The BinarySearchTree to be copied.
     */
    BinarySearchTree(const BinarySearchTree<T>& other);


    /**
     * @pre - We assume the deleteTree private method functions properly.
     * @post - Deletes the BinarySearchTree using the deleteTree method
     * @param - None
     */
    ~BinarySearchTree();


    /**
     *  Note: Implementation of an interface method
     * @pre - The copy constructor of the BinarySearchTree class works properly.
     * @post - This method will make a deep copy of the BinarySearchTree for which the method is called. It relies on the copy constructor that will be implemented in the BinarySearchTree class
     * @param - None
     * @return - BSTI<T>* - The BSTI<T>* pointer that points to the deep copied BinarySearchTree will be returned
     */
    virtual BSTI<T>* clone();



    /**
     *  Note: Implementation of an interface method
     * @pre - Assume the m_root variable of the BinarySearchTree class has been pointer at nullptr or a valid Node
     * @post - Returns true if the m_root variable points at nullptr(BST is empty). Returns false if the m_root variable points at a valid Node object (BST is not empty)
     * @param - None
     * @return - bool - true if the m_root variable points at nullptr(BST is empty). Returns false if the m_root variable points at a valid Node object (BST is not empty)
     */
    bool isEmpty() const;



    /**
     *  Note: Implementation of an interface method
     * @pre - We assume the parameter passed in is a valid T value. We assume the Node class' methods function properly, and m_root has been initialized.
     * @pre - We assume the other add function in the BinarySearchTree class functions properly.
     * @post - This method add's the T value to the corresponding Binary Search Tree for which the methods was called using the other add function in the BinarySearchTree class. If the value is in the tree already, we return false
     * @param - T value - Value to be added to the BinarySearchTree
     * @return - bool - Returns true if the value is added (always returns true).
     */
    bool add(T value);



    /**
     *  Note: Implementation of an interface method
     * @pre - We assume m_root of the BinarySearchTree class has been initialized. We assume the other printTree method in the BinarySearchTree class functions properly. We assume the parameter is a valid order.
     * @post - If the BinarySearchTree is empty, we print a message saying so. If the tree is not empty, we use the other printTree method to print the tree.
     * @param - Order order - Represents the order for the tree to be printed in (PRE, IN, POST)
     * @return - None
     */
    void printTree(Order order) const;



    /**
     *  Note: Implementation of an interface method
     * @pre - We assume the printTree method above works properly.
     * @post - Prints the tree in In_ORDER (calls the above method with the parameter IN_ORDER)
     * @param - None
     * @return - None
     */
    void sortedPrint() const;



    /**
     * @pre - We assume the type T is comparable with ==. We assume the ValueNotFoundException class functions properly. We asssume m_root of the BinarySearchTree class functions properly
     * @pre - We assume that the other search function in the BinarySearchTree class functions properly.
     * @post - If the BinarySearchTree for which the method is called is empty, we throw an exception. Otherwise, we use the other search function to look for the value.
     * @param - T value - Value to be searched for
     * @return - T - Returns the value if it is found
     */
    T search(T value) const throw (ValueNotFoundException);



private:



    /**
     * @pre - We assume the parameter passed in is a valid T value. We assume the Node class' methods function properly, and we assume subtree is a valid Node pointer
     * @post - This method add's the T value to the corresponding Binary Search Tree for which the methods was called by calling itself recursively
     * @param - T value - Value to be added to the BinarySearchTree, Node<T>* subtree - Subtree to be searched for where to add the value properly
     * @return - bool - Returns true if the value is added (always returns true).
     */
    bool add(T value, Node<T>* subtree);




    /**
     * @pre - We assume the subTree passed in is a valid Node pointer, and we assume the methods in the Node class function properly
     * @post - This method deletes an entire BinarySearchTree by calling itself recursively.
     * @param - Node<T>* subTree - Subtree to be deleted
     * @return - None
     */
    void deleteTree(Node<T>* subTree);




    /**
     * @pre - We assume the type T is comparable with ==. We assume the ValueNotFoundException class functions properly. We assume subtree is valid Node pointer. We assume the Node class methods work properly.
     * @post - If the BinarySearchTree for which the method is called is not found, we throw an exception. Otherwise, we call the method recursively until the value is found
     * @param - T value - Value to be searched for, Node<T>* subtree - Subtree to be searched in
     * @return - T - Returns the value if it is found
     */
    T search(T value, Node<T>* subtree) const throw (ValueNotFoundException);





    /**
     * @pre - We assume subtree is a valid Node pointer, and we assume Order is a valid order (PRE, IN, POST). We assume the methods of the Node class function properly.
     * @post - This method calls itself recursively to print all the values in a tree in either (PRE_ORDER, IN_ORDER, or POST_ORDER)
     * @param - Node<T>* subtree - Subtree to be printed Order order - Represents the order for the tree to be printed in (PRE, IN, POST)
     * @return - None
     */
    void printTree(Node<T>* subtree,Order order) const;



    /**
     * NOTE: Helper method used to copy a BinarySearchTree. Could not figure out how to clone a tree without a method that uses recursion. Called in the copy constructor
     * @pre - We assume subtree is a valid Node pointer. We assume the methods of the Node class function properly.
     * @post - This method calls itself recursively on the left subtree and the right subtree of the BST for which it is called to copy all the values.
     * @param - Node<T>* - Returns the root Node to the new copied tree
     * @return - None
     */
    Node<T>* copyTree(Node<T>* subtree);




    Node<T>* m_root; // Represents a pointer that points to the root Node in a BST








};


#include "BinarySearchTree.hpp" // We include the corresponding BinarySearchTree.h file


#endif
