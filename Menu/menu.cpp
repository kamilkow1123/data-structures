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
    cout<<"list";
}

void heapTestMenu(){
    cout<<"heap";
}

void treeTestMenu(){
    cout<<"tree";
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
            // arrayExperimentMenu(&array);//TODO in fillUp
            break;
        case 2: 
            // listExperimentMenu(&list);//TODO in fillUp
            break;
        case 3: 
            // heapExperimentMenu(&heap);//TODO in fillUp
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