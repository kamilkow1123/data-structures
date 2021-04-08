class Array{
private:
    int *array;
    int size;

public:
    Array();
    ~Array();
    void addElement(int data);
    void deleteElement(int data);
    int findElement(int data);
    void print();
};
