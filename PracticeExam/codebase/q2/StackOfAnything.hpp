/** 	@file StackOfAnything.hpp
*	@author John Gibbons
*	@date 2014.02.02
*/


template <typename T>
StackOfAnything<T>::StackOfAnything()
{
    m_top = nullptr;
    m_size = 0;
}

template <typename T>
StackOfAnything<T>::~StackOfAnything()
{
    while(!isEmpty())
    {
        pop();
    }
}

template <typename T>
void StackOfAnything<T>::printStack() const
{
    StackableAnything<T>* temp = m_top;
    while(temp!=nullptr) {

        std::cout<<temp->getValue()<<std::endl;
        temp=temp->getPrevious();
    }
}


template <typename T>
T StackOfAnything<T>::findMax() const throw(std::runtime_error)
{
    if(this->m_top == nullptr)
    {
        throw( std::runtime_error("Stack empty"));
    }
    else
    {
        StackableAnything<T>* temp = this->m_top;
        T max = temp->getValue();
        while(temp != nullptr)
        {
            if(max < temp->getValue())
            {
                max = temp->getValue();
            }
            temp = temp->getPrevious();
        }

        return(max);
    }
}

template <typename T>
bool StackOfAnything<T>::isEmpty()
{
    return(m_size==0);
}

template <typename T>
void StackOfAnything<T>::push(T value)
{
    StackableAnything<T>* temp = m_top;
    m_top = new StackableAnything<T>(value);
    m_top->setPrevious(temp);
    m_size++;
}

template <typename T>
T StackOfAnything<T>::peek() const throw (std::runtime_error)
{
    if(nullptr == m_top)
    {
        throw(std::runtime_error("Peek attempted on empty stack"));
    }
    else
    {
        return(m_top->getValue());
    }
}

template <typename T>
void StackOfAnything<T>::popUntil(T value)
{
    StackableAnything<T>* temp = nullptr;


    while(m_top!= nullptr) {

        if(m_top->getValue() == value) {

            break;
        }

        temp = m_top;
        m_top = m_top->getPrevious();
        delete temp;
        temp = nullptr;

    }
}


template <typename T>
T StackOfAnything<T>::pop()
{
    StackableAnything<T>* tempPtr;
    T temp;

    temp = m_top->getValue();
    tempPtr = m_top->getPrevious();


    delete m_top;
    m_size--;

    m_top = tempPtr;

    return(temp);
}

template <typename T>
int StackOfAnything<T>::size() const
{
    return(m_size);
}
