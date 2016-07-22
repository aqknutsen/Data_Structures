
template <typename T>
ArrayMinHeap<T>::ArrayMinHeap() {

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

    return(itemCount==0);
}

template <typename T>
int ArrayMinHeap<T>::getNumberofNodes() const {

    return(itemCount);

}

template <typename T>
int ArrayMinHeap<T>::getHeight() const {

    int count = 0;
    int index =0;
    while(index <= itemCount-1) {


        count++;
        index = (index*2) + 1;

    }

    return(count);

}


template <typename T>
T ArrayMinHeap<T>::peekTop() const throw(std::runtime_error) {


    if(isEmpty()) {
        throw(std::runtime_error("Heap is empty!"));
    }

    else {

        return(items[0]);
    }


}

template <typename T>
bool ArrayMinHeap<T>::add(const T& newData) {


    for(int i=0; i < itemCount;i++) {

        if(items[i]==newData) {

            return(false);
        }


    }

    itemCount++;
    items[itemCount-1] = newData;
    upHeap(itemCount-1);
    return(true);

}

template<typename T>
bool ArrayMinHeap<T>::remove() {

    if(isEmpty()) {

        return(false);
    }

    else {

        items[0]=items[itemCount-1];
        itemCount--;
        if(itemCount> 0) {

                downHeap(0);

        }
    }

    return(true);
}

template <typename T>
void ArrayMinHeap<T>::clear() {

    delete[] items;

}

/**
*Prints in ascendin
*/
template <typename T>
T* ArrayMinHeap<T>::heapSort(T newArray[]) {

    for(int i=0; i < itemCount;i++) {

        newArray[i]=items[i];
    }

    int size = itemCount;

    T temp = newArray[size-1];
    newArray[size-1]=newArray[0];
    newArray[0]=temp;

    size = size-1;

    while(size >1) {



        downHeap(0, newArray, size);

        T value = newArray[0];
        newArray[0]=newArray[size-1];
        newArray[size-1]=value;

        size--;
    }

    return(newArray);



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
void ArrayMinHeap<T>::downHeap(int subTreeRootIndex) {

    if((2*subTreeRootIndex) + 1 <= itemCount-1) { //Check if a leaf

        int LeftChildIndex = 2 * subTreeRootIndex +1;

        int LargerChildIndex = LeftChildIndex;

        int SmallerChildIndex = LeftChildIndex;

        if((2*subTreeRootIndex) + 2 <= itemCount-1) {

            int RightChildIndex = LeftChildIndex + 1;

            if(items[RightChildIndex] < items[LargerChildIndex]) {


                SmallerChildIndex = RightChildIndex;
            }


        }

        if(items[subTreeRootIndex] > items[SmallerChildIndex]) {

            T temp_value = items[subTreeRootIndex];
            items[subTreeRootIndex] = items[SmallerChildIndex];
            items[SmallerChildIndex] = temp_value;

            downHeap(SmallerChildIndex);

        }

    }

    return;



}

template <typename T>
void ArrayMinHeap<T>::downHeap(int subTreeRootIndex, T anArray[], int n) {


    if((2*subTreeRootIndex) + 1 <= n-1) { //Check if a leaf

        int LeftChildIndex = 2 * subTreeRootIndex +1;

        int LargerChildIndex = LeftChildIndex;

        int SmallerChildIndex = LeftChildIndex;

        if((2*subTreeRootIndex) + 2 <= n-1) {

            int RightChildIndex = LeftChildIndex + 1;

            if(anArray[RightChildIndex] < anArray[LargerChildIndex]) {


                SmallerChildIndex = RightChildIndex;
            }


        }

        if(anArray[subTreeRootIndex] > anArray[SmallerChildIndex]) {

            T temp_value = anArray[subTreeRootIndex];
            anArray[subTreeRootIndex] = anArray[SmallerChildIndex];
            anArray[SmallerChildIndex] = temp_value;

            downHeap(SmallerChildIndex, anArray, n);

        }

    }

    return;

}


template <typename T>
void ArrayMinHeap<T>::upHeap(int nodeIndex) {



    if(nodeIndex!=0) {

       int parentIndex=getParentIndex(nodeIndex);
       if(items[parentIndex] > items[nodeIndex]) {

            T temp = items[parentIndex];
            items[parentIndex]=items[nodeIndex];
            items[nodeIndex]=temp;
            upHeap(parentIndex);
       }
    }

    else {

        return;
    }


}


template <typename T>
void ArrayMinHeap<T>::heapCreate() {

    for(int index = itemCount-1; index>=0; index--) {

        downHeap(index);

    }



}
