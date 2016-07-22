/**
*	@file DoubleLinkedList.hpp
*	@date 2014.02.23
*	Updated: 2014.09.30
*	@author John Gibbons
*/

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T>* temp = m_front;
	Node<T>* next = nullptr;

	while(temp != nullptr)
	{
		next = temp->getNext();
		delete temp;
		m_size--;
		temp = next;
	}
}

template <typename T>
int DoubleLinkedList<T>::size()
{
	return(m_size);
}


template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return(m_size == 0);
}



template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>();
	temp->setValue(value);

	if(m_size == 0)
	{
		m_front = temp;
		m_back = temp;
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
	}
	else
	{
		temp->setPrevious(nullptr);
		temp->setNext(m_front);
		m_front->setPrevious(temp);
		m_front = temp;
	}

	m_size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T value) throw (std::runtime_error)
{

	Node<T>* right = find(listValue);

	if(right==nullptr || isEmpty()) {

		throw(std::runtime_error("No value found!"));
	}

	else if(right == m_front) {
		Node<T>* test = new Node<T>;
		test->setValue(value);
		test->setPrevious(nullptr);
		test->setNext(right);
		right->setPrevious(test);
		m_front=test;
		m_size++;

	}

	else {


	       Node<T>* left = right->getPrevious();
	       Node<T>* middle = new Node<T>;
	       middle->setValue(value);
	       middle->setPrevious(left);
	       middle->setNext(right);
	       left->setNext(middle);
	       right->setPrevious(middle);
	       m_size++;

	}
}



template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value)
{
	Node<T>* temp = m_front;

	while(temp != nullptr)
	{
		if(temp->getValue() == value)
		{
			return(temp);
		}
		else
		{
			temp = temp->getNext();
		}
	}

	return(nullptr);
}


template <typename T>
void DoubleLinkedList<T>::printList() const
{
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		std::cout << temp->getValue();
		if(temp->getNext() != nullptr)
		{
			std::cout << " ";
		}

		temp = temp->getNext();
	}
}


template <typename T>
void DoubleLinkedList<T>::printReverse() const
{

	if(m_size==0) {

	}

	else {

		Node<T>* temp = m_front;
		while(temp->getNext()!=nullptr) {
			temp=temp->getNext();
		}


		while(temp!=nullptr) {

			std::cout<<temp->getValue() << " " <<std::endl;
			temp=temp->getPrevious();

		}

	}


}

