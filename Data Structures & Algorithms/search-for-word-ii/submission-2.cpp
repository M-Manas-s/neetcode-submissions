class Solution {
public:

    const vector<int> d4i = {0,0,-1,1};
    const vector<int> d4j = {-1,1,0,0};

    void feed(int par, int i,int j, vector<vector<char>>& board, vector<vector<int>> &adj, int dfsvis[12][12], int h) {

        if ( h > 10 )
            return;

        int n = board.size();
        int m = board[0].size();

        auto check = [&](int x,int y) {
            return x >= 0 && x < n && y >= 0 && y < m && dfsvis[x][y] == 0; 
        };

        dfsvis[i][j] = 1;

        int new_node;
        if (adj[par][board[i][j] - 'a'] == -1) {
            adj.push_back(vector<int>(26,-1));
            new_node = adj.size() - 1;
            adj[par][board[i][j] - 'a'] = new_node;
        } else
            new_node = adj[par][board[i][j] - 'a'];

        for ( int k = 0; k < 4; k++ ) {
            int x = i + d4i[k];
            int y = j + d4j[k];
            if ( check(x,y) )
                feed(new_node,x,y,board,adj,dfsvis, h+1);
        }

        dfsvis[i][j] = 0;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<vector<int>> adj;

        adj.push_back(vector<int>(26,-1));

        int dfsvis[12][12];
        for ( int i = 0; i < 12; i++ )
            for ( int j = 0; j < 12; j++ )
                dfsvis[i][j] = 0;

        int n = board.size();
        int m = board[0].size();
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                feed(0, i,j, board, adj, dfsvis, 1);

        vector<string> ans;

        for ( auto word : words ) {
            int cur = 0;
            bool found = 1;
            for (auto ch: word) {
                cur = adj[cur][ch-'a'];
                if (cur == -1) {
                    found = 0;
                    break;
                }
            }
            if (found)
                ans.push_back(word);
        }

        return ans;

    }
};
