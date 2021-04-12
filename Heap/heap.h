#include "../Array/array.h"

#ifndef _HEAP_H_
#define _HEAP_H_

class Heap
{
private:
    Array *heap = new Array(); // array to store elements

    int parent(int i) { return (i-1)/2; }; //returns the parent index
    int left(int i) { return 2*i+1; }; //returns the left child index
    int right(int i) { return 2*i+2; }; //returns the right child index

public:
    Heap(); //constructor
    ~Heap(); //destructor
    void insert(int data); //insert key into the heap
    int extractMax(); //delete the max element - root
    void deleteElement(int data); //delete element by data
    void heapify(int i); //recursively heapify (restore the properties of heap) a sub-tree
    void printHeap(); //print the heap
    bool findElement(int data); //find element in the heap
    int getSize();
};

#endif