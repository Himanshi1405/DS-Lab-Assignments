/* Develop a menu driven program demonstrating the following operations on Circular
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().#include <bits/stdc++.h>*/
using namespace std;
int MAX = 3;

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue() {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }
        int val;
        cout << "Enter element to enqueue: ";
        cin >> val;

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = val;
        cout << val << " enqueued successfully\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }
        cout << arr[front] << " dequeued\n";

        if (front == rear) {
            // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice;

    do {
        cout << "\n---- Circular Queue Menu ----\n";
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
