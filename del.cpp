#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m = 2;
    vector<pair<int, int>> p(m, make_pair(-1, -1));
    for (int i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < m; i++) {
        if (p[i].first != -1 && p[i].second == -1) {
            int index = p[i].first;
            if (index >= 0 && index < n) {
                arr.erase(arr.begin() + index);
                n--;
            }
        } else if (p[i].first != -1 && p[i].second != -1) {
            int start = p[i].first;
            int end = p[i].second;

            if (start >= 0 && start < n && end >= 0 && end <= n && start <= end) {
                arr.erase(arr.begin() + start, arr.begin() + end + 1);
                n -= (end - start + 1);
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
