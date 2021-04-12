#include<iostream>
#include<fstream>
#include "heap.cpp"
using namespace std;

void fillHeapRandomly(Heap **heap){
    if((*heap)->getSize() != 0){
        cout<<"There is data in heap"<<endl;
        return;
    }

    int size, data;
    do{
        cout<<"How many numbers do you want to add?"<<endl;
        cin>>size;
    }while(size<=0 || size>50000);

    for(int i = 0; i<size; i++){
        data = rand()%500;
        (*heap)->insert(data);
    }
}

void fillHeapFromFile(Heap **heap){
    if((*heap)->getSize() != 0){
        cout<<"There is data in heap"<<endl;
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
            (*heap)->insert(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteHeap(Heap **heap){
    delete *heap;
    *heap = new Heap();
}

void fillHeap(Heap **heap, int size, int numberRange){
    if((*heap)->getSize() != 0) deleteHeap(heap);

    int data;

    for(int i = 0; i<size; i++){
        data = rand()%numberRange;
        (*heap)->insert(data);
    }
}

void heapExperiment(Heap **heap){
    srand(time(NULL));
    float time;
    int size, numberOfMeasurements, numberRange, data;

    do{
        cout<<"Enter the size of the heap: ";
        cin>>size;
    }while(size<0 || size>300000);

    do{
        cout<<"Enter the number of measurements: ";
        cin>>numberOfMeasurements;
    }while(numberOfMeasurements<0 || numberOfMeasurements>5000);

    do{
        cout<<"Enter the max value of elements: ";
        cin>>numberRange;
    }while(numberRange<0 || numberRange>300000);
    

    //Insert element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillHeap(heap, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*heap)->insert(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Inserting element into the heap took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete the root
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillHeap(heap, size, numberRange);
        Timer timer;
        (*heap)->extractMax();
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting the root from the heap took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillHeap(heap, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*heap)->deleteElement(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting random element in heap took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Finding element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillHeap(heap, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*heap)->findElement(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Finding element in the heap took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    deleteHeap(heap);
}