#include <iostream>
using namespace std;


struct Tnode {
 int key;
 Tnode* LeftTree = nullptr;
 Tnode* RightTree = nullptr;
};


int main() {
 Tnode* root = nullptr;
 root = new Tnode;
 root->key = 10;
 root->LeftTree = new Tnode;
 root->LeftTree->key = 5;
 root->RightTree = new Tnode;
 root->RightTree->key = 12;
 Tnode* tmp = root->RightTree;
 tmp->LeftTree = new Tnode;
 tmp->LeftTree->key = 100;
 tmp->RightTree = new Tnode;
 tmp->RightTree->key = 102;

}
