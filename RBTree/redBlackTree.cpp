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

bool RBTree::isEmpty(){
    return root == nullptr;
}

void RBTree::deleteTree(RBNode *root){
     if (root != nullptr)
    {
        deleteTree(root->right);
        deleteTree(root->left);
        delete root;
    }
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
    
    RBNode *parent = nullptr;
    RBNode *uncle = nullptr;
    RBNode *grandparent = nullptr;

    while((newNode != root)&&(newNode->color != BLACK)&&(newNode->parent->color == RED)){
        parent = newNode->parent;
        grandparent = newNode->parent->parent;

        if(parent == grandparent->left){
            uncle = grandparent->right;
            if(uncle != nullptr && uncle->color == RED){
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            }
            else{
                if(newNode == parent->right){
                    rotateLeft(parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateRight(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                newNode = parent;
            }
        }
        else{ //mirror cases
            uncle = grandparent->left;
            if(uncle != nullptr && uncle->color == RED){
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            }
            else {
                 if(newNode == parent->left){
                    rotateRight(parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateLeft(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                newNode = parent;
            }
        }
    }
    root->color = BLACK;
}

// find the successor of the given node
RBNode *successor(RBNode *node) {
    RBNode *temp = node;
 
    while (temp->left != nullptr)
      temp = temp->left;
 
    return temp;
}

//swap data in two given nodes
void swapData(RBNode *node1, RBNode *node2) {
    int temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// check if given node is a left child
bool isOnLeft(RBNode *node) { 
    return node == node->parent->left; 
}

// returns pointer to sibling
RBNode *getSibling(RBNode *node) {
    // sibling null if no parent
    if (node->parent == NULL)
      return NULL;
 
    if (isOnLeft(node))
      return node->parent->right;
 
    return node->parent->left;
}

bool hasRedChild(RBNode *node) {
    return (node->left != NULL && node->left->color == RED) ||
           (node->right != NULL && node->right->color == RED);
}

// find node that replaces a deleted node in BST
RBNode *BSTreplace(RBNode *node) {
    // when node has 2 children
    if (node->left != NULL && node->right != NULL)
      return successor(node->right);
 
    // when node is a leaf
    if (node->left == NULL && node->right == NULL)
      return NULL;
 
    // when node has a single child
    if (node->left != NULL)
      return node->left;
    else
      return node->right;
}

// deletes the given node
void RBTree::deleteNode(RBNode *node) {
    RBNode *temp = BSTreplace(node);
 
    // True when node and temp are both black
    bool bothBlack = ((temp == nullptr || temp->color == BLACK) && (node->color == BLACK));
    RBNode *parent = node->parent;
 
    if (temp == nullptr) {
      // temp is nullptr so node is leaf
      if (node == root) {
        // node is root, making root null
        root = NULL;
      } 
      else {
        if (bothBlack) {
          // node is a leaf, fix double black at node
          fixDoubleBlack(node);
        } else {
          // temp or node is red
          if (getSibling(node) != nullptr)
            // sibling is not null, make it red
            getSibling(node)->color = RED;
        }
 
        // delete node from the tree
        if (isOnLeft(node)) {
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      }
      delete node;
      return;
    }
 
    if (node->left == NULL || node->right == NULL) {
      // node has 1 child
      if (node == root) {
        // node is root, assign the value of temp to node, and delete temp
        node->data = temp->data;
        node->left = node->right = NULL;
        delete temp;
      } else {
        // Detach node from tree and move temp up
        if (isOnLeft(node)) {
          parent->left = temp;
        } else {
          parent->right = temp;
        }
        delete node;
        temp->parent = parent;
        if (bothBlack) {
          // temp and node both black, fix double black at temp
          fixDoubleBlack(temp);
        } else {
          // temp or node red, color temp black
          temp->color = BLACK;
        }
      }
      return;
    }
    // node has 2 children, swap values with successor and recurse
    swapData(temp, node);
    deleteNode(temp);
}
 
void RBTree::fixDoubleBlack(RBNode *node) {
    if (node == root) //Reached root
      return;
 
    RBNode *sibling = getSibling(node);
    RBNode *parent = node->parent;
    if (sibling == NULL) {
      // No sibiling, double black pushed up
      fixDoubleBlack(parent);
    } else {
      if (sibling->color == RED) {
        // Sibling red
        parent->color = RED;
        sibling->color = BLACK;
        if (isOnLeft(sibling)) {
          // left case
          rotateRight(parent);
        } else {
          // right case
          rotateLeft(parent);
        }
        fixDoubleBlack(node);
      } else {
        // Sibling black
        if (hasRedChild(sibling)) {
          // at least 1 red children
          if (sibling->left != NULL && sibling->left->color == RED) {
            if (isOnLeft(sibling)) {
              // left left
              sibling->left->color = sibling->color;
              sibling->color = parent->color;
              rotateRight(parent);
            } else {
              // right left
              sibling->left->color = parent->color;
              rotateRight(sibling);
              rotateLeft(parent);
            }
          } else {
            if (isOnLeft(sibling)) {
              // left right
              sibling->right->color = parent->color;
              rotateLeft(sibling);
              rotateRight(parent);
            } else {
              // right right
              sibling->right->color = sibling->color;
              sibling->color = parent->color;
              rotateLeft(parent);
            }
          }
          parent->color = BLACK;
        } else {
          // 2 black children
          sibling->color = RED;
          if (parent->color == BLACK)
            fixDoubleBlack(parent);
          else
            parent->color = BLACK;
        }
      }
    }
}

RBNode *RBTree::search(int data) {
    RBNode *temp = root;
    while (temp != NULL) {
      if (data < temp->data) {
        if (temp->left == NULL)
          break;
        else
          temp = temp->left;
      } else if (data == temp->data) {
        break;
      } else {
        if (temp->right == NULL)
          break;
        else
          temp = temp->right;
      }
    }
    return temp;  
}

//delete the node with given data
void RBTree::deleteByData(int data) {
    if (root == NULL) //tree is empty
        return;
 
    RBNode *node = search(data);
 
    if (node->data != data) {
        cout << "There is no node with data: " << data << endl;
        return;
    }

    deleteNode(node);
}

void inorderHelper(RBNode *root){
    if (root == nullptr)
        return;

    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

void RBTree::printInorder(){
    inorderHelper(root);
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

// int main(){
//     RBTree tree = RBTree();

//     tree.insertElement(11);
//     tree.insertElement(2);
//     tree.insertElement(14);
//     tree.insertElement(1);
//     tree.insertElement(15);
//     // tree.insertElement(7);
//     // tree.insertElement(5);
//     // tree.insertElement(8);
//     // tree.insertElement(4);
//     tree.print();
//     tree.deleteByData(15);
//     tree.deleteByData(14);
//     tree.print();

//     return 0;
// }