#include <iostream>
#include <map>
#include<unordered_map>
#include <vector>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int maxi;
    unordered_map<int, int> mp;
    int n = fruits.size();
    for (int i = 0; i < n; i++)
    {
        mp[fruits[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"   "<<it->second<<endl;
        
    }
}
int main()
{
    vector<int> f{1,2,1,3,3,3,2,5};
    totalFruit(f);
}