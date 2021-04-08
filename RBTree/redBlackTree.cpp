#include<iostream>
#include "redBlackTree.h"
using namespace std;

RBTree::RBTree(){
    root = nullptr;
    //ASCII for printing the tree
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
}

RBTree::~RBTree(){}

RBNode *RBTree::getRoot()
{
    return this->root;
}

// void RBTree::insertElement(int data){
//     RBNode *newNode = new RBNode(data);
//     root = insertNode(root, newNode);
//     rebuildTree(newNode);
// }

// RBNode* RBTree::insertNode(RBNode *root, RBNode *newNode){ //recursively find a place for new node and insert it
//     if(root == nullptr){ 
//         return newNode;
//     }
//     else if(newNode->data <= root->data){
//         RBNode *leftChild = insertNode(root->left, newNode);
//         root->left = leftChild;
//         leftChild->parent = root;
//     }
//     else{
//         RBNode *rightChild = insertNode(root->right, newNode);
//         root->right = rightChild;
//         rightChild->parent = root;
//     }
//     return root;
// }

RBNode* insertBST(RBNode *root, RBNode *newNode){ //recursively find a place for new node and insert it
    if(root == nullptr){ 
        return newNode;
    }
    else if(newNode->data <= root->data){
        RBNode *leftChild = insertBST(root->left, newNode);
        root->left = leftChild;
        leftChild->parent = root;
    }
    else{
        RBNode *rightChild = insertBST(root->right, newNode);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

void RBTree::insertElement(int data){
    RBNode *newNode = new RBNode(data);
    root = insertBST(root, newNode);
    RBNode *uncle = nullptr;

    while((newNode->parent->color == RED)&&(newNode != root)){

        if(newNode->parent == newNode->parent->parent->left){
            uncle = newNode->parent->parent->right;
            if(uncle->color == RED){
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            if(newNode == newNode->parent->right){
                newNode = newNode->parent;
                rotateLeft(newNode);
            }
            newNode->parent->color = BLACK;
            newNode->parent->parent->color = RED;
            rotateRight(newNode->parent->parent);
        }
        else{
            uncle = newNode->parent->parent->left;
            if(uncle->color == RED){
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            if(newNode == newNode->parent->left){
                newNode = newNode->parent;
                rotateRight(newNode);
            }
            newNode->parent->color = BLACK;
            newNode->parent->parent->color = RED;
            rotateLeft(newNode->parent->parent);
        }
    }
    root->color = BLACK;
}

// void RBTree::insertElement(int data){
//     RBNode *newNode = new RBNode(data);
//     root = insertBST(root, newNode);

//     RBNode *parent = nullptr;
//     RBNode *uncle = nullptr;
//     RBNode *grandparent = nullptr;
    
//     while((newNode->parent->color == RED)&&(newNode != root)&&(newNode->color != BLACK)){
//         parent = newNode->parent;
//         grandparent = newNode->parent->parent;

//         if(parent == grandparent->right){
//             uncle = grandparent->left;
//             if((uncle != nullptr) && (uncle->color == RED)){
//                 uncle->color = BLACK;
//                 parent->color = BLACK;
//                 grandparent->color = RED;
//                 newNode = grandparent;
//                 continue;
//             }
//             if(newNode == parent->left){
//                 newNode = parent;
//                 rotateRight(newNode);
//             }
//             parent->color = BLACK;
//             grandparent->color = RED;
//             rotateLeft(grandparent);
//             break;
//         }
//         else{
//             uncle = grandparent->right;
//             if((uncle != nullptr) && (uncle->color == RED)){
//                 uncle->color = BLACK;
//                 parent->color = BLACK;
//                 grandparent->color = RED;
//                 newNode = grandparent;
//                 continue;
//             }
//             if(newNode == parent->right){
//                 newNode = parent;
//                 rotateLeft(newNode);
//             }
//             parent->color = BLACK;
//             grandparent->color = RED;
//             rotateRight(grandparent);
//             break;
//         }
//     }
//     root->color = BLACK;
// }

void RBTree::rotateRight(RBNode *A){
    RBNode* B = A->left;
    RBNode* temp = A->parent;

    if(B)
    {
        A->left = B->right;
        if(A->left) A->left->parent = A;

        B->right = A;
        B->parent = temp;
        A->parent = B;

        if(temp)
        {
            if( temp->left == A ) temp->left = B;
            else temp->right = B;
        }
        else root = B;
    }
}

void RBTree::rotateLeft(RBNode *A)
{
    RBNode* B = A->right;
    RBNode* temp = A->parent;

    if(B)
    {
        A->right = B->left;
        if(A->right) A->right->parent = A;

        B->left = A;
        B->parent = temp;
        A->parent = B;

        if(temp)
        {
            if( temp->left == A ) temp->left = B;
            else temp->right = B;
        }
        else root = B;
    }
}

void RBTree::print(){
    cout<<endl;
    printRB("","",root);
    cout<<endl;
}

void RBTree::printRB(string sp, string sn, RBNode * root){ //PRINTING RBT as a tree
    string s;

    if(root)
    {
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        printRB ( s + cp, cr, root->right );

        s = s.substr ( 0, sp.length( ) - 2 );
        cout << s << sn <<((root->color)?"B":"R")<<":"<< root->data << endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        printRB ( s + cp, cl, root->left );
    }
}

int main(){
    RBTree tree = RBTree();

    tree.insertElement(5);
    
    tree.print();

    return 0;
}