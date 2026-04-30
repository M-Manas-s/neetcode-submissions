class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1)
            return 0;
        int target = sum / 2;
        vector<int> dp[2];
        dp[0] = dp[1] = vector<int>(target+1);
        dp[0][0] = dp[1][0] = 1;

        for ( int i = 1 ; i <= nums.size(); i++ ) {
            for ( int j = 1; j <= target; j++ ) {
                if ( j >= nums[i-1] ) {
                    dp[i&1][j] = dp[(i-1)&1][j] || dp[(i-1)&1][j-nums[i-1]];
                } else
                    dp[i&1][j] = dp[(i-1)&1][j];
            }
        }

        return dp[nums.size()&1][target];
    }
};
