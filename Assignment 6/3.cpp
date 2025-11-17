#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
} *dHead = NULL;

struct CNode {
    int data;
    CNode *next;
} *cHead = NULL;

void dInsert(int x) {
    DNode *n = new DNode();
    n->data = x;
    n->next = dHead;
    n->prev = NULL;
    if (dHead) dHead->prev = n;
    dHead = n;
}
void cInsert(int x) {
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

int sizeDLL() {
    int count = 0;
    DNode *t = dHead;
    while (t) {
        count++;
        t = t->next;
    }
    return count;
}

int sizeCLL() {
    if (!cHead) return 0;
    int count = 0;
    CNode *t = cHead;
    do {
        count++;
        t = t->next;
    } while (t != cHead);
    return count;
}

int main() {
    dInsert(1);
    dInsert(2);
    dInsert(3);

    cInsert(10);
    cInsert(20);
    cInsert(30);
    cInsert(40);

    cout << "Size of DLL = " << sizeDLL() << endl;
    cout << "Size of CLL = " << sizeCLL() << endl;
}
