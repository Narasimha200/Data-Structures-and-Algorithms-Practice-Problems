#include <bits/stdc++.h>
using namespace std;



//LINK:- https://leetcode.com/problems/set-matrix-zeroes/

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // swap matrix[i][j] with matrix[j][i]
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

//TC:- O(n * n)
//SC:- O(1)