/*Develop a Menu driven program  to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT */

#include <stdio.h>
int n,ele, pos;
int arr[100];
    
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
    for(int i=n;i>=pos;i--){
        if(pos==i){
            arr[i]=ele;
        }
        else {
            arr[i]=arr[i-1];
        }
    }
    for(int i=0;i<=n;i++){
        printf("%d\n",arr[i]);
    }
    
}

void delete(){
    printf("Enter the element you want to delete: ");
    scanf("%d", &ele);

    int found = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele){
            found = 1;
    
            for(int j = i; j < n-1; j++){
                arr[j] = arr[j+1];
            }
            n--;  
            break;
        }
    }
    if(found){
        printf("Elements after deletion:\n");
        for(int i = 0; i < n; i++){
            printf("%d\n", arr[i]);
        }
    }
    else{
        printf("Element not found in the array.\n");
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


int main()
{
    int choice=0;
    while(choice!=6){
        printf("Enter your choice: create(1), display(2), insert(3), delete(4), linear search(5), exit(6)\n");
        scanf("%d",&choice);
        if(choice==1){
            create();
            while(choice!=6){
            printf("Enter your choice: create(1), display(2), insert(3), delete(4), linear search(5), exit(6)\n");
            scanf("%d",&choice);
           
                switch (choice){
                case 2:
                display();
                break;
                case 3:
                insert();
                break;
                case 4:
                delete();
                break;
                case 5:
                linearSearch();
                break;
                case 6:
                
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