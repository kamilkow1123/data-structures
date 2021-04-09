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

// find node that do not have a left child
  // in the subtree of the given node
RBNode *successor(RBNode *x) {
    RBNode *temp = x;
 
    while (temp->left != NULL)
      temp = temp->left;
 
    return temp;
}

void swapValues(RBNode *u, RBNode *v) {
    int temp;
    temp = u->data;
    u->data = v->data;
    v->data = temp;
}

// check if node is left child of parent
bool isOnLeft(RBNode *node) { return node == node->parent->left; }

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
RBNode *BSTreplace(RBNode *x) {
    // when node have 2 children
    if (x->left != NULL && x->right != NULL)
      return successor(x->right);
 
    // when leaf
    if (x->left == NULL && x->right == NULL)
      return NULL;
 
    // when single child
    if (x->left != NULL)
      return x->left;
    else
      return x->right;
}

// deletes the given node
void RBTree::deleteNode(RBNode *v) {
    RBNode *u = BSTreplace(v);
 
    // True when u and v are both black
    bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
    RBNode *parent = v->parent;
 
    if (u == NULL) {
      // u is NULL therefore v is leaf
      if (v == root) {
        // v is root, making root null
        root = NULL;
      } else {
        if (uvBlack) {
          // u and v both black
          // v is leaf, fix double black at v
          fixDoubleBlack(v);
        } else {
          // u or v is red
          if (getSibling(v) != NULL)
            // sibling is not null, make it red"
            getSibling(v)->color = RED;
        }
 
        // delete v from the tree
        if (isOnLeft(v)) {
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      }
      delete v;
      return;
    }
 
    if (v->left == NULL || v->right == NULL) {
      // v has 1 child
      if (v == root) {
        // v is root, assign the value of u to v, and delete u
        v->data = u->data;
        v->left = v->right = NULL;
        delete u;
      } else {
        // Detach v from tree and move u up
        if (isOnLeft(v)) {
          parent->left = u;
        } else {
          parent->right = u;
        }
        delete v;
        u->parent = parent;
        if (uvBlack) {
          // u and v both black, fix double black at u
          fixDoubleBlack(u);
        } else {
          // u or v red, color u black
          u->color = BLACK;
        }
      }
      return;
    }
 
    // v has 2 children, swap values with successor and recurse
    swapValues(u, v);
    deleteNode(u);
}
 
void RBTree::fixDoubleBlack(RBNode *x) {
    if (x == root)
      // Reached root
      return;
 
    RBNode *sibling = getSibling(x);
    RBNode *parent = x->parent;
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
        fixDoubleBlack(x);
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

// utility function that deletes the node with given value
void RBTree::deleteByData(int data) {
    if (root == NULL)
      // Tree is empty
      return;
 
    RBNode *v = search(data), *u;
 
    if (v->data != data) {
      cout << "No node found to delete with value:" << data << endl;
      return;
    }
 
    deleteNode(v);
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

    tree.insertElement(11);
    tree.insertElement(2);
    tree.insertElement(14);
    tree.insertElement(1);
    tree.insertElement(15);
    // tree.insertElement(7);
    // tree.insertElement(5);
    // tree.insertElement(8);
    // tree.insertElement(4);
    tree.print();
    tree.deleteByData(15);
    tree.deleteByData(14);
    tree.print();

    return 0;
}