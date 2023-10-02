#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{   int N=arr.size();
	priority_queue<int,vector<int>,greater<int>>mini;
        for(int i=0;i<N;i++)
        {
            int sum=0;
            for(int j=i;j<N;j++)
            {
                sum +=arr[j];
                if(mini.size()<k)
                {
                    mini.push(sum);
                }
                else
                {
                    if(sum>mini.top())
                    {
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
}

// Driver's code
int main()
{
	vector<int>a = { 60,-20,4,-5};
	int N = sizeof(a) / sizeof(a[0]);
	int K = 2;
    cout<<getKthLargest(a,K)<<endl;
    return 0;
}
