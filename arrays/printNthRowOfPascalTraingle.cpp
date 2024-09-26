#include <bits/stdc++.h>
using namespace std;

//LINK:- "https://leetcode.com/problems/pascals-triangle-ii/"

vector<int> getRow(int rowIndex)
{
    vector<int> pascal;
    pascal.push_back({1});
    for (int row = 1; row <= rowIndex; row++)
    {
        vector<int> currRow(row + 1);
        currRow[0] = currRow[row] = 1;
        for (int j = 1; j < row; j++)
        {
            currRow[j] = pascal[j - 1] + pascal[j];
        }
        pascal = currRow;
    }
    return pascal;
}

//TC:- O(N * N)
//SC:- O(N)