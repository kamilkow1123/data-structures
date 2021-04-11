#include<iostream>
#include<conio.h>
#include "../Array/arrayFillUp.cpp"
#include "../DoubleLinkedList/listFillUp.cpp"
#include "../Heap/heapFillUp.cpp"
#include "../RBTree/treeFillUp.cpp"
// #include "../Array/array.h"
// #include "../DoubleLinkedList/doubleLinkedList.h"
// #include "../Heap/heap.h"
// #include "../RBTree/redBlackTree.h"

using namespace std;

//Structures declaration
Array arr = Array();
DoubleLinkedList list = DoubleLinkedList();
Heap heap = Heap();
RBTree tree = RBTree();

int insertData(string text)
{
    int data;
    cout << "Enter "<<text<<": ";
    try
    {
        cin >> data;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return data;
}

void arrayTestMenu(){
    do{
        system("cls");
        cout<<"___________TESTING ARRAY___________"<<endl;
        cout<<"[1] Add element at the beginning"<<endl;
        cout<<"[2] Add element at the end"<<endl;
        cout<<"[3] Add element at the given index"<<endl;
        cout<<"[4] Delete element from the beginning"<<endl;
        cout<<"[5] Delete element from the end"<<endl;
        cout<<"[6] Delete element from the given index"<<endl;
        cout<<"[7] Fill array with random data"<<endl;
        cout<<"[8] Fill array with the data from file"<<endl;
        cout<<"[9] Find element in array"<<endl;
        cout<<"[10] Print array"<<endl;
        cout<<"[11] Delete array"<<endl;
        cout<<"[12] Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice, index;
        cin>>choice;
        
        switch(choice){
            case 1: 
                arr.pushFront(insertData("data"));
                break;
            case 2: 
                arr.pushBack(insertData("data"));
                break;
            case 3: 
                arr.pushOnIndex(insertData("data"), insertData("index"));
                break;
            case 4: 
                arr.popFront();
                break;
            case 5: 
                arr.popBack();
                break;
            case 6: 
                arr.deleteElementByIndex(insertData("index"));
                break;
            case 7: 
                fillArrayRandomly(&arr);
                break;
            case 8: 
                fillArrayFromFile(&arr);
                break;
            case 9: 
                index = arr.findIndex(insertData("data to find"));
                if(index != -1) cout<<"Found element at index "<<index<<endl;
                else cout<<"Inserted data is not in the array"<<endl;
                break;
            case 10: 
                arr.print();
                break;
            case 11: 
                deleteArray(&arr);
                break;
            case 12:
                return;
                break;
            default:
                cout<<endl<<"Wrong choice"<<endl;
                break;
        }
        cout<<"Press any key to continue ";
        getch();
    }while(true);
    
}

void listTestMenu(){
    do{
        system("cls");
        cout<<"___________TESTING LIST___________"<<endl;
        cout<<"[1] Add node at the beginning"<<endl;
        cout<<"[2] Add node at the end"<<endl;
        cout<<"[3] Add node after the given node"<<endl;
        cout<<"[4] Delete node from the beginning"<<endl;
        cout<<"[5] Delete node from the end"<<endl;
        cout<<"[6] Delete node with given data"<<endl;
        cout<<"[7] Fill list with random data"<<endl;
        cout<<"[8] Fill list with the data from file"<<endl;
        cout<<"[9] Find node in list"<<endl;
        cout<<"[10] Print list"<<endl;
        cout<<"[11] Delete list"<<endl;
        cout<<"[12] Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        
        switch(choice){
            case 1: 
                list.push_front(insertData("data"));
                break;
            case 2: 
                list.push_back(insertData("data"));
                break;
            case 3: 
                list.push_after(list.findNode(insertData("data of the previous node")), insertData("data to insert"));
                break;
            case 4: 
                list.pop_front();
                break;
            case 5: 
                list.pop_back();
                break;
            case 6: 
                list.pop_node(list.findNode(insertData("data of the node to be deleted")));
                break;
            case 7: 
                fillListRandomly(&list);
                break;
            case 8: 
                fillListFromFile(&list);
                break;
            case 9: 
                if(list.findNode(insertData("data to find")) != nullptr) cout<<"Found the node"<<endl;
                else cout<<"There is no node with that data"<<endl;
                break;
            case 10: 
                list.printList();
                break;
            case 11: 
                deleteList(&list);
                break;
            case 12:
                return;
                break;
            default:
                cout<<endl<<"Wrong choice"<<endl;
                break;
        }
        cout<<"Press any key to continue ";
        getch();
    }while(true);
}

void heapTestMenu(){
    do{
        system("cls");
        cout<<"___________TESTING HEAP___________"<<endl;
        cout<<"[1] Add node to the heap"<<endl;
        cout<<"[2] Delete root"<<endl;
        cout<<"[3] Delete node with given data"<<endl;
        cout<<"[4] Fill heap with random data"<<endl;
        cout<<"[5] Fill heap with the data from file"<<endl;
        cout<<"[6] Find node in heap"<<endl;
        cout<<"[7] Print heap"<<endl;
        cout<<"[8] Delete heap"<<endl;
        cout<<"[9] Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        
        switch(choice){
            case 1: 
                heap.insert(insertData("data"));
                break;
            case 2: 
                heap.extractMax();
                break;
            case 3: 
                heap.deleteElement(insertData("data of the node to be deleted"));
                break;
            case 4: 
                fillHeapRandomly(&heap);
                break;
            case 5: 
                fillHeapFromFile(&heap);
                break;
            case 6: 
                if(heap.findElement(insertData("data to find"))) cout<<"Found the node"<<endl;
                else cout<<"There is no node with that data"<<endl;
                break;
            case 7: 
                heap.printHeap();
                break;
            case 8: 
                deleteHeap(&heap);
                break;
            case 9:
                return;
                break;
            default:
                cout<<endl<<"Wrong choice"<<endl;
                break;
        }
        cout<<"Press any key to continue ";
        getch();
    }while(true);
}

void treeTestMenu(){
    do{
        system("cls");
        cout<<"_________TESTING RED BLACK TREE_________"<<endl;
        cout<<"[1] Add node to the tree"<<endl;
        cout<<"[2] Delete node with given data"<<endl;
        cout<<"[3] Fill tree with random data"<<endl;
        cout<<"[4] Fill tree with the data from file"<<endl;
        cout<<"[5] Find node in tree"<<endl;
        cout<<"[6] Print tree"<<endl;
        cout<<"[7] Print tree in order"<<endl;
        cout<<"[8] Delete tree"<<endl;
        cout<<"[9] Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        
        switch(choice){
            case 1: 
                tree.insertElement(insertData("data"));
                break;
            case 2: 
                tree.deleteByData(insertData("data of the node to be deleted"));
                break;
            case 3: 
                fillTreeRandomly(&tree);
                break;
            case 4: 
                fillTreeFromFile(&tree);
                break;
            case 5: 
                if(tree.search(insertData("data to find")) != nullptr) cout<<"Found the node"<<endl;
                else cout<<"There is no node with that data"<<endl;
                break;
            case 6: 
                tree.print();
                break;
            case 7: 
                tree.printInorder();
                break;
            case 8: 
                deleteTree(&tree);
                break;
            case 9:
                return;
                break;
            default:
                cout<<endl<<"Wrong choice"<<endl;
                break;
        }
        cout<<"Press any key to continue ";
        getch();
    }while(true);
}

void testMenu(){
    system("cls");
    cout<<"___________TESTING___________"<<endl;
    cout<<"[1] Array"<<endl;
    cout<<"[2] Linked List"<<endl;
    cout<<"[3] Heap"<<endl;
    cout<<"[4] Red-black tree"<<endl;
    cout<<"[5] Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;

    switch(choice){
        case 1: 
            arrayTestMenu();
            break;
        case 2: 
            listTestMenu();
            break;
        case 3: 
            heapTestMenu();
            break;
        case 4: 
            treeTestMenu();
            break;
        case 5:
            return;
            break;
        default:
            cout<<endl<<"Wrong choice"<<endl;
            break;
    }
}

void experimentMenu(){
    system("cls");
    cout<<"___________EXPERIMENT___________"<<endl;
    cout<<"[1] Array"<<endl;
    cout<<"[2] Linked List"<<endl;
    cout<<"[3] Heap"<<endl;
    cout<<"[4] Red-black tree"<<endl;
    cout<<"[5] Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;

    switch(choice){
        case 1: 
            arrayExperiment(&arr);
            break;
        case 2: 
            listExperiment(&list);
            break;
        case 3: 
            heapExperiment(&heap);
            break;
        case 4: 
            // treeExperimentMenu(&tree);//TODO in fillUp
            break;
        case 5:
            return;
            break;
        default:
            cout<<endl<<"Wrong choice"<<endl;
            break;
    }
}

void startingMenu(){
    cout<<"___________MENU___________"<<endl;
    cout<<"[1] Test the structure"<<endl;
    cout<<"[2] Run the experiment"<<endl;
    cout<<"[3] Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;

    switch(choice){
        case 1: 
            testMenu();
            break;
        case 2: 
            experimentMenu();
            break;
        case 3: 
            break;
        default:
            cout<<endl<<"Wrong choice"<<endl;
            break;
    }
}