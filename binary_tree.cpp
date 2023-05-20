#include <cstddef>
#include <iostream>
#include <random>
#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int _data): data(_data), left(nullptr), right(nullptr) {}

    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode* root) {
        os << root->data << endl;
        os << "/\\" << endl;
        if (root->left != nullptr) os << root->left;
        if (root->right != nullptr) os << root->right;
        return os;
    }
};

std::ostream& operator<<(std::ostream& os, const BinaryTreeNode* root) {
        os << root->data << endl;
        os << "/\\" << endl;
        if (root->left != nullptr) os << root->left;
        if (root->right != nullptr) os << root->right;
        return os;
    }

BinaryTreeNode* buildtree(int d) {
  BinaryTreeNode* root;
  if(d==-1){
    return NULL;
  }
  root=new BinaryTreeNode(rand()%100);
  root->left=buildtree(d-1);
  root->right=buildtree(d-1);
  return root;
}

int main() {
    BinaryTreeNode* root = buildtree(10);
    cout << root;
}