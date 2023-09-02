#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    //  cout<<n<<endl;
      priority_queue<int> pq;
   for (int i = l; i < k; i++) {
     pq.push(arr[i]);
     //cout<<"   Top values of ques are    "<<pq.top();
   }
   cout<<endl;
   cout<<"in the top is  "<<pq.top()<<endl;
       for(int i=k;i<=r;i++){
           if(arr[i]<pq.top())
           {
               
               pq.pop();
               pq.push(arr[i]);
               cout<<"the new push  is "<<arr[i]<<endl;
               cout<<"  on this the top valus is "<<pq.top()<<endl;
           }
       }
       int ans=pq.top();
       return ans;
    } 
int main()
{
    int arr[]{7,10,4,3,20,15};
    int l=0;
    int r=5;
    int k=3;
    cout<<kthSmallest(arr,l,r,k)<<endl;

}