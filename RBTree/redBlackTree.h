using namespace std;

enum Color{
    RED,
    BLACK
};

struct RBNode{
    int data;
    Color color;
    RBNode *left;
    RBNode *right;
    RBNode *parent;

    RBNode(int data){
        this->data = data;
        this->color = RED;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class RBTree{
private:
    RBNode *root;
    string cr, cl, cp;

public:
    RBTree();
    ~RBTree();
    RBNode *getRoot();
    void insertElement(int data);
    void rotateRight(RBNode *A);
    void rotateLeft(RBNode *A);
    void deleteNode(RBNode *node);
    void deleteByData(int data);
    RBNode *search(int data);
    void fixDoubleBlack(RBNode *node);
    void print();
    void printRB(string sp, string sn, RBNode *root);
};