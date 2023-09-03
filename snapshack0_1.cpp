#include<iostream>
#include<vector>
using namespace std;
void solveTab(vector<int> &weight,vector<int> &value,int n,int capacity)
{
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    for(int w=weight[0];w<=capacity;w++)
    {
        if(weight[0]<=capacity)
        {
            dp[0][w]=value[0];
        }
        else
          dp[0][w]=0;
    }
    for(int i=0;i<n;i++)
    {cout<<dp[0][i]<<endl;}
}
void knapsack(vector<int>&weight,vector<int> value,int n,int maxWeight)
{
    solveTab(weight,value,n,maxWeight);
}
int main() {
    int n=4; // Number of items
    //cin >> n;
    vector<int> weight{1,2,4,5};
    vector<int> value{5,4,8,6};
    
    // Input the weights and values of items
    // for (int i = 0; i < n; i++) {
    //     cin >> weight[i];
    // }
    
    // for (int i = 0; i < n; i++) {
    //     cin >> value[i];
    // }
    
    int maxWeight=5; // Maximum weight capacity of the knapsack
    //cin >> maxWeight;
    knapsack(weight, value, n, maxWeight);
    
    // int result = knapsack(weight, value, n, maxWeight);
    
    // cout << "Maximum value that can be obtained: " << result << endl;
    
    return 0;
}