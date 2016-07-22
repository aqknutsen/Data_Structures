#include "ArrayMinHeap.h"


template <typename T>
ArrayMinHeap>T>::ArrayMinHeap() {

    T* items=nullptr;;

    int itemCount=0;

    int maxItems=0;

}

template <typename T>
ArrayMinHeap<T>::ArrayMinHeap(const T someArray[], const int arraySize) {

    itemCount =arraySize;
    maxItems = 2*arraySize;

    items = new T[maxItems];
    for (int i=0; i < itemCount; i++) {


        items[i] = someArray[i];
    }

    heapCreate();



}



template <typename T>
ArrayMinHeap<T>::~ArrayMinHeap() {

    clear();
}

template <typename T>
bool ArrayMinHeap<T>::isEmpty() const {

    return(itemsCount==0);
}

template <typename T>
int ArrayMinHeap<T>::getNumberofNodes() const {

    return(itemsCount);

}

template <typename T>
int ArrayMinHeap::getHeight() const {

    int count = 0;
    int index =0;
    while(index <= itemsCount-1) {


        count++;
        index = (index*2) + 1;

    }

    return(count);

}


template <typename T>
T ArrayMinHeap::peekTop() const throw(std::runtime_error) {


    if(isEmpty()) {
        throw(std::runtime_error("Heap is empty!"));
    }

    else {

        return(items[0]);
    }


}

template <typename T>
bool ArrayMinHeap<T>::add(const T& newData) {

    items[itemCount] = newData;

    int newDataIndex = itemCount;

    inPlace=false;

    while((newDataIndex>=0) && !inPlace) {


        parentIndex = (newDataIndex-1)/2;

        if(items[newDataIndex] > items[parentIndex]) {

            inPlace = true;
        }

        else {

            T value = items[parentIndex];
            items[parentIndex]=items[newDataIndex];
            items[newDataIndex] = value;


            newDataIndex=parentIndex
        }
    }

    itemsCount++;

}

template<typename T>
bool ArrayMinHeap<T>::remove() {

    if(isEmpty()) {

        return(false);
    }

    else {

        items[0]=items[itemsCount-1];
        itemsCount--;
        if(itemsCount> 0) {

                heapRebuild(0);

        }
    }


}

template <typename T>
void ArrayMinHeap<T>::clear() {

    delete[] items;

}

template <typename T>
void ArrayMinHeap<T>::heapSort() {

    while(!isEmpty()) {

        if(itemsCount==1) {
            std::cout<<peakTop()<<std::endl;
            remove();

        }
        else {

            std::cout<<peakTop()<< ", ";
            remove();

        }

    }


}

template<typename T>
int ArrayMinHeap<T>::getLeftChildIndex(const int nodeIndex) const {


    return((2*nodeIndex) + 1);

}

template<typename T>
int ArrayMinHeap<T>::getRightChildIndex(const int nodeIndex) const {


    return((2*nodeIndex) + 2);

}


template<typename T>
int ArrayMinHeap<T>::getParentIndex(const int nodeIndex) const {


    return((nodeIndex-1)/2);

}

template <typename T>
void ArrayMinHeap<T>::heapRebuild(int subTreeRootIndex) {

    if(2*subTreeRootIndex) + 1 <= itemsCount-1) { //Check if a leaf

        int LeftChildIndex = 2 * rootIndex +1;

        int SmallerChildIndex = LeftChildIndex;

        if(2*subTreeRootIndex) + 2 <= itemsCount-1) {

            int RightChildIndex = LeftChildIndex + 1;

            if(items[RightChildIndex] < items[LargerChildIndex]) {


                SmallerChildIndex = RightChildIndex;
            }


        }

        if(items[subtreeRootIndex] > items[SmallerChildIndex]) {

            T temp_value = items[subtreeRootIndex];
            items[subtreeRootIndex] = items[SmallerChildIndex];
            items[SmallerChildIndex] = temp_value;

            heapRebuild(SmallerChildIndex);

        }

    }

    return();



}


template <typename T>
void ArrayMinHeap<T>::heapCreate() {

    for(int index = itemCount-1; index>=0; index--) {

        heapRebuild(index);

    }



}
