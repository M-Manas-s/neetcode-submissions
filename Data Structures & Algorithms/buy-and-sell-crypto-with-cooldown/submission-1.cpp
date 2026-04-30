class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2]; // 0 - buy, 1 - sell
        dp[0][0] = -prices[0];
        dp[0][1] = -1e9;
        for ( int i = 1 ; i < n; i++ ) {
            if ( i >= 2 )
                dp[i][0] = max( dp[i-1][0], dp[i-2][1] - prices[i]);
            else
                dp[i][0] = max(dp[i-1][0], -prices[i]);
            
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }
        return max(0,dp[n-1][1]);
    }
};
