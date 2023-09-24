#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s = "abcdefffffghwoijowjlke";
    unordered_map<char, int> count;
    char ch;

    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        count[ch]++;
    }

    // Iterate over the map and print the counts for each character
    for (auto it = count.begin(); it != count.end(); ++it) {
        cout << it->first << "    " << it->second << endl;
    }

    return 0;
}
