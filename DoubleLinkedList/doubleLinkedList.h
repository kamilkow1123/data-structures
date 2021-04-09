struct Node{
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    void print(){
        std::cout<<data<<" ";
    }
};

class DoubleLinkedList{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList();
    void push_back(int data);
    void push_front(int data);
    void push_after(Node *prevNode, int data);
    void pop_back();
    void pop_front();
    void pop_node(Node *nodeToDelete);
    void printList();
    Node *findNode(int data); //find node by its data
    bool isEmpty();
};