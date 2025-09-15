/*Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences. For example, if given linked list is 1->2->1-
>2->1->3->1 and given key is 1, then output should be 4. After deletion of all the
occurrences of 1, the linked list is 2->2->3*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert node at end
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
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to count and delete all occurrences of a key
int countAndDelete(int key) {
    int count = 0;

    // Handle head nodes that contain the key
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Now handle remaining nodes
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

// Main function
int main() {
    // Example: 1->2->1->2->1->3->1
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    cout << "Original List: ";
    displayList();

    int key;
    cout << "Enter key to count and delete: ";
    cin >> key;

    int occurrences = countAndDelete(key);
    cout << "Key " << key << " occurred " << occurrences << " times.\n";

    cout << "List after deleting all occurrences of " << key << ": ";
    displayList();

    return 0;
}
