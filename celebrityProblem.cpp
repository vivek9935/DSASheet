#include <iostream>
#include <vector>
using namespace std;
// Function to find the celebrity
int celebrity(vector<vector<int>>& M, int n) {
    int candidate = 0;

    // Step 1: Find a potential candidate who might be a celebrity
    for (int i = 1; i < n; i++) {
        if (M[candidate][i] == 1) {
           { candidate = i;
              cout<<candidate<<endl;
           }
        }
    }

    // Step 2: Verify if the candidate is a celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
            return -1; // The candidate is not a celebrity
        }
    }

    return candidate; // The candidate is a celebrity
}

int main() {
    // Example adjacency matrix (n = 4)
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0,1,1},
        {0,0,1},
        {0,1,0}
    };

    int n = adjacencyMatrix.size();

    int celeb = celebrity(adjacencyMatrix, n);

    if (celeb != -1) {
        std::cout << "The celebrity is person " << celeb << std::endl;
    } else {
        std::cout << "No celebrity found." << std::endl;
    }

    return 0;
}
