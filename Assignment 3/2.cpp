/*Given a string, reverse it using STACK. For example “DataStructure” should be output as
  “erutcurtSataD.” */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str="DataStructures";
    stack<char>s;
    
    for(char ch:str){
        s.push(ch);
    }
    
    cout<<"Reversed string is: ";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}