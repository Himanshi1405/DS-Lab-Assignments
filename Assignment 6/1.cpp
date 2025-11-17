#include <iostream>
using namespace std;

/************ DOUBLY LINKED LIST ************/

struct DNode {
    int data;
    DNode *prev, *next;
};

DNode *dHead = NULL;

void dInsertFirst(int x) {
    DNode *n = new DNode();
    n->data = x;
    n->prev = NULL;
    n->next = dHead;
    if (dHead) dHead->prev = n;
    dHead = n;
}
void dInsertLast(int x) {
    DNode *n = new DNode();
    n->data = x;
    n->next = NULL;
    if (!dHead) {
        n->prev = NULL;
        dHead = n;
        return;
    }
    DNode *t = dHead;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}
void dInsertAfter(int key, int x) {
    DNode *t = dHead;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    DNode *n = new DNode();
    n->data = x;
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}
void dDelete(int key) {
    DNode *t = dHead;
    while (t && t->data != key) t = t->next;
    if (!t) return;

    if (t->prev) t->prev->next = t->next;
    else dHead = t->next;

    if (t->next) t->next->prev = t->prev;
    delete t;
}
bool dSearch(int key) {
    DNode *t = dHead;
    while (t) {
        if (t->data == key) return true;
        t = t->next;
    }
    return false;
}
void dDisplay() {
    DNode *t = dHead;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

/************ CIRCULAR LINKED LIST ************/

struct CNode {
    int data;
    CNode *next;
};

CNode *cHead = NULL;

void cInsertLast(int x) {
    CNode *n = new CNode();
    n->data = x;
    if (!cHead) {
        cHead = n;
        n->next = cHead;
        return;
    }
    CNode *t = cHead;
    while (t->next != cHead) t = t->next;
    t->next = n;
    n->next = cHead;
}
void cDelete(int key) {
    if (!cHead) return;

    CNode *t = cHead, *prev = NULL;
    if (cHead->data == key && cHead->next == cHead) {
        delete cHead;
        cHead = NULL;
        return;
    }
    while (t->data != key) {
        prev = t;
        t = t->next;
        if (t == cHead) return;
    }
    prev->next = t->next;
    if (t == cHead) cHead = t->next;
    delete t;
}
bool cSearch(int key) {
    if (!cHead) return false;
    CNode *t = cHead;
    do {
        if (t->data == key) return true;
        t = t->next;
    } while (t != cHead);
    return false;
}
void cDisplay() {
    if (!cHead) return;
    CNode *t = cHead;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != cHead);
    cout << endl;
}

/************ MENU ************/

int main() {
    int choice, list, val, key;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 5) break;

        cout << "Choose List (1 = Doubly, 2 = Circular): ";
        cin >> list;

        switch(choice) {
            case 1: // Insert
                cout << "Enter value: ";
                cin >> val;
                if (list == 1) {
                    cout << "1.First 2.Last 3.After specific: ";
                    cin >> key;
                    if (key == 1) dInsertFirst(val);
                    else if (key == 2) dInsertLast(val);
                    else {
                        cout << "Insert after which key? ";
                        cin >> key;
                        dInsertAfter(key, val);
                    }
                } else {
                    cInsertLast(val);
                }
                break;

            case 2: // Delete
                cout << "Enter value to delete: ";
                cin >> val;
                if (list == 1) dDelete(val);
                else cDelete(val);
                break;

            case 3: // Search
                cout << "Enter value to search: ";
                cin >> val;
                cout << ((list==1 ? dSearch(val) : cSearch(val)) ? "Found" : "Not Found") << endl;
                break;

            case 4: // Display
                if (list == 1) dDisplay();
                else cDisplay();
                break;
        }
    }
    return 0;
}

