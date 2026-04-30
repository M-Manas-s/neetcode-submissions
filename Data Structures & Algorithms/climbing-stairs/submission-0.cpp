class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for ( int i = 1; i <= n; i++ ) 
            dp[i] = (i>=2?dp[i-2]:0) + dp[i-1];
        return dp[n];
    }
};
