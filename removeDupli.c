//WAP to remove duplicates from an array

#include <stdio.h>

int main(){
    int n,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

//Bubble sort
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
//Removing duplicate    
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            for(int j=i; j<n; j++){
                arr[j]=arr[j+1];
                n--;
            }
        }
    }
    printf("The sorted and unique array is:\n");
  for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }  
    
}