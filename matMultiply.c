/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
 
 void matMultiply(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]) {
    if (c1 == r2) {
        int am[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                am[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    am[i][j] += m1[i][k] * m2[k][j];
                }
                printf("%d ", am[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix multiplication not possible\n");
    }
}
 
int main(){
    
    int r1, c1, r2, c2;
    printf("Enter size of first matrix:\n");
    scanf("%d %d", &r1, &c1);
    int m1[r1][c1];
    printf("Enter elements of first matrix:\n");
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
        scanf("%d", &m1[i][j]);
        }
    }
    printf("Enter size of second matrix:\n");
    scanf("%d %d", &r2, &c2);
    int m2[r2][c2];
    printf("Enter elements of second matrix:\n");
    
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
        scanf("%d", &m2[i][j]);
            
        }
    }
    
    matMultiply(r1, c1, m1, r2, c2, m2);

    return 0;
 }