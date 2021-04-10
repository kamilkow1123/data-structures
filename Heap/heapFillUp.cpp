#include<fstream>
#include "heap.cpp"

void fillHeapRandomly(Heap *heap){
    if(heap->getSize() != 0){
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
        heap->insert(data);
    }
}

void fillHeapFromFile(Heap *heap){
    if(heap->getSize() != 0){
        cout<<"There is data in heap"<<endl;
        return;
    }

    fstream in;
    in.open("../data.txt", ios::in);

    if(in.good()){
        int size, data;
        in>>size;
        while(!in.eof()){
            in>>data;
            heap->insert(data);
        }
        in.close();
    }
    else
        cout<<"Cannot open data.txt"<<endl;
}

void deleteHeap(Heap *heap){
    Heap newHeap = Heap();
    *heap = newHeap;
}

// int main(){
//     Heap heap = Heap();

//     // fillHeapRandomly(&heap);
//     fillHeapFromFile(&heap);
//     heap.printHeap();
//     deleteHeap(&heap);

//     return 0;
// }