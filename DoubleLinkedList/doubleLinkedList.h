class DoubleLinkedList{
private:
    int data;
    DoubleLinkedList *prev;
    DoubleLinkedList *next;

public:
    explicit DoubleLinkedList(int data);
    static void push_back(DoubleLinkedList **head, int data);
    static void push_front(DoubleLinkedList **head, int data);
    static void pop_back(DoubleLinkedList **head);
    static void pop_front(DoubleLinkedList **head);
    static void printList(DoubleLinkedList *head);
    static void push_after(DoubleLinkedList **head, DoubleLinkedList *prevNode, int data);
    static DoubleLinkedList *findNode(DoubleLinkedList **head, int pos);
};