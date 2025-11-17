#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* create(){
    int val;
    cout << "Enter value (-1 for no node): ";
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    cout << "Enter left child of " << val << endl;
    root->left = create();
    cout << "Enter right child of " << val << endl;
    root->right = create();
    return root;
}

void preorder(Node* root){
    if(root){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = create();
    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
