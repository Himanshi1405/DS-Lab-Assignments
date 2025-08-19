//Write a program to count the total number of distinct elements in an array of length number

#include<iostream>
using namespace std;

 void bubbleSort(int*arr,int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
           if(arr[j]>arr[j+1]){
               arr[j]=arr[j]+arr[j+1];
               arr[j+1]=arr[j]-arr[j+1];
               arr[j]=arr[j]-arr[j+1];
           } 
        }
    } 
 }
 
 void duplicate(int*arr , int n){
    bubbleSort(arr,n);
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=arr[i+1]){
            count++; 
        }
    }
    cout<<"The number of distinct elements in an array is "<<count;     
 }
 
 int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    duplicate(arr,n);
     
 }