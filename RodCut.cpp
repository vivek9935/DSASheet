#include<iostream>
#include<limits.h>
using namespace std;
int solve(int n,int x,int y,int z)
{
    //base cases 
    if(n==0)
      return 0;
    if(n<0)
      return -1;
    int a=solve(n-x,x,y,z);
    int b=solve(n-y,x,y,z);
    int c=solve(n-z,x,y,z);
    int ans = max(a,max(b,c));
    return ans;
}
int cutSegment(int n,int x,int y,int z)
{
    int ans = solve(n,x,y,z);
    if(ans<0)
       return 0;
    else 
       return ans;
}
int main()
{
    int n=7,x=5,y=2,z=2;
    cout<<cutSegment(n,x,y,z)<<endl;
}