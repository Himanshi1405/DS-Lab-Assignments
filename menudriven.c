/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*Develop a Menu driven program  to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT */

#include <stdio.h>
#include <stdbool.h>
int n,ele, pos;
int arr[100];

bool created(int choice){
    if (choice==1){return 1;}
    else{return 0;}
}
    
    void create(){
    printf("Enter the size of the array ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(){
    printf("The elememts in array is: \n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}

void insert(){
    printf("Enter the element you want to insert ");
    scanf("%d",&ele);
    printf("Enter the position at which you want to insert ");
    scanf("%d",&pos);
    printf("The elememts in array is: \n");
    for(int i=0;i<n;i++){
        if(pos==i){
            printf("%d\n",arr[i]);
        }
        printf("%d\n",arr[i]);
    }
}

void delete(){
    printf("Enter the element you want to delete ");
    scanf("%d",&ele);
    printf("The elememts in array is: \n");
    for(int i=0;i<n;i++){
        if(ele==arr[i]){
            continue;
        }
        printf("%d\n",arr[i]);
    }
}

void linearSearch(){
    printf("Enter the element you want to find ");
    scanf("%d",&ele);
    printf("The elememts is at: ");
    for(int i=0;i<n;i++){
        if(ele==arr[i]){
            printf("%d\n",i);
        }
    }
}

void end(){
    printf("Exiting the program");
}


int main()
{
    int choice=0;
    while(1){
        printf("Enter your choice: create(1), display(2), insert(3), delete(4), linear search(5), exit(6)\n");
        scanf("%d",&choice);
        int c=created(choice);
        if(c==1){
            create();
            while(choice!=6){
            printf("Enter your choice: create(1), display(2), insert(3), delete(4), linear search(5), exit(6)\n");
            scanf("%d",&choice);
                switch (choice){
                case 2:
                display();
                continue;
                case 3:
                insert();
                continue;
                case 4:
                delete();
                continue;
                case 5:
                linearSearch();
                continue;
                case 6:
                end();
                break;
                }
                
            }
        
        }
        else{
            printf("First create an array\n");
            continue;
        }
            
        
    }

    return 0;
}