// C++ code for the above approach:
#include <iostream>
#include <vector>
using namespace std;

void SetMatrixZeroes(vector<vector<int>>& arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    
    // Create two arrays to store whether a row or column should be zeroed
    vector<bool> zeroRows(rows, false);
    vector<bool> zeroCols(cols, false);

    // Traverse the matrix to mark rows and columns to be zeroed
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Zero out rows
    for (int i = 0; i < rows; i++) {
        if (zeroRows[i]) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // Zero out columns
    for (int j = 0; j < cols; j++) {
        if (zeroCols[j]) {
            for (int i = 0; i < rows; i++) {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 2, 0},
                                {3, 4, 5, 2},
                                {1, 3, 1, 5}};

    // Function call
    SetMatrixZeroes(arr);

    // Printing the modified matrix
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
