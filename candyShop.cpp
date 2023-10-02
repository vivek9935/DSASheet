#include <bits/stdc++.h>
using namespace std;
long long minimumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(), cost.end());
    long long mini = 0;
    long long buy = 0;
    long long free = n - 1;
    while (buy <= free)
    {
        mini += cost[buy];
        buy++;
        free -= k;
    }
    return mini;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(), cost.end());
    long long maxi = 0;
    long long buy = n - 1;
    long long free = 0;
    while (buy <= free)
    {
        maxi += cost[buy];
        buy--;
        free += k;
    }
    return maxi;
}
int main()
{
    vector<int> a{9, 8, 2, 6, 4};
    int n = 5;
    int k = 2;
    cout << minimumCost(a, n, k) << endl;
    cout << maximumCost(a, n, k) << endl;
}