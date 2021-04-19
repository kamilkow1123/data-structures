#include<iostream>
#include<fstream>
#include "redBlackTree.cpp"
using namespace std;

void fillTreeRandomly(RBTree **tree){
    if(!(*tree)->isEmpty()){
        cout<<"There is data in a tree"<<endl;
        return;
    }

    int size, data;
    do{
        cout<<"How many numbers do you want to add?"<<endl;
        cin>>size;
    }while(size<=0 || size>50000);

    for(int i = 0; i<size; i++){
        data = rand()%500;
        (*tree)->insertElement(data);
    }
}

void fillTreeFromFile(RBTree **tree){
    if(!(*tree)->isEmpty()){
        cout<<"There is data in a tree"<<endl;
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
            (*tree)->insertElement(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteTree(RBTree **tree){
    delete *tree;
    *tree = new RBTree();
}

void fillTree(RBTree **tree, int size, int numberRange){
    if(!(*tree)->isEmpty()) deleteTree(tree);

    int data;

    for(int i = 0; i<size; i++){
        data = rand()%numberRange;
        (*tree)->insertElement(data);
    }
}

void treeExperiment(RBTree **tree){
    srand(time(NULL));
    float time;
    int size, numberOfMeasurements, numberRange, data;

    do{
        cout<<"Enter the size of the tree: ";
        cin>>size;
    }while(size<0 || size>1000000);

    do{
        cout<<"Enter the number of measurements: ";
        cin>>numberOfMeasurements;
    }while(numberOfMeasurements<0 || numberOfMeasurements>10000);

    do{
        cout<<"Enter the max value of elements: ";
        cin>>numberRange;
    }while(numberRange<0 || numberRange>500000);
    

    //Insert element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillTree(tree, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*tree)->insertElement(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Inserting element into the red black tree took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Delete element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillTree(tree, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*tree)->deleteByData(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Deleting random element in red black tree took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    //Finding element
    time = 0;
    for(int i = 0; i<numberOfMeasurements; i++){
        fillTree(tree, size, numberRange);
        data = rand()%numberRange;
        Timer timer;
        (*tree)->search(data);
        time += timer.getTime().count() * 1000000000.0f;
    }
    cout<<"Finding element in the red black tree took on average: "<<time/numberOfMeasurements<<"ns"<<endl;

    deleteTree(tree);
}