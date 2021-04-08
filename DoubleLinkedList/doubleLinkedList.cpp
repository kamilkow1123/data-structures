#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

void DoubleLinkedList::push_back(DoubleLinkedList **head, int data) { //adding node at the end
    auto *newNode = new DoubleLinkedList(data);
    DoubleLinkedList *temp = (*head);
    DoubleLinkedList *temp2 = nullptr;

    while (temp != nullptr)
    {
        temp2 = temp;
        temp = temp->next;
    }

    if ((*head) == nullptr)
    {
        (*head) = newNode;
    }
    else
    {
        temp2->next = newNode;
        newNode->prev = temp2;
        newNode->next = nullptr;
    }
}

void DoubleLinkedList::push_front(DoubleLinkedList **head, int data) { //adding node at the beginning
    auto *newNode = new DoubleLinkedList(data);
    newNode->prev = nullptr;
    newNode->next = (*head);
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}

void DoubleLinkedList::pop_back(DoubleLinkedList **head) { //deleting node from the end
    DoubleLinkedList *temp = (*head);

    if ((*head) == nullptr)
    {
        return;
    }

    if ((*head)->next == nullptr)
    {
        *head = nullptr;
        return;
    }

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
}

void DoubleLinkedList::pop_front(DoubleLinkedList **head) { //deleting node from the beginning
    DoubleLinkedList *temp = nullptr;

    if (*head != nullptr)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
        (*head)->prev = nullptr;
    }
}

void DoubleLinkedList::printList(DoubleLinkedList *head) { //print all the nodes
    while (head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void DoubleLinkedList::push_after(DoubleLinkedList **head, DoubleLinkedList *prevNode, int data) { //add node after specific node
    if (prevNode == nullptr)
    {
        push_front(head, data);
        return;
    }

    auto *newNode = new DoubleLinkedList(data);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;

    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
}

DoubleLinkedList *DoubleLinkedList::findNode(DoubleLinkedList **head, int data) { //find the node by its data and return it
    DoubleLinkedList *temp = (*head);

    while(temp != nullptr){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

int main() {
    auto *head = new DoubleLinkedList(5);
    DoubleLinkedList::push_back(&head, 6);
    DoubleLinkedList::push_back(&head, 7);
    DoubleLinkedList::push_back(&head, 8);
    DoubleLinkedList::push_back(&head, 9);
    DoubleLinkedList::push_back(&head, 10);

    DoubleLinkedList::printList(head);

    DoubleLinkedList::pop_back(&head);
    DoubleLinkedList::pop_back(&head);
    DoubleLinkedList::pop_front(&head);

    DoubleLinkedList::printList(head);

    DoubleLinkedList::push_after(&head, DoubleLinkedList::findNode(&head, 7),-3);

    DoubleLinkedList::printList(head);

    return 0;
}
