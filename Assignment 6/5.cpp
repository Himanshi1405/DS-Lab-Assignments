#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool isCircular(Node *head) {
    if (!head) return true;
    Node *t = head->next;
    while (t && t != head)
        t = t->next;
    return (t == head);
}

int main() {
    Node *head = new Node();
    head->data = 1;

    Node *node2 = new Node();
    node2->data = 2;
    head->next = node2;

    node2->next = head; // make circular

    cout << (isCircular(head) ? "Circular" : "Not Circular");
}
