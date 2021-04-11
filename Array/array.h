#ifndef _ARRAY_H_
#define _ARRAY_H_
 
class Array{
private:
    int *array;
    int size;

public:
    Array();
    ~Array();
    void pushBack(int data);
    void pushFront(int data);
    void pushOnIndex(int data, int index);
    void deleteElement(int data);
    void deleteElementByIndex(int index);
    void popBack();
    void popFront();
    int findIndex(int data);
    int findElement(int index);
    void print();
    int getSize();
    void setSize(int newSize);
    void swapElements(int index1, int index2);
};

#endif