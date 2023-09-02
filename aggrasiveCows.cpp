#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int> &stalls, int k,int mid)
{
    int cowCount=1;
    int lastpos=stalls[0];
    for(int i=0;i<stalls.size();i++)
    {
            if(stalls[i]-lastpos>=mid){
                cout<<(stalls[i]-lastpos)<<endl;
              cowCount++;
                  if(cowCount==k)
                  {
                      return true;
                  }
                lastpos=stalls[i];
             }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxi=-1;
    int n=stalls.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,stalls[i]);
        
    }
    int e=maxi;
    int ans =-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        cout<<"mid befor the if is   "<<mid<<endl;
        if(isPossible(stalls,k,mid))
        {
            ans = mid;
            cout<<"mid inside if statement  the  "<<mid<<endl;
            s=mid+1;
        }
        else
        {
            cout<<"mid inside else statement "<<mid<<endl;
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    }
int main()
{
    vector<int> stalls{4,2,1,3,6};
    int k= 3;
    cout<<aggressiveCows(stalls,k)<<endl;
}