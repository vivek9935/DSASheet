#include<iostream>
using namespace std;
int recyclePens(int n, int r, int k, int c ){
  int j=0;
  int maxi=0;
  int x = r/c;
  if(x>=n)
   return n;
  for (int i = 1; i < n; i++)
  { 
	 j=(r+k*i)/c;
	 if(j<=(n-i))
	 {
		 maxi++;
	 }
  }
  return maxi;
}
int main()
{
    cout<<"total recycle pen is  "<<recyclePens(10,10,5,5)<<endl;
}