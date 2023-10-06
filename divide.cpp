
#include <bits/stdc++.h>
using namespace std;
int divideTwoInteger(int dividend, int divisor) {
	int moddivisor=divisor>0?divisor:-1*divisor;
	int divisor_helper=moddivisor;
	int count =1;
	int var;
	int moddivident=dividend;
	if(dividend<0)
	{
      moddivident=dividend*-1;
	}
    cout<<moddivisor<<"   "<<moddivident<<endl;
    
	while(divisor_helper<=moddivident)
	{
        cout<<moddivident<<"  "<<divisor_helper<<endl;
		if(divisor_helper<=moddivident)
		  {
              var=count;
			  count++;
		  }
		  divisor_helper +=moddivisor;
	}
	if((divisor<0&&dividend<0)||(divisor>0&&dividend>0))
	  return var;
	return -1*var;
	
} 
int main()
{
    cout<<divideTwoInteger(-20, -3)<<endl;
}