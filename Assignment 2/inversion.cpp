/*Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
count the number of inversions in an array*/

#include <bits/stdc++.h>
using namespace std;

void inversion(int *A, int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                count++;
            }
        }
    }
    cout<<"The number of inversions is: "<<count;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    inversion(A,n);

    return 0;
}