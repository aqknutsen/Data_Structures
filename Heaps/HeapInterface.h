#ifndef HEAPINTERFACE_H_INCLUDED
#define HEAPINTERFACE_H_INCLUDED

template<typename T>

class HeapInterface {

public:

    virtual ~HeapInterface() {};

    virtual bool isEmpty() const = 0;

    virtual int getNumberofNodes() const = 0;

    virtual int getHeight() const = 0;

    virtual T peekTop() const = 0;

    virtual bool add(const T& newData) = 0;

    virtual bool remove() =0;

    virtual void clear() = 0;

    virtual T* heapSort(T newArray[]) = 0;



};



#endif // HEAPINTERFACE_H_INCLUDED
