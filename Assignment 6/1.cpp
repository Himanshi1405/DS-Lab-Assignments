#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node *head = NULL;

void insertFirst(int x) {
    Node *n = new Node();
    n->data = x;
    n->prev = NULL;
    n->next = head;
    if (head != NULL) head->prev = n;
    head = n;
}

void insertLast(int x) {
    Node *n = new Node();
    n->data = x;
    n->next = NULL;
    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }
    Node *t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertAfter(int key, int x) {
    Node *t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    Node *n = new Node();
    n->data = x;
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}

void deleteNode(int key) {
    Node *t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

bool search(int key) {
    Node *t = head;
    while (t) {
        if (t->data == key) return true;
        t = t->next;
    }
    return false;
}

void display() {
    Node *t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    insertFirst(10);
    insertLast(20);
    insertAfter(10, 15);
    display();
    deleteNode(15);
    display();
    cout << (search(20) ? "Found" : "Not Found");
    return 0;
}
