#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i; // either max or min index
    int left = 2*i + 1;
    int right = 2*i + 2;

    // For increasing order -> build max heap
    // For decreasing order -> build min heap
    if(increasing) {
        if(left < n && arr[left] > arr[extreme]) extreme = left;
        if(right < n && arr[right] > arr[extreme]) extreme = right;
    } else {
        if(left < n && arr[left] < arr[extreme]) extreme = left;
        if(right < n && arr[right] < arr[extreme]) extreme = right;
    }

    if(extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing = true) {
    // Build heap
    for(int i=n/2 - 1; i>=0; i--)
        heapify(arr, n, i, increasing);

    // Extract
    for(int i=n-1; i>0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    heapSort(arr, n, true); // true → increasing | false → decreasing

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
