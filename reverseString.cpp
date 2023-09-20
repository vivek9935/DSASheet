
#include<iostream>
#include <stack>
#include <string>
using namespace std;
string reverseString(string str) {
    stack<string> st;
    string word = "";
    string reversedString = "";

    for (int i=0;i<=str.length();i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word.push_back(str[i]);
        } else {
            if (!word.empty()) {
                st.push(word);
                word = "";
            }
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    while (!st.empty()) {
        reversedString += st.top();
        st.pop();
        if (!st.empty()) {
            reversedString += ' ';
        }
    }

    return reversedString;
}
int main()
{
    string str ="welcome to coding ninja";
    cout<<reverseString(str)<<endl;
}