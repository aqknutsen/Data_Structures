/**
*	@file Queue.hpp
*	@author John Gibbons
*	@date 2014.04.02
*/

template <typename T>
Queue<T>::Queue() : m_size(0), m_front(nullptr), m_back(nullptr)
{ }


template <typename T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return (m_size==0);
}


template <typename T>
void Queue<T>::enqueue(T newEntry)
{
	if(m_front == nullptr)
	{
		m_front = new Node<T>(newEntry);
		m_back = m_front;
	}
	else
	{
		Node<T>* temp = new Node<T>(newEntry);
		m_back->setNext(temp);
		m_back = temp;
	}

	m_size++;
}

template <typename T>
T Queue<T>::dequeue() throw(std::runtime_error)
{
    if(m_front == nullptr) {

        throw(std::runtime_error("Queue empty!"));
    }

    else if (m_size ==1) {

        Node<T>* temp = m_front;
        m_front = nullptr;
        m_back=nullptr;
        T value = temp->getValue();
        delete temp;
        m_size--;
        return(value);
    }

    else {

        Node<T>* temp = m_front;

        m_front = m_front->getNext();

        T value = temp->getValue();
        delete temp;
        m_size--;
        return(value);
    }

}

template <typename T>
void Queue<T>::backOfTheLine() throw (std::runtime_error)
{

    if (isEmpty()) {

        throw(std::runtime_error("Value not found!"));

    }

    else if (m_size ==1) {

        std::cout<<"List is only of size 1"<<std::endl;
    }

    else {

        Node<T>* temp = m_front;
        T value = temp->getValue();

        Node<T>* new_node = new Node<T>();
        new_node->setValue(value);
        new_node->setNext(nullptr);

        m_back->setNext(new_node);
        m_back = m_back->getNext();

        m_size++;

        this->dequeue();

    }
}

template <typename T>
T Queue<T>::peekFront() const throw(std::runtime_error)
{
	if(m_size > 0)
	{
		return(m_front->getValue());
	}
	else
	{
		throw( std::runtime_error("Peak attempted on empty queue") );
	}
}

template <typename T>
int Queue<T>::size() const
{
	return(m_size);
}


template <typename T>
void Queue<T>::print() const
{
    Node<T>* temp = m_front;
    while(temp!=nullptr) {
        std::cout<<temp->getValue()<< " ";
        temp = temp->getNext();
    }

}
