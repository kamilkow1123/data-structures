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

int Array::findElement(int data) {
    int index = -1;

    for(int i = 0; i<size; i++){
        if(array[i] == data){
            index = i;
        }
    }
    return index;
}

void Array::deleteElement(int data) {
    int index = findElement(data);

    if(index == -1) return;

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

int main() {
    Array ar = Array();
    ar.addElement(1);
    ar.addElement(2);
    ar.addElement(3);
    ar.addElement(4);
    ar.addElement(5);
    ar.addElement(6);

    ar.print();

    ar.deleteElement(4);

    ar.print();
    cout<<ar.findElement(3);

    return 0;
}
