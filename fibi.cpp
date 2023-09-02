#include<iostream>
#include<map>
using namespace std;

int fib(int n, map<int, int> &dp)
{
    if(n <= 1)
        return n;
    
    if(dp.find(n) != dp.end())
        return dp[n];
    
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    map<int, int> dp;
    cout << "Fibonacci(" << n << ") = " << fib(n, dp) << endl;

    return 0;
}
