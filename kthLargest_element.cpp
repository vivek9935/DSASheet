#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Klargest(vector<int> &a, int k, int n) {
    vector<int>ans;
    sort(a.begin(),a.end());
    for(int i=n-1;i>=0&&k>0;i--)
    {
         k--;
     ans.push_back(a[i]);
    
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
vector<int> a{3,4,1,2};
int n = a.size();
int k=2;
vector<int> ans;
ans=Klargest(a, k,n);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<"  ";
}cout<<endl;
}