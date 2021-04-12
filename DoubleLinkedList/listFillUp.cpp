#include<iostream>
#include<fstream>
#include "doubleLinkedList.cpp"
using namespace std;

void fillListRandomly(DoubleLinkedList **list){
    if(!(*list)->isEmpty()){
        cout<<"There is data in list"<<endl;
        return;
    }

    int size, data;
    do{
        cout<<"How many numbers do you want to add?"<<endl;
        cin>>size;
    }while(size<=0 || size>50000);

    for(int i = 0; i<size; i++){
        data = rand()%500;
        (*list)->push_back(data);
    }
}

void fillListFromFile(DoubleLinkedList **list){
    if(!(*list)->isEmpty()){
        cout<<"There is data in list"<<endl;
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
            (*list)->push_back(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteList(DoubleLinkedList **list){
    delete *list;
    *list = new DoubleLinkedList();
}

void fillList(DoubleLinkedList **list, int size, int numberRange){
    if(!(*list)->isEmpty()) deleteList(list);

    int data;

    for(int i = 0; i<size; i++){
        data = rand()%numberRange;
        (*list)->push_back(data);
    }
}

void listExperiment(DoubleLinkedList **list){
    srand(time(NULL));
    float time;
    int size, numberOfMeasurements, numberRange, data;

    do{
        cout<<"Enter the size of the list: ";
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
    

    //Insert at the beginning
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*list)->push_front(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Inserting element at the beginning of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Insert at the end
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*list)->push_back(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Inserting element at the end of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Insert at random position
    int position;
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        data = rand()%numberRange;
        position = rand()%(size-1);
        Timer timer;
        (*list)->push_on_position(data, position);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Inserting element at the random position of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete from the beginning
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        Timer timer;
        (*list)->pop_front();
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting element from the beginning of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete from the end
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        Timer timer;
        (*list)->pop_back();
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting element from the end of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete from random position
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        position = rand()%(size-1);
        Timer timer;
        (*list)->pop_on_position(position);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting element from the random position of the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Finding element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillList(list, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*list)->findNode(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Finding element in the list took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    deleteList(list);
}