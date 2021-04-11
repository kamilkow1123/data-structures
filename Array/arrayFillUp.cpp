#include<iostream>
#include<fstream>
#include "array.cpp"
using namespace std;

void fillArrayRandomly(Array *array){
    if(array->getSize() != 0){
        cout<<"There is data in array"<<endl;
        return;
    }

    int size, data;
    do{
        cout<<"How many numbers do you want to add?"<<endl;
        cin>>size;
    }while(size<=0 || size>50000);

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

// int main(){
//     Array array = Array();

//     fillArrayRandomly(&array);
//     fillArrayFromFile(&array);

//     array.print();
//     deleteArray(&array);
//     return 0;
// }