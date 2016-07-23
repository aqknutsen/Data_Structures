/**
*	@file :BSTI.h
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: This is an interface class the will be implemented by the BinarySearchTree class.
*   @brief: This class creates an enumerated type Order. Also, it contains methods that will clone a BST, check if a BST is empty, add a value to a BST, search a BST for a value, and print a BST.
*   @brief: Finally, this class contains a virtual destructor that will delete a BST
*/




#ifndef BSTI_H
#define BSTI_H


#include "ValueNotFoundException.h" // We include ValueNotFoundException since some of the method's in this class throw this type of exception

#include "Node.h" // We include Node.h since some of our methods will be interacting with nodes



/**
 * @brief: This creates an enumerated type Order that has three variables PRE_ORDER, IN_ORDER, and POST_ORDER
 */
enum Order {

        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,


};


template <typename T> // We template the class
class BSTI {

public:



    /**
     * @pre - A valid BTSI pointer exists
     * @post - A virtual destructor allows for a pointer to the interface class (e.g. BSTI.h) to be able to virtually call the destructor of the derived class when being deleted
     * @param - None
     */
    virtual~BSTI(){};



    /**
     * @pre - The copy constructor of the BinarySearchTree class works properly.
     * @post - This method will make a deep copy of the BinarySearchTree for which the method is called. It relies on the copy constructor that will be implemented in the BinarySearchTree class
     * @param - None
     * @return - BSTI<T>* - The BSTI<T>* pointer that points to the deep copied BinarySearchTree will be returned
     */
    virtual BSTI<T>* clone() =0;



    /**
     * @pre - Assume the m_root variable of the BinarySearchTree class has been pointer at nullptr or a valid Node
     * @post - Returns true if the m_root variable points at nullptr(BST is empty). Returns false if the m_root variable points at a valid Node object (BST is not empty)
     * @param - None
     * @return - bool - true if the m_root variable points at nullptr(BST is empty). Returns false if the m_root variable points at a valid Node object (BST is not empty)
     */
    virtual bool isEmpty() const =0;



    /**
     * @pre - We assume the parameter passed in is a valid T value. We assume the Node class' methods function properly, and m_root has been initialized.
     * @pre - We assume the other add function in the BinarySearchTree class functions properly.
     * @post - This method add's the T value to the corresponding Binary Search Tree for which the methods was called using the other add function in the BinarySearchTree class. If the value is in the tree already, we return false
     * @param - T value - Value to be added to the BinarySearchTree
     * @return - bool - Returns true if the value is added (always returns true).
     */
    virtual bool add(T value) = 0;



    /**
     * @pre - We assume the type T is comparable with ==. We assume the ValueNotFoundException class functions properly. We asssume m_root of the BinarySearchTree class functions properly
     * @pre - We assume that the other search function in the BinarySearchTree class functions properly.
     * @post - If the BinarySearchTree for which the method is called is empty, we throw an exception. Otherwise, we use the other search function to look for the value.
     * @param - T value - Value to be searched for
     * @return - T - Returns the value if it is found
     */
    virtual T search(T value) const throw(ValueNotFoundException) =0;



    /**
     * @pre - We assume m_root of the BinarySearchTree class has been initialized. We assume the other printTree method in the BinarySearchTree class functions properly. We assume the parameter is a valid order.
     * @post - If the BinarySearchTree is empty, we print a message saying so. If the tree is not empty, we use the other printTree method to print the tree.
     * @param - Order order - Represents the order for the tree to be printed in (PRE, IN, POST)
     * @return - None
     */
    virtual void printTree(Order order) const =0;




    /**
     * @pre - We assume the printTree method above works properly.
     * @post - Prints the tree in In_ORDER (calls the above method with the parameter IN_ORDER)
     * @param - None
     * @return - None
     */
    virtual void sortedPrint() const =0;


};

#endif
