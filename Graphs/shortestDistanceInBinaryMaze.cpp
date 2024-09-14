#include <vector>
#include <queue>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n));
    queue<pair<pair<int, int>, int>> q;
    //------------------
    q.push({{0, 0}, 1});
    visited[0][0] = 1;

    while (!q.empty())
    {
        auto quardinatesAndDist = q.front();
        int row = quardinatesAndDist.first.first;
        int col = quardinatesAndDist.first.second;
        int dist = quardinatesAndDist.second;
        q.pop();
        // traverse all four sides
        for (int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++){
            int nRow = row + i;
            int nCol = col + j;
            if (nRow == n-1 && nCol == n-1)
                return dist;
            if (nRow >= 0 && nRow < n && !visited[nRow][nCol] && grid[nRow][nCol] == 0)
            {
                q.push({{nRow, nCol}, dist + 1});
                visited[nRow][nCol] = true;
            }
        }
    }
    return -1;
}

//TC:- O(n * m * 4) --> O(n * m)
//SC:- O(n * m)
