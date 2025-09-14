/* Write a program to implement a stack using (a) Two queues and (b) One Queue.*/

#include <bits/stdc++.h>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate elements
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top: " << st.top() << endl; // 20

    return 0;
}
