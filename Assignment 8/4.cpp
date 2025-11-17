#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool isBST(Node* root, int minVal, int maxVal){
    if(!root) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(15);

    if(isBST(root, INT_MIN, INT_MAX)) cout << "Valid BST";
    else cout << "Not a BST";
    return 0;
}

