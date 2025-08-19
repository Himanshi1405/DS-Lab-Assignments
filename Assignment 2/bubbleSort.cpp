//performing bubble sort
#include<bits/stdc++.h>
using namespace std;

int main(){
    int temp=0;
    int arr[7]={64,34,25,12,22,11,90};
    int n=7;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
    cout<<"The sorted array is:"<<endl;
    for(int i=0; i<7; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
	