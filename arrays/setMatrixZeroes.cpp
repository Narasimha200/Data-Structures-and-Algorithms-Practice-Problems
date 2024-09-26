#include <bits/stdc++.h>
using namespace std;

// LINK:- "https://leetcode.com/problems/set-matrix-zeroes/description/"

void setZeroes(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    // for every 0 for its column and row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // for every cell check whether its column or row is marks or not
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
//TC:- O(N*M)
//SC:- O(N + M)