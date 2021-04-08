#include <iostream>
#include "array.h"

using namespace std;

Array::Array() {
    this->array = new int[0];
    this->size = 0;
}

Array::~Array() = default;

void Array::addElement(int data) {
    size++;
    array = (int*)realloc(array, size*sizeof(int));
    array[size-1] = data;
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

void Array::deleteElement(int data) {
    int index = findIndex(data);

    if(index == -1) return;

    for(int i = index; i<size; i++){
        array[i] = array[i+1];
    }
    size--;
    array = (int*)realloc(array, size*sizeof(int));
}

void Array::deleteElementByIndex(int index) {
    if(index<0 || index>=size) return;

    for(int i = index; i<size; i++){
        array[i] = array[i+1];
    }
    size--;
    array = (int*)realloc(array, size*sizeof(int));
}

void Array::print() {
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

// int main() {
//     Array ar = Array();
//     ar.addElement(1);
//     ar.addElement(2);
//     ar.addElement(3);
//     ar.addElement(4);
//     ar.addElement(5);
//     ar.addElement(6);

//     ar.print();

//     ar.deleteElement(4);

//     ar.print();
//     cout<<ar.findElement(4)<<endl;
//     cout<<ar.findIndex(6);

//     return 0;
// }
