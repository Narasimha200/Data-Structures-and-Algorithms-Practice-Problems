//Problem Link:- "https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1"
public class subsetSumEqualToK {
    class Solution {
    
        static Boolean check(int idx, int arr[], int target, int[][] dp){
            if(target == 0) return true;
            if(idx == 0) return arr[0] == target;
            if(dp[idx][target] != -1) return dp[idx][target] == 1;
            Boolean pick = check(idx - 1, arr, target, dp);
            Boolean notPick = false;
            if(arr[idx] <= target){
                notPick = check(idx -1, arr, target - arr[idx], dp);
            }
            dp[idx][target] = (pick || notPick)? 1: 0;
            return dp[idx][target] == 1;
        }
        
        static Boolean isSubsetSum(int arr[], int sum) {
            int n = arr.length;
            int[][] dp = new int[n][sum+1];
            for(int i = 0; i < dp.length; i++){
                for(int j = 0; j < dp[0].length; j++){
                    dp[i][j] = -1;
                }
            }
            return check(n-1, arr, sum, dp);
        }
    }
}
//TC:- (N * sum)
//SC:- (N * sum) + O(N)
