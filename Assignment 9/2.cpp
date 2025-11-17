#include <iostream>
using namespace std;

#define MAX 100
int heapArr[MAX];
int heapSize = 0;

// Insert into Max Heap
void insert(int value) {
    heapArr[++heapSize] = value;
    int i = heapSize;

    while(i > 1 && heapArr[i/2] < heapArr[i]) {
        swap(heapArr[i], heapArr[i/2]);
        i = i/2;
    }
}

// Delete max (root)
int deleteMax() {
    if(heapSize == 0) {
        cout << "Priority Queue is Empty\n";
        return -1;
    }

    int maxVal = heapArr[1];
    heapArr[1] = heapArr[heapSize--];

    int i = 1;
    while(true) {
        int left = 2*i, right = 2*i+1, largest = i;

        if(left <= heapSize && heapArr[left] > heapArr[largest])
            largest = left;
        if(right <= heapSize && heapArr[right] > heapArr[largest])
            largest = right;

        if(largest != i) {
            swap(heapArr[i], heapArr[largest]);
            i = largest;
        } else break;
    }
    return maxVal;
}

// Peek max
int getMax() {
    if(heapSize == 0) return -1;
    return heapArr[1];
}

// Display
void display() {
    if(heapSize == 0) {
        cout << "Priority Queue is Empty\n";
        return;
    }
    cout << "Priority Queue: ";
    for(int i = 1; i <= heapSize; i++)
        cout << heapArr[i] << " ";
    cout << "\n";
}

int main() {
    insert(40);
    insert(10);
    insert(50);
    insert(30);
    insert(60);

    display();

    cout << "Deleted Max: " << deleteMax() << endl;
    display();

    cout << "Current Max: " << getMax() << endl;

    return 0;
}
