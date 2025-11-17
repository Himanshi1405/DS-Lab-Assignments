#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    for(int i=0, j=n-1; i<j; i++, j--) {
        int minIndex = i, maxIndex = j;

        for(int k=i; k<=j; k++) {
            if(arr[k] < arr[minIndex]) minIndex = k;
            if(arr[k] > arr[maxIndex]) maxIndex = k;
        }

        swap(arr[i], arr[minIndex]);

        if(maxIndex == i) maxIndex = minIndex;

        swap(arr[j], arr[maxIndex]);
    }
}

int main() {
    int arr[] = {20, 5, 7, 90, 45, 2, 15};
    int n = 7;

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
}
