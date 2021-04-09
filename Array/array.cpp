#include <iostream>
#include "array.h"

using namespace std;

Array::Array() {
    this->array = new int[0];
    this->size = 0;
}

Array::~Array() = default;

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
    if(index<0 || index>size) return;

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
//     ar.pushBack(1);
//     ar.pushBack(2);
//     ar.pushBack(3);
//     ar.pushBack(4);
//     ar.pushFront(5);
//     ar.pushFront(6);
//     ar.pushFront(7);
//     ar.pushOnIndex(10, 6);

//     ar.print();

//     // ar.deleteElement(4);

//     // ar.print();
//     // cout<<ar.findElement(4)<<endl;
//     // cout<<ar.findIndex(6);

//     return 0;
// }
