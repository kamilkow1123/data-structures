#include<iostream>
#include<fstream>
#include "doubleLinkedList.cpp"
using namespace std;

void fillListRandomly(DoubleLinkedList *list){
    if(!list->isEmpty()){
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
        list->push_back(data);
    }
}

void fillListFromFile(DoubleLinkedList *list){
    if(!list->isEmpty()){
        cout<<"There is data in list"<<endl;
        return;
    }

    fstream in;
    in.open("../data.txt", ios::in);

    if(in.good()){
        int size, data;
        in>>size;
        while(!in.eof()){
            in>>data;
            list->push_back(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteList(DoubleLinkedList *list){
    DoubleLinkedList newList = DoubleLinkedList();
    *list = newList;
}

// int main(){
//     DoubleLinkedList list = DoubleLinkedList();

//     // fillListRandomly(&list);
//     fillListFromFile(&list);
//     list.printList();
//     deleteList(&list);

//     return 0;
// }