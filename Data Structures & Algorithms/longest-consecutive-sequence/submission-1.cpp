class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> dp;
        sort(nums.begin(),nums.end());
        int ret = 0;
        for ( auto x : nums ) {
            dp[x] = dp[x-1] + 1;
            ret = max(ret, dp[x]);
        }
        return ret;
    }
};
