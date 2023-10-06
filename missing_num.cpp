#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>&a, int N) {
  
  //better solution
  /*  vector<int> hash(N+1,0);
    for(int i=0;i<N;i++)
    {
      
        hash[a[i]]=1;
    }
    for(int i=1;i<=N;i++)
    {
        if(hash[i]==0)
        {
          return i;
        }
    }
 return -1;*/
 //brute force approch 
 for(int i=1;i<=N;i++)
 {
     for(int j=0;j<N-1;j++)
     {
        cout<<"i ki value "<<i<<"  a[j] ki value "<<a[j]<<endl;
         if(a[j]!=i)
         { 
            cout<<"if loop ke andar"<<endl;
            cout<<i<<endl;
            return i;
         }
     }
 }
return -1;
}
int main()
{
  vector<int> arr1 = {1, 2, 3, 4, 6};
  int N=arr1.size();
   cout<< missingNumber(arr1,N)<<endl;
}