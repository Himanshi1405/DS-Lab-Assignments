/*Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b */
#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(string s) {
    vector<int> freq(26, 0); // frequency of characters
    queue<char> q;

    for (char ch : s) {
        // Update frequency
        freq[ch - 'a']++;
        // Push current char
        q.push(ch);

        // Remove all repeating chars from front
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Print result for this step
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";   // Sample Input
    cout << "Input: " << s << endl;
    cout << "Output: ";
    firstNonRepeating(s);
    return 0;
}
