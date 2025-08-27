/*Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek(). */

#include <bits/stdc++.h>
using namespace std;
#define n 10 

class Stack{
   int arr[n];
   int top;
   
   public:
   Stack(){
       top=-1;
   }
   void push(int x){
       if(isFull()){
           cout<<"Stack overflow, no more space"<<endl;
       }
       else{
           arr[++top]=x;
           cout <<x<<" is pushed into stack." << endl;
       }
   }
   void pop(){
       if(isEmpty()){
           cout<<"Stack underflow, nothing to pop"<<endl;
       }
       else{
           cout <<arr[top--]<<" is popped from stack." << endl;
       }
   }
   bool isFull(){
       return (top==n-1);
   }
   bool isEmpty(){
       return (top==-1);
   }
   void display(){
        if (isEmpty()) {
        cout<<"Stack is empty."<<endl;
        } 
       cout<<"The elements in the stack is :"<<endl;
       for(int i=0; i<=top; i++){
           cout<<arr[i]<<endl;
       }
   }
   void peek(){
       if (isEmpty()){
            cout<<"Stack is empty."<<endl;
        } 
        else{
            cout<<"Top element is: "<<arr[top];
        }
    }
};

int main(){
    Stack s;
    int choice, value;
    
    do{
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is NOT Empty." << endl;
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is NOT Full." << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 7);


    return 0;
}
