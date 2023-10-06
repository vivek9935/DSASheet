#include <bits/stdc++.h> 
using namespace std;
int stringMania(int n, int m, string str1, string str2) {
    for(int i=0; i<min(n, m); i++){
        if(str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
    }

    if(n > m) {
        return 1;
    } else if (n < m) {
        return -1;
    }

    return 0;

}
int main() {
    int n, m;
    cout << "Enter the length of the first string (n): ";
    cin >> n;
    cout << "Enter the length of the second string (m): ";
    cin >> m;

    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int result = stringMania(n, m, str1, str2);

    if (result == 0) {
        cout << "Both strings are equal." << endl;
    } else if (result == 1) {
        cout << "The first string is greater than the second string." << endl;
    } else {
        cout << "The second string is greater than the first string." << endl;
    }

    return 0;
}
