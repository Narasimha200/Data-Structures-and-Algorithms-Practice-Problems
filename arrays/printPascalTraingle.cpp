#include <bits/stdc++.h>
using namespace std;

//LINK:- "https://leetcode.com/problems/pascals-triangle/description/"

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    pascal.push_back({1});
    for(int row = 1; row < numRows; row++){
        vector<int> currRow(row+1);
        currRow[0] = currRow[row] = 1;
        for(int j = 1; j < row; j++){
            currRow[j] = pascal[row-1][j-1]+pascal[row-1][j];
        }
        pascal.push_back(currRow);
    }
    return pascal;
}

//TC:- O(N * N)
//SC:- O(N * N)