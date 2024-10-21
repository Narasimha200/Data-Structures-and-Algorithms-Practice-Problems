#include <bits/stdc++.h>
using namespace std;
bool isValid(int x, int y, int m, int n, vector<vector<int>> &matrix, vector<vector<bool>> &viisted){
    if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 0 && viisted[x][y] == false){
        return true;
    }
    return false;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int srcX, srcY, dX, dY, rx, ry;
    cin >> srcX >> srcY >> dX >> dY >> rx >> ry;
    //logic begin
    int count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<vector<int>> q;
    visited[srcX][srcY] = true;
    q.push({srcX, srcY, 0});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int cx = front[0];
        int cy = front[1];
        int dis = front[2];
        if(cx == dX && cy == dY){
            cout << dis << endl;
            break;
        }
        int nx, ny;
        //for forword
        nx = cx + rx;
        ny = cy + ry;
        if(isValid(nx, ny, m, n, matrix, visited)){
            q.push({nx, ny, dis + 1});
            visited[nx][ny] = true;
        }
        //right
        nx = cx + ry;
        ny = cy - rx;
        if(isValid(nx, ny, m, n, matrix, visited)){
            q.push({nx, ny, dis + 1});
            visited[nx][ny] = true;
        }
        //back
        nx = cx - rx;
        ny = cy - ry;
        if(isValid(nx, ny, m, n, matrix, visited)){
            q.push({nx, ny, dis + 1});
            visited[nx][ny] = true;
        }
        //left
        nx = cx - ry;
        ny = cy + rx;
        if(isValid(nx, ny, m, n, matrix, visited)){
            q.push({nx, ny, dis + 1});
            visited[nx][ny] = true;
        }
        count++;
    }
}
