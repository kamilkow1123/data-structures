#include "../Array/array.cpp"

class Heap
{
private:
    Array heap = Array(); // array to store elements

    int parent(int i) { return (i-1)/2; }; //returns the parent index
    int left(int i) { return 2*i+1; }; //returns the left child index
    int right(int i) { return 2*i+2; }; //returns the right child index

public:
    Heap(); //constructor
    void insert(int data); //insert key into the heap
    int extractMax(); //delete the max element - root
    void heapify(int i); //recursively heapify (restore the properties of heap) a sub-tree
    void printHeap(); //print the heap
    void findNode(); //
};