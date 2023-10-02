#include <bits/stdc++.h> 
using namespace std;
void inplaceRotate(vector<vector<int>> &arr)

{

    int n=arr.size();

   for(int i=0;i<n;i++){

       for(int j=i;j<n;j++){

           swap(arr[i][j],arr[j][i]);

           

       }

   }
   cout<<"afte transforming "<<endl;
   cout<<"-------------------------------------------"<<endl;
   for(auto &row:arr)
{
    for(auto col : row)
    {
        cout<<col<<"   ";
    }cout<<endl;
}

    for(int i=0;i<n;i++){

        int s=0;

        int e=n-1;

        

        while(s<=e){

            swap(arr[s][i],arr[e][i]);
            cout<<"afte each swap the answer    [s][i]  "<<s<<i<<" [e] [i] "<<e<<i<<endl;
   cout<<"-------------------------------------------"<<endl;
            for(auto &row:arr)
{
    for(auto col : row)
    {
        cout<<col<<"   ";
    }cout<<endl;
}

            s++;

            e--;

        }

    }

}
int main()
{
    vector<vector<int>>arr{{1,2,3},
                           {4,5,6},     
                           {7,8,9} };
inplaceRotate(arr);
for(auto &row:arr)
{
    for(auto col : row)
    {
        cout<<col<<"   ";
    }cout<<endl;
}
}  