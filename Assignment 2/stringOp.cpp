/*4) String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.*/

#include <bits/stdc++.h>
using namespace std;

void concatenate(string &s1){
    string s2, s3;
    cout<<"Enter a string to concatenate : ";
    getline(cin, s2);
    s3= s1 + s2;
    cout<<"The concatenated string is : "<<s3<<endl;
}

void reverseString(string &s1){
    string s3= s1;
    reverse(s3.begin(), s3.end());
    cout<<"The reversed string is : "<<s3<<endl;
} 

void deleteVowel(string &s1){
    string s3= s1;
    for(int i=0; s3[i]!= '\0'; i++){
        if(s3[i]=='a' || s3[i]=='e' || s3[i]=='i' || s3[i]=='o' || s3[i]=='u'){
            for(int j=i; s3[j]!= '\0'; j++){
                s3[j]=s3[j+1];
            }
            i--;
        }
    }
    cout<<"The string after deleting vowel is : "<<s3<<endl;
}

void sortString(string &s1){
    string s3= s1;
    sort(s3.begin(), s3.end());
    cout<<"The sorted string is : "<<s3<<endl;
}

void lowerCase(char ch){
    char low = tolower(ch);
    cout<<"Given character in lower case is : "<<low<<endl;
}

int main()
{
    string s1;
    char ch;
    cout<<"Enter a string : ";
    getline(cin,s1);
    concatenate(s1);
    reverseString(s1);
    deleteVowel(s1);
    sortString(s1);
    cout<<"Enter a uppercase character : ";
    cin>>ch;
    lowerCase(ch);

    return 0;
}