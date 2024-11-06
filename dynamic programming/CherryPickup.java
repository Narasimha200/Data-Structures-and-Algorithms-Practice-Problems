//problem link:- "https://leetcode.com/problems/cherry-pickup-ii/"

import java.util.*;

class Solution {
    // memoiztion
    int maxScore(int i, int j1, int j2, int row, int col, int[][] grid, int[][][] dp) {
        if (j1 < 0 || j1 == col || j2 < 0 || j2 == col) {
            return Integer.MIN_VALUE;
        }
        if (i == row - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxScore = Integer.MIN_VALUE;

        for (int f = -1; f <= 1; f++) {
            for (int s = -1; s <= 1; s++) {
                int value = maxScore(i + 1, j1 + f, j2 + s, row, col, grid, dp);
                maxScore = Math.max(maxScore, value);
            }
        }
        if (j1 == j2)
            maxScore += grid[i][j1];
        else
            maxScore += grid[i][j1] + grid[i][j2];

        return dp[i][j1][j2] = maxScore;
    }
    // TC:- O(n * m * m)
    // SC:- O(n * m * m)

    // tabulation with space optimization
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] next = new int[n][m];
        // base case
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    next[j1][j2] = grid[n - 1][j1];
                } else {
                    next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        int[][] curr = new int[m][m];
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxScore = Integer.MIN_VALUE;
                    for (int f = -1; f <= 1; f++) {
                        for (int s = -1; s <= 1; s++) {
                            if (j1 + f >= 0 && j1 + f < m && j2 + s >= 0 && j2 + s < m) {
                                int value = next[j1 + f][j2 + s];
                                maxScore = Math.max(maxScore, value);
                            }
                        }
                    }
                    if (j1 == j2)
                        maxScore += grid[i][j1];
                    else
                        maxScore += grid[i][j1] + grid[i][j2];

                    curr[j1][j2] = maxScore;
                }
            }
            //swaping two arrays
            int[][] temp = next;
            next = curr;
            curr = temp;
        }
        return next[0][m - 1];
    }
    //TC:- O(n * m * m)
    //SC:- O(m * m)
}

public class CherryPickup {
    public static void main(String[] args) {

    }
}