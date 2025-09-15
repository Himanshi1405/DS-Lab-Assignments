/*Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output- 3*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display list
void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to find middle element
void findMiddle() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move by 1
        fast = fast->next->next;   // move by 2
    }

    cout << "Middle element is: " << slow->data << endl;
}

// Main function
int main() {
    // Example: 1->2->3->4->5
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);

    cout << "Linked List: ";
    displayList();

    findMiddle();

    return 0;
}
