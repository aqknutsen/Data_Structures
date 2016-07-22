/**
*	@file :BinarySearchTree.hpp
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: Implementation of the BinarySearchTree.h file (see .h file for method descriptions
*/





#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

/**
* Important Notes
*   A local variable in a recursive call does not change the variable for the call
*   A new variable is edited for each call

*/
template <typename T>
T BinarySearchTree<T>::sumEntireTree() {

    if(this->m_root==nullptr) {

        return(T());
    }
    else {

        sumEntireTree(m_root);
    }

}

template<typename T>
int BinarySearchTree<T>::maxDepth() const {

    if(m_root==nullptr) {

        return(0);
    }

    else {

        this->maxDepth(m_root);
    }

}

template<typename T>
int BinarySearchTree<T>::countNodes() const {

     if(m_root==nullptr) {

        return(0);
    }

    else {

        this->countNodes(m_root);
    }

}




template <typename T>
T BinarySearchTree<T>::sumEntireTree(Node<T>* subtree) {

    T sum = subtree->getValue();

    if(subtree->getLeft()!=nullptr) {
        sum +=sumEntireTree(subtree->getLeft());
    }

    if(subtree->getRight()!=nullptr) {
        sum+=sumEntireTree(subtree->getRight());
    }

    return(sum);


}

template<typename T>
int BinarySearchTree<T>::maxDepth(Node<T>* subtree) const {



    int depth_left = 1;
    int depth_right = 1;

    if(subtree->getLeft()!=nullptr) {

        depth_left +=maxDepth(subtree->getLeft());
    }

    if(subtree->getRight()!=nullptr) {

        depth_right+=maxDepth(subtree->getRight());

    }

    if(depth_left < depth_right) {

        return(depth_right);
    }
    else {
        return(depth_left);
    }
}

template <typename T>
int BinarySearchTree<T>::countNodes(Node<T>* subtree) const {


    int sum = 1;

    if(subtree->getLeft()!=nullptr) {

        sum+=countNodes(subtree->getLeft());
    }

    if(subtree->getRight()!=nullptr) {

        sum+=countNodes(subtree->getRight());
    }

    return(sum);


}








#endif // BINARYSEARCHTREE_HPP
