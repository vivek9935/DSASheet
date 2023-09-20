#include <bits/stdc++.h>
using namespace std;
vector<int> sumInRanges(vector<int> &arr, int n,
                        vector<vector<long long>> &queries, int q)
{

    // Write your code here

    vector<int> v;

    vector<long long> prefixsum(n + 1);

    prefixsum[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        prefixsum[i] = (prefixsum[i - 1] + arr[i - 1]) ;
    }

    while (q--)
    {

        long long L = queries[q][0];

        long long R = queries[q][1];

        long long count1 = ((L - 1) / n) ;

        long long res1 = ((count1)*prefixsum[n]) ;

        long long Lsum = (res1 + prefixsum[(L - 1) % n]);

        long long count2 = (R / n) ;

        long long res2 = ((count2)*prefixsum[n]) ;

        long long Rsum = (res2 + prefixsum[R % n]) ;
        int sum = (int)(Rsum - Lsum ) ;

        v.push_back(sum);
    }

    reverse(v.begin(), v.end());

    return v;
}