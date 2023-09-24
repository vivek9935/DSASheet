#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isValid(string s)
{
  stack<char> st;
  int len = s.length();
  bool flag;
  for (int i = 0; i < len; i++)
  {
    char ch = s[i];
    if (ch == '(' || ch == '[' || ch == '{')
      st.push(ch);
    else
    {
      flag = false;
      char top = st.top();
      if ((top == '{' && s[i] == '}') || (top == '(' && s[i] == ')') || (top == '[' && s[i] == ']'))
        flag = true;
    }
  }
  if (flag == false)
    return false;
  else
    return true;
}
int main()
{
  string s{"{}{}[]"};
  cout << "bracket is valid or not  " << isValid(s) << endl;
}