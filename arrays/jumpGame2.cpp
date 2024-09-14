#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int currDist = nums[0];
    int maxDist = nums[0];
    int steps = 0;

    for(int i = 1; i < nums.size(); i++){
        if(i == n - 1) return steps + 1;
        currDist--;
        maxDist = max(maxDist, i + nums[i]);
        //reached the already taken distance completly
        if(currDist == 0){
            steps++;
            currDist =  maxDist - i;
        }
    }
    return 0;
}

//TC:- O(N)
//SC:- O(1)