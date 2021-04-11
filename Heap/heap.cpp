#include<iostream>
#include "heap.h"

using namespace std;

Heap::Heap(){}

int Heap::getSize(){
    return heap.getSize();
}

void Heap::insert(int data){
    heap.pushBack(data); //adding new element at the end of the heap
    int i = heap.getSize() - 1;

    while(i != 0 && heap.findElement(parent(i)) < heap.findElement(i)){ //comparing the element with its parent
        heap.swapElements(i, parent(i)); //swaping the element and its parent if the properties of maxHeap are validated
        i = parent(i);
    }

}

int Heap::extractMax(){
    if(heap.getSize() == 0) return -1; //empty heap
    else if(heap.getSize() == 1){ //only 1 element in the heap
        int root = heap.findElement(0); //store the root
        heap.deleteElementByIndex(0); //delete the root
        return root; //return max element
    }
    else{ //more than 1 element in the heap
        int root = heap.findElement(0); //store the root
        heap.swapElements(0, heap.getSize()-1); //swap root and the last element
        heap.deleteElementByIndex(heap.getSize()-1); //delete the last element
        heapify(0); //restore the heap properties

        return root; //return max element
    }
}

void Heap::deleteElement(int data){
    int i;
    for (i = 0; i < heap.getSize(); i++)
    {
        if (data == heap.findElement(i))
            break;
    }
    
    if(i == heap.getSize()) return;

    heap.swapElements(i, heap.getSize()-1);
    heap.deleteElementByIndex(heap.getSize()-1);
    for (int i = (heap.getSize())/2-1; i >= 0; i--)
    {
        heapify(i);
    }
}

void Heap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    //find the largest element of this segment of three
    if((l < heap.getSize()) && (heap.findElement(l) > heap.findElement(largest))){
        largest = l;
    }
    if((r < heap.getSize()) && (heap.findElement(r) > heap.findElement(largest))){
        largest = r;
    }

    //if l or r is the largest, then heapify again
    if(largest != i){
        heap.swapElements(i, largest);
        heapify(largest);
    }
}

void Heap::findElement(int data){
    for(int i = 0; i < heap.getSize(); i++)
    {
        if(heap.findElement(i) == data)
        {
            cout<<"Found "<<data<<" in the heap"<<endl;
            return;
        }
    }
    cout<<data<<" is not in the heap"<<endl;
}

void Heap::printHeap(){
    if(heap.getSize() == 0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    heap.print();
}

// int main(){
//     Heap heap = Heap();

//     heap.insert(83);
//     heap.insert(77);
//     heap.insert(65);
//     heap.insert(93);
//     heap.insert(92);
//     heap.insert(90);
//     heap.insert(86);

//     heap.printHeap();
//     heap.deleteElement(90);
//     // heap.extractMax();
//     // heap.printHeap();
//     // heap.findElement(866);
//     heap.printHeap();
//     return 0;
// }