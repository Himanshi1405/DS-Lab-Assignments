#include <bits/stdc++.h>
using namespace std;
int main(){

int n, temp, ele;
cout<<"Enter the number of elements"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements:"<<endl;
for(int i=0; i<n; i++){
	cin>>arr[i];
} 

sort(arr,arr+n);

cout<<"The sorted array is:"<<endl;
for(int i=0; i<n; i++){
	cout<<arr[i]<<endl;
}

//binary search
cout<<"Enter the element you want to search"<<endl;
cin>>ele;
int found=0;
int beg=0;
int end=n-1;
int mid=n/2;
while(beg<=end) {
    mid=(beg+end)/2;
	if (ele>arr[mid]){
		beg=mid+1;
	}
	else if(ele<arr[mid]){
		end=mid-1;
	} 
	else if(ele==arr[mid]){
		cout<<"Elelment is found at "<<mid;
		found++;
		break;
	}
}
if(found==0){
    cout<<"Element not in the array";
	return 0;
}
}