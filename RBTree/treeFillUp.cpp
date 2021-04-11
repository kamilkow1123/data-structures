#include<iostream>
#include<fstream>
#include "redBlackTree.cpp"
using namespace std;

void fillTreeRandomly(RBTree *tree){
    if(!tree->isEmpty()){
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
        tree->insertElement(data);
    }
}

void fillTreeFromFile(RBTree *tree){
    if(!tree->isEmpty()){
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
            tree->insertElement(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteTree(RBTree *tree){
    // tree->deleteTree(tree->getRoot());
    RBTree newTree = RBTree();
    *tree = newTree;
}

// int main(){
//     RBTree tree = RBTree();

//     fillTreeRandomly(&tree);
//     // fillTreeFromFile(&tree);

//     tree.printInorder();
//     deleteTree(&tree);

//     return 0;
// }