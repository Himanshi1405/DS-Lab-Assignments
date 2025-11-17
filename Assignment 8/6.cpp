#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i){
        while(i>0 && heap[(i-1)/2] < heap[i]){
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i){
        int n = heap.size();
        while(true){
            int l = 2*i+1, r = 2*i+2, largest=i;
            if(l<n && heap[l] > heap[largest]) largest = l;
            if(r<n && heap[r] > heap[largest]) largest = r;

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    void pop(){
        if(heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top(){
        return heap.empty() ? -1 : heap[0];
    }
};

int main(){
    MaxHeap pq;
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(25);

    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "After pop, top: " << pq.top() << endl;

    return 0;
}
