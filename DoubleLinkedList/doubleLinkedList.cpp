#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
    while(head!=nullptr) pop_front();
}

void DoubleLinkedList::push_back(int data) { //adding node at the end
    Node *newNode = new Node(data);

    if(head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoubleLinkedList::push_front(int data) { //adding node at the beginning
    Node *newNode = new Node(data);

    if(head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoubleLinkedList::push_after(Node *prevNode, int data) { //add node after specific node
    if (prevNode == nullptr)
    {
        push_front(data);
        return;
    }

    Node *newNode = new Node(data);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;

    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
}

void DoubleLinkedList::push_on_position(int data, int position){
    Node *temp = head;
    for(int i = 0; i<position; i++){
        temp = temp->next;
    }
    push_after(temp, data);
}

void DoubleLinkedList::pop_node(Node *nodeToDelete){
    if(nodeToDelete == nullptr) return;
    if(nodeToDelete->prev) nodeToDelete->prev->next = nodeToDelete->next;
    else head = nodeToDelete->next;

    if(nodeToDelete->next) nodeToDelete->next->prev = nodeToDelete->prev;
    else tail = nodeToDelete->prev;

    free(nodeToDelete);
}

void DoubleLinkedList::pop_on_position(int position){
    Node *temp = head;
    for(int i = 0; i<position; i++){
        temp = temp->next;
    }
    pop_node(temp);
}

void DoubleLinkedList::pop_back() { //deleting node from the end
    if(tail == nullptr) return;
    pop_node(tail);
    // if(tail == nullptr) return;
    // Node *temp = tail;
    // tail->prev->next = nullptr;
    // tail = tail->prev;
    // free(temp);
}

void DoubleLinkedList::pop_front() { //deleting node from the beginning
    if(head == nullptr) return;
    pop_node(head);
    // if(head == nullptr) return;
    // Node *temp = head;
    // head->next->prev = nullptr;
    // head = head->next;
    // free(temp);
}

void DoubleLinkedList::printList() { //print all the nodes
    Node *temp = head;
    if(temp == nullptr) {cout<<"List is empty"<<endl; return;}
    while (temp != nullptr)
    {
        temp->print();
        temp = temp->next;
    }
    cout<<endl;
}

Node *DoubleLinkedList::findNode(int data) { //find the node by its data and return it
    Node *temp = head;

    while(temp != nullptr){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool DoubleLinkedList::isEmpty(){
    return head == nullptr;
}

// int main() {
//     DoubleLinkedList list = DoubleLinkedList();

//     list.push_back(5);
//     list.push_back(8);
//     list.push_back(4);
//     list.push_front(2);
//     list.push_front(3);
//     list.push_front(1);
//     list.push_after(list.findNode(44),17);

//     list.printList();
//     // list.pop_node(list.findNode(17));
//     // list.pop_node(list.findNode(45));
//     list.pop_back();
//     list.pop_front();
//     list.pop_front();
//     list.pop_front();
//     list.pop_back();
//     list.pop_back();
//     list.pop_back();

//     list.printList();
//     return 0;
// }
