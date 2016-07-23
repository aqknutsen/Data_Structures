/**
*	@file :BinarySearchTree.hpp
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: Implementation of the BinarySearchTree.h file (see .h file for method descriptions
*/





#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP


template <typename T> // We use the templated type T in this method
BinarySearchTree<T>::BinarySearchTree() {

    m_root = nullptr;

}



template <typename T> // We use the templated type T in this method
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)  {

    m_root = new Node<T>(*(other.m_root));


}


template <typename T> // We use the templated type T in this method
BinarySearchTree<T>::~BinarySearchTree() {

    deleteTree(m_root);

}


template <typename T> // We use the templated type T in this method
BSTI<T>* BinarySearchTree<T>::clone() {


    BSTI<T>* clone = new BinarySearchTree<T>(*(this));
    return(clone);

}


template <typename T> // We use the templated type T in this method
bool BinarySearchTree<T>::isEmpty() const {
    return(m_root==nullptr);


}


template <typename T> // We use the templated type T in this method
bool BinarySearchTree<T>::add(T value) {
    return(add(value,m_root));



}


template <typename T> // We use the templated type T in this method
void BinarySearchTree<T>::printTree(Order order) const {

    printTree(m_root,order);


}

template <typename T> // We use the templated type T in this method
void BinarySearchTree<T>::sortedPrint() const {

        printTree(m_root,IN_ORDER);


}



template <typename T> // We use the templated type T in this method
T BinarySearchTree<T>::search(T value) const throw (ValueNotFoundException) {

    return(search(value,m_root));



}




template <typename T> // We use the templated type T in this method
bool BinarySearchTree<T>::add(T value, Node<T>* subtree) {


    if(subtree==nullptr) {

        Node<T>* new_node = new Node<T>();
        new_node->setValue(value);

        this->m_root = new_node;


   }


   else if (value==subtree->getValue()) {

            return(false);

   }

   else if (value<subtree->getValue()) {

        if(subtree->getLeft()!=nullptr) {

            add(value,subtree->getLeft());

         }

        else {

            Node<T>* node1 = new Node<T>();
            node1->setValue(value);
            subtree->setLeft(node1);

        }


  }

  else {

        if(subtree->getRight()!=nullptr) {

            add(value,subtree->getRight());

         }

        else {

            Node<T>* node1 = new Node<T>();
            node1->setValue(value);
            subtree->setRight(node1);

        }


  }
  return(true);


}


template <typename T> // We use the templated type T in this method
void BinarySearchTree<T>::deleteTree(Node<T>* subTree) {

    if (subTree==nullptr) {


        return;

    }

    else if (subTree->getLeft()!=nullptr) {


        deleteTree(subTree->getLeft());

    }

    else if (subTree->getRight()!=nullptr) {

        deleteTree(subTree->getRight());

    }


    delete subTree;





}



template <typename T> // We use the templated type T in this method
T BinarySearchTree<T>::search(T value, Node<T>* subtree) const throw (ValueNotFoundException) {

    if(subtree==nullptr) {

        throw(ValueNotFoundException("Value not in tree!"));

    }

    else if (subtree->getValue()==value) {

        return(value);

    }

    else if (value<subtree->getValue()) {

            search(value,subtree->getLeft());
     }

    else {

        search(value,subtree->getRight());

    }





}



template <typename T> // We use the templated type T in this method
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const {

    if(order == PRE_ORDER) {

        if (subtree!=nullptr) {


            std::cout<<subtree->getValue()<<std::endl;
            printTree(subtree->getLeft(),order);
            printTree(subtree->getRight(),order);
        }

    }


    else if(order == IN_ORDER) {

        if (subtree!=nullptr) {

             printTree(subtree->getLeft(),order);
            std::cout<<subtree->getValue()<<std::endl;

            printTree(subtree->getRight(),order);
        }

    }

    else if(order == POST_ORDER) {

        if (subtree!=nullptr) {

             printTree(subtree->getLeft(),order);
             printTree(subtree->getRight(),order);
            std::cout<<subtree->getValue()<<std::endl;


        }

    }




}


template <typename T> // We use the templated type T in this method
Node<T>* BinarySearchTree<T>::copyTree(Node<T>* subtree) {

    Node<T>* clone = nullptr;

    while(subtree!=nullptr) {

        clone = new Node<T>(subtree->getValue());
        clone->setLeft(copyTree(subtree->getLeft()));
        clone->setRight(copyTree(subtree->getRight()));

   }


    return(clone);
}








#endif // BINARYSEARCHTREE_HPP
