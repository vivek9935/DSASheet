#include <bits/stdc++.h>
using namespace std; 
void heapify(vector<int> &ans, int n, int i) {
    int l = i;
    int le = 2*i + 1;
    int re = 2*i + 2;
    cout<<"l    le     re  "<<l<<"  "<<le<<"  "<<re<<endl;
    if (le < n && ans[l] < ans[le])
        l = le;
    if (re < n && ans[l] < ans[re])
        l = re;
    if (l != i) {
        swap(ans[i], ans[l]);
        heapify(ans, n, l);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans;
    for(auto i:arr1)
      ans.push_back(i);
    for(auto i:arr2)
      ans.push_back(i);
    int ni = ans.size();
    for (int i = (ni / 2)-1 ; i >= 0; i--) {
        heapify(ans, ni, i);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"  ";
    }cout<<endl;


    return ans;


}
int main() {
    // Test data
    int n = 5;
    int m = 4;

    std::vector<int> arr1 = {10 ,5, 6, 4, 5, 6};
    std::vector<int> arr2 = {9, 7, 9, 4, 3, 8, 3};

    // Merge the heaps
    vector<int> mergedHeap = mergeHeap(n, m, arr1, arr2);

    // Print the merged heap
    std::cout << "Merged Heap: ";
    for (int num : mergedHeap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}