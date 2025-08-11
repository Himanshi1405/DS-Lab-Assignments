/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
 
 void reverse(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The reverse of array:\n");
    for (int i=0;i<n/2;i++){
        arr[i]=arr[i]+arr[n-1-i];
        arr[n-1-i]=arr[i]-arr[n-1-i];
        arr[i]=arr[i]-arr[n-1-i];
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
 }
 
 
 int main(){
    reverse();
    return 0;
 }