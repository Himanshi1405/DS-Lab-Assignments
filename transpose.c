//WAP to find transpose of an array

#include <stdio.h>
 
 void transpose(int r1, int c1, int m1[r1][c1]) {
    printf("Transpose of the matrix:\n");
        for (int i = 0; i < c1; i++) {
            for (int j = 0; j < r1; j++) {
                printf("%d ", m1[j][i]);
            }
            printf("\n");
        }
    }
 
int main(){
    
    int r1, c1;
    printf("Enter size of first matrix:\n");
    scanf("%d %d", &r1, &c1);
    int m1[r1][c1];
    printf("Enter elements of first matrix:\n");
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
        scanf("%d", &m1[i][j]);
        }
    }
    
    transpose(r1, c1, m1);

    return 0;
 }