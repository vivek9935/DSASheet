// C++ program to find the length of the longest substring
// without repeating characters
#include <bits/stdc++.h>
using namespace std;

// This function returns true if all characters in str[i..j]
// are distinct, otherwise returns false
bool areDistinct(string str, int i, int j)
{

	// Note : Default values in visited are false
	vector<bool> visited(300);

	for (int k = i; k <= j; k++) {
        cout<<visited[str[k]]<<"   ";
		 if (visited[str[k]] == true)
			{
                return false;
            }
		visited[str[k]] = true;
	}cout<<endl;
	return true;
}

// Returns length of the longest substring
// with all distinct characters.
int longestUniqueSubsttr(string str)
{
	int n = str.size();
	int res = 0; // result
	for (int i = 0; i < n; i++)
		{for (int j = i; j < n; j++)
			{ 
                //cout<<j<<"   time i did this "<<areDistinct(str, i, j)<<"   ";
                if (areDistinct(str, i, j))
				res = max(res, j - i + 1);
                cout<<endl;
            }
        }
	return res;
}

// Driver code
int main()
{
	string str = "pwwkew";
	cout << "The input string is " << str << endl;
	int len = longestUniqueSubsttr(str);
	cout << "The length of the longest non-repeating "
			"character substring is "
		<< len;
	return 0;
}

// This code is contributed by Sania Kumari Gupta
// (kriSania804)
