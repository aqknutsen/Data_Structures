#ifndef ARRAYMINHEAP_H_INCLUDED
#define ARRAYMINHEAP_H_INCLUDED


#include "HeapInterface.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class ArrayMinHeap: public HeapInterface<T> {


public:

    ArrayMinHeap();

    ArrayMinHeap(const T someArray[], const int arraySize);

    ~ArrayMinHeap();

    bool isEmpty() const;

    int getNumberofNodes() const;

    int getHeight() const;

    T peekTop() const throw(std::runtime_error);

    bool add(const T& newData);

    bool remove();

    void clear();

    T* heapSort(T newArray[]);


private:

    int getLeftChildIndex(int nodeIndex) const;

    int getRightChildIndex(int nodeIndex) const;

    int getParentIndex(int nodeIndex) const;

    void downHeap(int subTreeRootIndex);

    void downHeap(int subTreeRootIndex, T anArray[], int n);

    void upHeap(int nodeIndex);

    void heapCreate();

    static const int ROOT_INDEX=0;

    static const int DEFAULT_CAPACITY=21;

    T* items;

    int itemCount;

    int maxItems;

};

#include "ArrayMinHeap.hpp"


#endif // ARRAYMINHEAP_H_INCLUDED
