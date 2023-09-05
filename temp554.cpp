#include<iostream>
#include<algorithm>
using namespace std;
void rotate(int arr[], int n)
{
    for(int i=0;i<n;i++){
        if(n-2>=0)
        swap(arr[n-1-i],arr[n-2-i]);
    }   
}