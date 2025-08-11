/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(){
    
    int r, c;
    printf("Enter size of matrix:\n");
    scanf("%d %d", &r, &c);
    int arr[r][c];
    printf("Enter elements of matrix:\n");
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
        scanf("%d", &arr[i][j]);
        }
    }
 
    // Calculate and print sum of each row
    for(int i = 0; i < r; i++) {
        int rowSum = 0;
        for(int j = 0; j < c; j++) {
            rowSum += arr[i][j];
        }
        printf("Sum of row %d = %d\n", i, rowSum);
    }

    // Calculate and print sum of each column
    for(int j = 0; j < c; j++) {
        int colSum = 0;
        for(int i = 0; i < r; i++) {
            colSum += arr[i][j];
        }
        printf("Sum of column %d = %d\n", j, colSum);
    }

    return 0;
}

    