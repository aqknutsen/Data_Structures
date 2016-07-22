/**
*	@file : LinkedList.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.06
*	@brief: Implementation of the linkedlist class
*/

#include "LinkedList.h"



void LinkedList::removeAt(int index) throw (std::runtime_error) {


    if(isEmpty() || index <0 || index > m_size-1) {

        throw(std::runtime_error("Invalid index"));
    }

    if(m_size==1) {

        delete m_front;
        m_front=nullptr;
        m_size--;
    }

    else if (index==0) {

        Node* temp = m_front;
        m_front=m_front->getNext();
        delete temp;
        m_size--;
    }

    else if (index==m_size-1) {

        Node* new_back = m_front;

        while(new_back->getNext()->getNext()!=nullptr) {

            new_back=new_back->getNext();
        }

        Node* old_back=new_back->getNext();

        delete old_back;
        old_back=nullptr;
        m_size--;

        new_back->setNext(nullptr);


    }

    else {

        Node* left = m_front;
        for(int i=0; i < index-1; i++) {

            left=left->getNext();
        }

        Node* r_node=left->getNext();
        Node* right = r_node->getNext();

        delete r_node;
        r_node==nullptr;
        m_size--;

        left->setNext(right);
    }

}

void LinkedList::insertAt(int index, int value) throw(std::runtime_error) {

    if(index <0 || index>m_size-1 && !isEmpty()) {

        throw(std::runtime_error("Invalid index!"));
    }

    else if(isEmpty()) {

        Node* new1 = new Node();
        new1->setNext(nullptr);
        new1->setValue(value);
        m_size++;
    }

    else if (index==0) {

        Node* new_node = new Node();
        new_node->setValue(value);
        new_node->setNext(m_front);
        m_front=new_node;
        m_size++;
    }

    else if (index==m_size-1) {


        Node* old_back = m_front;

        while(old_back->getNext()!=nullptr) {

            old_back=old_back->getNext();

        }

        Node* new_back = new Node();
        new_back->setNext(nullptr);
        new_back->setValue(value);

        old_back->setNext(new_back);

        m_size++;
    }

    else {

        Node* left = m_front;

        for(int i =0 ; i <index-1;i++) {

            left=left->getNext();
        }

        Node* middle = new Node();
        middle->setValue(value);

        Node* right = left->getNext();

        left->setNext(middle);

        middle->setNext(right);

        m_size++;


    }


}

void LinkedList::moveNode(int startIndex, int endIndex) throw (std::runtime_error) {

    if(startIndex < 0 || endIndex> m_size-1 || m_size==1 || startIndex>=endIndex) {

        throw(std::runtime_error("Invalid start or end index!"));
    }

    else {

        if(startIndex==0 && endIndex==m_size-1) {

            Node* old_back = m_front;

            while(old_back->getNext()!=nullptr) {

                old_back=old_back->getNext();
            }

            Node* new_back = new Node();
            new_back->setValue(m_front->getValue());
            new_back->setNext(nullptr);

            old_back->setNext(new_back);

            Node* temp = m_front;

            m_front=m_front->getNext();

            delete temp;

            temp==nullptr;

        }

        else if (startIndex==0) {

            Node* left = m_front;

            for(int i =0; i < endIndex; i++) {

                left=left->getNext();
            }

            Node* right = left->getNext();

            Node* middle = new Node();
            middle->setValue(m_front->getValue());
            middle->setNext(right);

            left->setNext(middle);


           Node* temp = m_front;

           m_front==m_front->getNext();

           delete temp;

           temp==nullptr;


        }

        else if (endIndex==m_size-1) {

            Node* move_left = m_front;
            Node* move_middle = m_front;
            Node* move_right = nullptr;

            Node* old_back = m_front;

            for(int i =0; i < startIndex;i++) {
                move_middle=move_middle->getNext();

            }

             for(int i =0; i < startIndex-1;i++) {
                move_left=move_left->getNext();

            }

            move_right = move_middle->getNext();



             while(old_back->getNext()!=nullptr) {

                old_back=old_back->getNext();
            }



            Node* new_back = new Node();

            new_back->setValue(move_middle->getValue());
            new_back->setNext(nullptr);

            old_back->setNext(new_back);

            delete move_middle;
            move_middle=nullptr;

            move_left->setNext(move_right);

        }

        else {

            Node* move_left = m_front;
            Node* move_middle = m_front;
            Node* move_right = nullptr;


            Node* back_left = m_front;
            Node* back_right = nullptr;

            for(int i =0; i <startIndex;i++) {

                move_middle=move_middle->getNext();
            }

            for(int i =0 ; i <startIndex-1;i++) {

                move_left=move_left->getNext();
            }

            move_right=move_middle->getNext();

            for(int i =0; i < endIndex;i++) {

                back_left=back_left->getNext();
            }

            back_right=back_left->getNext();

            Node* back_middle = new Node();
            back_middle->setValue(move_middle->getValue());
            back_middle->setNext(back_right);
            back_left->setNext(back_middle);

            delete move_middle;
            move_middle=nullptr;

            move_left->setNext(move_right);


        }
    }


}
