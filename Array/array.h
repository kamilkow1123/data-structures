class Array{
private:
    int *array;
    int size;

public:
    Array();
    ~Array();
    void addElement(int data);
    void deleteElement(int data);
    void deleteElementByIndex(int index);
    int findIndex(int data);
    int findElement(int index);
    void print();
    int getSize();
    void setSize(int newSize);
    void swapElements(int index1, int index2);
};
