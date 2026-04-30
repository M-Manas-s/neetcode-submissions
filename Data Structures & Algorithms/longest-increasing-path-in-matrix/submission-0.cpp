class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vt;
        int n = matrix.size();
        int m = matrix[0].size();
        for ( int i =0; i < n; i++) for ( int j = 0; j < m;j++)
            vt.push_back({i,j});
        sort(vt.begin(), vt.end(), [&](pair<int,int> a, pair<int,int> b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        });

        int dp[n][m];
        for ( int i =0; i < n; i++) for ( int j = 0; j < m;j++)
            dp[i][j] = 0;
        vector<int> d4i = {-1, 1, 0, 0};
        vector<int> d4j = {0, 0, 1, -1};
        int ret = 0;
        for ( auto p : vt ) {
            for ( int i = 0; i < 4; i++ ) {
                int x = p.first + d4i[i];
                int y = p.second + d4j[i];
                if ( x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[p.first][p.second] ) {
                    dp[p.first][p.second] = max(dp[p.first][p.second], 1 + dp[x][y]);
                }
            }
            ret = max(ret, dp[p.first][p.second]);
        }
        return ret + 1;
    }
};
