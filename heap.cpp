#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest =i;
    int left=2*i;
    int right=2*i+1;
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        std::swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main()
{
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++)
    cout<<arr[i]<<"  ";
    cout<<endl;
heapSort(arr,n);
 for(int i=1;i<=n;i++)
    cout<<arr[i]<<"  ";
    cout<<endl;

    
}