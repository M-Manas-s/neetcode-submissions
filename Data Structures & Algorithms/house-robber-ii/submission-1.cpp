class Solution {
public:

    int calc ( vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for ( int i = 2; i < n; i++ ) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if ( nums.size() == 1 ) return nums[0];
        return max(calc(vector(nums.begin()+1,nums.end())), calc(vector(nums.begin(), nums.end()-1)));
    }
};
