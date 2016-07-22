/**
*	@file : DoubleLinkedList.hpp
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: Implementation of the DoubleLinkedList class
*/


template <typename T>
bool DoubleLinkedList<T>::removePairs(T value) {

    if(isEmpty() || m_size==1 || find(value)==nullptr || find(value)==m_back) {

        return(false);
    }

    else {

        Node<T>* firstfind = find(value);

        while(firstfind->getNext()!=nullptr) {

            if(firstfind->getNext()->getValue()==value) {

                if(m_size==2) {

                    delete m_front;
                    delete m_back;
                    m_front=nullptr;
                    m_back=nullptr;
                    m_size=m_size-2;
                    return(true);
                }

                else if (find(value)==m_front) {

                    Node<T>* temp = m_front;
                    Node<T>* temp2 = m_front;

                    m_front=temp2->getNext();
                    m_front->setPrevious(nullptr);

                    delete temp;
                    delete temp2;
                    m_size=m_size-2;
                    return(true);
                }

                else if(find(value)==m_back->getPrevious()) {

                    Node<T>* temp = m_back->getPrevious();
                    Node<T>* temp2 = m_back;

                    m_back=temp->getPrevious();
                    m_back->setNext(nullptr);

                    delete temp;
                    delete temp2;


                    m_size=m_size-2;
                    return(true);
                }

                else {

                    Node<T>* temp = find(value);
                    Node<T>* temp2 = temp->getNext();

                    Node<T>* left = temp->getPrevious();
                    Node<T>* right = temp2->getNext();

                    left->setNext(right);
                    right->setPrevious(nullptr);

                    delete temp;
                    delete temp2;

                    m_size=m_size-2;
                    return(true);

                }
            }

            else {

                firstfind=firstfind->getNext();
            }

            return(false);
        }

    }


}

template <typename T>
bool DoubleLinkedList<T>::isSorted() const {


    if(isEmpty()) {

        return(false);
    }

    else if(m_size==1) {

        return(true);
    }

    else {

        Node<T>* it = m_front;

        while(it->getNext()!=nullptr) {

            if(it->getValue() > it->getNext()->getValue()) {
                return(false);
            }

            it=it->getNext();
        }

        return(true);

    }

}

template <typename T>

void DoubleLinkedList<T>::removeAllDuplicates() {

    if(!(isSorted()) || isEmpty() || m_size==1) {


    }

    else {

        Node<T>* temp = m_front;
        while(temp->getNext()!=nullptr) {

            T value = temp->getValue();


            if(value == temp->getNext()->getValue()) {


                remove(value);
                temp=temp->getNext();
            }

           else {

                temp=temp->getNext();

           }
        }
    }


}

template <typename T>
DoubleLinkedList<T>* DoubleLinkedList<T>::mergeLists(DoubleLinkedList<T>& list1, DoubleLinkedList<T>& list2) throw(std::runtime_error) {

    if(!(list1.isSorted()) || !(list2.isSorted())) {

        throw(std::runtime_error("Merge Lists requires sorted lists!"));
    }

    else {

        Node<T>* list1_it = list1.m_front;


        while(list1_it->getNext()!=nullptr) {

            T value = list1_it->getValue();

            if(list2.isEmpty()) {

                Node<T>* new_node = new Node<T>();
                new_node->setValue(value);
                new_node->setNext(nullptr);
                new_node->setPrevious(nullptr);

                list2.m_front = new_node;
                list2.m_back=new_node;

                list2.m_size++;
            }

            else {

                if(value <= list2.m_front->getValue()) {

                    Node<T>* new_node = new Node<T>();

                    new_node->setValue(value);

                    new_node->setPrevious(nullptr);

                    new_node->setNext(list2.m_front);

                    list2.m_front->setPrevious(new_node);

                    list2.m_front=new_node;

                    list2.m_size++;
                }

                else {

                    Node<T>* it = list2.m_front;

                    while(it!=nullptr) {

                        if(value < it->getValue()) {

                            break;
                        }
                        it=it->getNext();
                    }

                    if(it==nullptr) {

                        Node<T>* new_back = new Node<T>();
                        new_back->setValue(value);
                        new_back->setNext(nullptr);
                        new_back->setPrevious(list2.m_back);

                        list2.m_back->setNext(new_back);

                        list2.m_back=new_back;

                        list2.m_size++;
                    }

                    else {

                        Node<T>* left = it->getPrevious();

                        Node<T>* middle = new Node<T>();

                        middle->setPrevious(left);
                        middle->setNext(it);
                        middle->setValue(value);

                        left->setNext(middle);
                        it->setPrevious(middle);

                        list2.m_size++;

                    }

                }
            }

            list1_it=list1_it->getNext();
        }

        DoubleLinkedList<T>* merged = new DoubleLinkedList<T>();

        *(merged) = list2;

        return(merged);

    }

}


template <typename T>
void DoubleLinkedList<T>::sortedInsert(T value) throw(std::runtime_error) {


    if(!isSorted()) {

            throw(std::runtime_error("List not sorted!"));

    }

    if(isEmpty()) {

        Node<T>* new_node = new Node<T>();
        new_node->setValue(value);
        new_node->setNext(nullptr);
        new_node->setPrevious(nullptr);

        m_front = new_node;
        m_back=new_node;

        m_size++;
    }

    else {

        if(value <= m_front->getValue()) {

            Node<T>* new_node = new Node<T>();

            new_node->setValue(value);

            new_node->setPrevious(nullptr);

            new_node->setNext(m_front);

            m_front->setPrevious(new_node);

            m_front=new_node;

            m_size++;
        }

        else {

            Node<T>* it = m_front;

            while(it!=nullptr) {

                if(value < it->getValue()) {

                    break;
                }
                it=it->getNext();
            }

            if(it==nullptr) {

                Node<T>* new_back = new Node<T>();
                new_back->setValue(value);
                new_back->setNext(nullptr);
                new_back->setPrevious(m_back);

                m_back->setNext(new_back);

                m_back=new_back;

                m_size++;
            }

            else {

                Node<T>* left = it->getPrevious();

                Node<T>* middle = new Node<T>();

                middle->setPrevious(left);
                middle->setNext(it);
                middle->setValue(value);

                left->setNext(middle);
                it->setPrevious(middle);

                m_size++;

            }

        }



    }
}
