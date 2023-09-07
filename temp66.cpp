#include<bits/stdc++.h>
using namespace std;

int fibo(int n, pair<int, int> &p) {
  if (n == 1)
    return p.second;
  
  int a = p.first;
  int b = p.second;
  return fibo(n - 1, make_pair(b, a + b));
}

int main() {
  int n;
  cin >> n;
  pair<int,int> &p (make_pair(0,1));
  cout << fibo(n, p) << endl;
  return 0;
}