#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(int rows, int columns, vector<vector<int> > &heights)
{
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > >pq;
    vector<vector<int> > maxEfforts(rows, vector<int>(columns, 1e9));
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    maxEfforts[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        vector<int> top = pq.top();
        pq.pop();
        int effort = top[0];
        int row = top[1];
        int col = top[2];
        if(row == rows - 1 && col == columns - 1) return effort;

        for(int i = 0; i < 4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < columns){
                int currMaxEffort = max(effort, abs(heights[row][col] - heights[nRow][nCol]));
                if(currMaxEffort < maxEfforts[nRow][nCol]){
                    maxEfforts[nRow][nCol] = currMaxEffort;
                    pq.push({currMaxEffort, nRow, nCol});
                }
            }
        }
    }
    return 0;
}

//TC:- (V+E)logV where V = n * m and E = n * m * 4
//SC:- (n * m)