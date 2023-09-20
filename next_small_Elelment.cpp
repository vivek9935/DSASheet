#include<iostream>
#include<stack>
#include <limits.h>
#include<vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> arr, int n) {

  vector<int> ans(n,-1);
  for (int i = 0; i < n; i++)
  { 
    for(int j=i+1;j<n;j++)
    {
        cout<<"  "<<arr[i]<<"   ";
      if(arr[i]>arr[j])
        {
            ans[i]=arr[j];
            break;

        }
    }
  }
  
  return ans;
}
int main()
{
    vector<int> arr{5,4,3,2,1};
    int n=arr.size();
    vector<int> ans;
    ans = nextSmallerElement(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<"  ";
    }cout<<endl;
    return 0;
}