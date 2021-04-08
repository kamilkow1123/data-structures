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
    void insertElement(int data);
    RBNode* insertNode(RBNode *root, RBNode *newNode);
    void rotateRight(RBNode *A);
    void rotateLeft(RBNode *A);
    void print();
    void printRB(string sp, string sn, RBNode *root);
    void rebuildTree(RBNode *newNode);
};