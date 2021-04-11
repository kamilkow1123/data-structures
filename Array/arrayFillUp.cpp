#include<iostream>
#include<fstream>
#include "../Timer/timer.cpp"
#include "array.cpp"
using namespace std;

const int numberRange = 30000;
const int numberOfMeasurements = 100;

void fillArrayRandomly(Array *array){
    if(array->getSize() != 0){
        cout<<"There is data in array"<<endl;
        return;
    }

    int size, data;
    do{
        cout<<"How many numbers do you want to add?"<<endl;
        cin>>size;
    }while(size<=0 || size>300000);

    for(int i = 0; i<size; i++){
        data = rand()%500;
        array->pushBack(data);
    }
}

void fillArrayFromFile(Array *array){
    if(array->getSize() != 0){
        cout<<"There is data in array"<<endl;
        return;
    }

    fstream in;
    in.open("../data.txt", ios::in);
    if(!in.good()) in.open("data.txt", ios::in);

    if(in.good()){
        int size, data;
        in>>size;
        while(!in.eof()){
            in>>data;
            array->pushBack(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteArray(Array *array){
    Array newArray = Array();
    *array = newArray;
}

void fillArray(Array *array, int size){
    if(array->getSize() != 0) deleteArray(array);

    int data;

    for(int i = 0; i<size; i++){
        data = rand()%numberRange;
        array->pushBack(data);
    }
}

void arrayExperiment(Array *array){
    srand(time(NULL));
    float time;
    int size, data;

    do{
        cout<<"Enter the size of the list: ";
        cin>>size;
    }while(size<0 || size>300000);
    

    //Insert at the beginning
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        data = rand()%numberRange;
        Timer timer;
        array->pushFront(data);
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Inserting element at the beginning of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Insert at the end
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        data = rand()%numberRange;
        Timer timer;
        array->pushBack(data);
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Inserting element at the end of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Insert at random position
    int index;
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        data = rand()%numberRange;
        index = rand()%(size-1);
        Timer timer;
        array->pushOnIndex(data, index);
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Inserting element at the random index of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Delete from the beginning
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        Timer timer;
        array->popFront();
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Deleting element from the beginning of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Delete from the end
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        Timer timer;
        array->popBack();
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Deleting element from the end of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Delete from random position
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        index = rand()%(size-1);
        Timer timer;
        array->deleteElementByIndex(index);
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Deleting element from the random index of the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    //Finding element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillArray(array, size);
        data = rand()%numberRange;
        Timer timer;
        array->findIndex(data);
        time += timer.getTime().count() * 1000.0f;
    }
    cout<<"Finding element in the array took on average: "<<time/numberOfMeasurements<<"ms"<<endl;

    deleteArray(array);
}