//Problem Link:- "https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1"
public class subsetSumEqualToK {
    class Solution {
        // memoization
        static Boolean check(int idx, int arr[], int target, int[][] dp) {
            if (target == 0)
                return true;
            if (idx == 0)
                return arr[0] == target;
            if (dp[idx][target] != -1)
                return dp[idx][target] == 1;
            Boolean notPick = check(idx - 1, arr, target, dp);
            Boolean pick = false;
            if (arr[idx] <= target) {
                pick = check(idx - 1, arr, target - arr[idx], dp);
            }
            dp[idx][target] = (pick || notPick) ? 1 : 0;
            return dp[idx][target] == 1;
        }
        // TC:- (N * sum)
        // SC:- (N * sum) + O(N)

        // tabulation with space optimization
        static Boolean isSubsetSum(int arr[], int sum) {
            int n = arr.length;
            boolean[] prev = new boolean[sum + 1];
            prev[0] = true;
            if (arr[0] <= sum)
                prev[arr[0]] = true;
            boolean[] curr = new boolean[sum + 1];
            curr[0] = true;
            for (int idx = 1; idx < n; idx++) {
                for (int target = 0; target <= sum; target++) {
                    boolean notPick = prev[target];
                    Boolean pick = false;
                    if (arr[idx] <= target){
                        pick = prev[target - arr[idx]];
                    }
                    curr[target] = notPick || pick;
                }
                boolean[] temp = prev;
                prev = curr;
                curr = temp;
            }
            return prev[sum];
        }
        //TC:- O(N * sum)
        //SC:- O(sum)
    }
}
// TC:- (N * sum)
// SC:- (N * sum) + O(N)
