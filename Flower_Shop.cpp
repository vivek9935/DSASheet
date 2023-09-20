#include<bits/stdc++.h>
using namespace std;
int FlowerShop( vector<int> &nums ){
    vector<int> vis(10000+1,0);
   for (int i = 0; i < nums.size(); i++) {
    int val = nums[i];
    cout<<vis[val]++<<endl;
}
    int ans = 0;
    for( int i = 0 ; i <= 10000 ;){
        if( vis[i] ){
            ans++;
            i += 4;
        }
        i++;
    }
    return ans;
}
int main()
{
    int n=5;

    //cin>>n;

    vector<int> nums{1,2,3,17,10};

    // for( int ind = 0 ; ind < n ; ind++ ) 
    // cin>>nums[ind];
    int ans = FlowerShop(nums);
    cout<<ans<<endl;
    return 0;

}