#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num = n; // Make sure n is positive
    //int position = 1; 
    int k=0;
    int sum1 = 0, sum2 = 0;
    for(int i=num;i!=0;i=i/10)
    {
        k++;
    }
    while (k!=0) {
        int digit = n % 10;
        n = n/10;
        if(k%2==0)
         sum1 +=digit;
        else
          sum2 +=digit;
        k--;
    }

    cout << sum2 << " " << sum1;
    return 0;
}