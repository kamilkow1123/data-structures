#include <iostream>
#include "array.h"

using namespace std;

Array::Array() {
    this->array = new int[0];
    this->size = 0;
}

Array::~Array(){
    delete [] array;
};

void Array::pushBack(int data) {
    size++;
    array = (int*)realloc(array, size*sizeof(int));
    array[size-1] = data;
}

void Array::pushFront(int data) {
    size++;
    array = (int*)realloc(array, size*sizeof(int));
    for(int i = size; i>0; i--){
        array[i] = array[i-1];
    }
    array[0] = data;
}

void Array::pushOnIndex(int data, int index) {
    if(index<0 || index>size){
        pushBack(data);
        return;
    } 

    size++;
    array = (int*)realloc(array, size*sizeof(int));
    int i;
    for(i = size; i>index; i--){
        array[i] = array[i-1];
    }
    array[i] = data;
}

int Array::findIndex(int data) {
    int index = -1;

    for(int i = 0; i<size; i++){
        if(array[i] == data){
            index = i;
        }
    }
    return index;
}

int Array::findElement(int index) {
    return array[index];
}

void Array::deleteElementByIndex(int index) {
    if(index<0 || index>=size) return;

    for(int i = index; i<size; i++){
        array[i] = array[i+1];
    }
    size--;
    array = (int*)realloc(array, size*sizeof(int));
}

void Array::deleteElement(int data) {
    int index = findIndex(data);
    deleteElementByIndex(index);
}

void Array::popBack(){
    deleteElementByIndex(size - 1);
}

void Array::popFront(){
    deleteElementByIndex(0);
}

void Array::print() {
    if(size == 0){
        cout<<"Array is empty"<<endl;
        return;
    }
    for(int i = 0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int Array::getSize(){
    return size;
}

void Array::setSize(int newSize){
    size = newSize;
}

void Array::swapElements(int index1, int index2){
    swap(array[index1], array[index2]);
}
