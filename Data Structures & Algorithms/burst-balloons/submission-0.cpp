class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[301][301];

        for ( int i = 0; i <= n; i++ )
        for ( int j = 0; j <= n; j++ )
            dp[i][j] = 0;

        for ( int i = 0; i < n; i++ )
            dp[i][i] = ( i == 0 ? 1 : nums[i-1]) * nums[i] * (i == n-1 ? 1 : nums[i+1] );

        for ( int len = 2; len <= n; len++ ) {
            for ( int i = 0; i <= n - len; i++ ) {
                int l = i;
                int r = i + len - 1;
                // cout << l << ' ' << r << ' ';
                for (int k = l; k <=r; k++ ) {
                    int left = l == 0 ? 1 : nums[l-1];
                    int right = r == n-1 ? 1 : nums[r+1];
                    dp[l][r] = max(dp[l][k-1] + dp[k+1][r] + left * nums[k] * right, dp[l][r] );
                }
                // cout << dp[l][r] << endl;
            }
        }

        // for ( int i =0; i < n-1; i++ )
        //     cout << dp[i][i+1] << ' ';

        return dp[0][n-1];
    }
};
