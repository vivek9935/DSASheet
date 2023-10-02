#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a value in a cell
bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        if (board[row][i] == val)
            return false;
        if (board[i][col] == val)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solve(vector<vector<int>>& board) {
    int n = board.size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        if (solve(board))
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle
void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

// Function to print the Sudoku board
void printSudoku(vector<vector<int>>& sudoku) {
    int n = sudoku.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku Puzzle:" << endl;
    printSudoku(sudoku);

    if (solve(sudoku)) {
        cout << "\nSolution:" << endl;
        printSudoku(sudoku);
    } else {
        cout << "\nNo solution found!" << endl;
    }

    return 0;
}
