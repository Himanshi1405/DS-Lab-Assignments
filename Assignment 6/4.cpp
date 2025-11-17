#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
} *head = NULL;

void insert(char x) {
    Node *n = new Node();
    n->data = x;
    n->next = head;
    n->prev = NULL;
    if (head) head->prev = n;
    head = n;
}

bool isPalindrome() {
    if (!head) return true;
    Node *left = head, *right = head;

    while (right->next) right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    insert('R');
    insert('A');
    insert('D');
    insert('A');
    insert('R');

    cout << (isPalindrome() ? "Palindrome" : "Not Palindrome");
}
