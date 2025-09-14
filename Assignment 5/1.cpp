/* Develop a menu driven program for the following operations of on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer (global for simplicity)
Node* head = NULL;

// Function to insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

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
    cout << "Inserted " << value << " at the end.\n";
}

// Function to insert before or after a specific value
void insertBeforeAfter(int value, int target, bool before) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    // Case 1: Insert before head
    if (before && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " before " << target << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (before && temp->next != NULL && temp->next->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }
        if (!before && temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Target " << target << " not found.\n";
}

// Function to delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}

// Function to delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = NULL;
}

// Function to delete a specific node
void deleteSpecific(int target) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted node " << target << ".\n";
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node " << target << " not found.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted node " << target << ".\n";
    delete toDelete;
}

// Function to search for a node
void searchNode(int target) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            cout << "Node " << target << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << target << " not found.\n";
}

// Function to display all nodes
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main menu
int main() {
    int choice, value, target;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and target: ";
                cin >> value >> target;
                insertBeforeAfter(value, target, true);
                break;
            case 4:
                cout << "Enter value and target: ";
                cin >> value >> target;
                insertBeforeAfter(value, target, false);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter target to delete: ";
                cin >> target;
                deleteSpecific(target);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> target;
                searchNode(target);
                break;
            case 9:
                displayList();
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
