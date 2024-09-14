
#include <vector>
using namespace std;
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int currDist = nums[0];
    int maxDist = nums[0];
    for(int i = 0; i < n; i++){
        if(maxDist >= n - 1) return true;
        maxDist = max(maxDist, nums[i] + i);
        currDist--;
        if(currDist == 0 && maxDist <= i) return false;
    }
    return false;
}