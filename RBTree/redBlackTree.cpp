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

void RBTree::insertElement(int data){
    RBNode *newNode = new RBNode(data);
    root = insertNode(root, newNode);
    rebuildTree(newNode);
}

RBNode* RBTree::insertNode(RBNode *root, RBNode *newNode){ //recursively find a place for new node and insert it
    if(root == nullptr){ 
        return newNode;
    }
    else if(newNode->data <= root->data){
        RBNode *leftChild = insertNode(root->left, newNode);
        root->left = leftChild;
        leftChild->parent = root;
    }
    else{
        RBNode *rightChild = insertNode(root->right, newNode);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

void RBTree::rebuildTree(RBNode *newNode){
    //rebuild tree
}

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

    tree.insertElement(9);
    tree.insertElement(8);
    tree.insertElement(11);
    tree.insertElement(4);
    tree.insertElement(7);
    tree.insertElement(1);

    tree.print();
    return 0;
}