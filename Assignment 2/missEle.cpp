/*Given an array of n-1 distinct integers in the range of 1 to n, find the missing number
in it in a Sorted Array
(a) Linear time
(b) Using binary search.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n-1];
    cout<<"Enter a sorted array of 1 to n-1 elements"<<endl;
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    // using linear time
    for(int i=0; i<n-1; i++){
        if(arr[i]!= (i+1)){
            cout<<"The missing element using linear time is : "<<i+1<<endl;
            break;
        }
    }
    
    // using binary search
    int beg=0;
    int end=n-2;
    int missing=0;
    while(beg<=end){
        int mid=(beg+end)/2;
        if(arr[mid]!=mid+1){
           missing=mid+1;
           end=mid-1;// check missing no. before 
        }
        else{
            beg=mid+1;// checks for missing no. after
        }
    }
    cout<<"The missing element using binary search is : "<<missing;
    return 0;
    
}