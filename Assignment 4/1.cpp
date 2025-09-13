/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include <bits/stdc++.h>
using namespace std;
int MAX = 5;

class Queue {
    int arr[5];
    int i = 0; // number of elements
public:
    void enqueue() {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }
        int val;
        cout << "Enter the element you want to enqueue: ";
        cin >> val;
        arr[i] = val;   // insert at rear
        i++;
        cout << val << " enqueued successfully\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        cout << arr[0] << " dequeued\n";
        for (int j = 0; j < i - 1; j++) { // shift all elements left
            arr[j] = arr[j + 1];
        }
        i--;
    }

    bool isEmpty() {
        return (i == 0);
    }

    bool isFull() {
        return (i == MAX);
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "The element at front is: " << arr[0] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "The elements in queue are: ";
        for (int j = 0; j < i; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    do {
        cout << "\n---- Queue Menu ----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
            case 6: cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n"); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
