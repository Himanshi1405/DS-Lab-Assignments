#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key){
    if(root == NULL) return new Node(key);
    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);
    return root;
}

// (a) Search (Recursive)
bool searchRec(Node* root, int key){
    if(!root) return false;
    if(root->data == key) return true;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) Search (Non-Recursive)
bool searchNonRec(Node* root, int key){
    while(root){
        if(root->data == key) return true;
        root = (key < root->data) ? root->left : root->right;
    }
    return false;
}

// (b) Maximum element
int findMax(Node* root){
    while(root->right) root = root->right;
    return root->data;
}

// (c) Minimum element
int findMin(Node* root){
    while(root->left) root = root->left;
    return root->data;
}

// (d) Inorder Successor
Node* successor(Node* root, int key){
    Node* succ = NULL;
    while(root){
        if(key < root->data){
            succ = root;
            root = root->left;
        }
        else root = root->right;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* predecessor(Node* root, int key){
    Node* pred = NULL;
    while(root){
        if(key > root->data){
            pred = root;
            root = root->right;
        }
        else root = root->left;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Search 40 Recursive: " << searchRec(root,40) << endl;
    cout << "Search 90 Non-Recursive: " << searchNonRec(root,90) << endl;

    cout << "Minimum = " << findMin(root) << endl;
    cout << "Maximum = " << findMax(root) << endl;

    Node* s = successor(root, 50);
    Node* p = predecessor(root, 50);

    cout << "Successor of 50: " << (s ? s->data : -1) << endl;
    cout << "Predecessor of 50: " << (p ? p->data : -1) << endl;
    return 0;
}
