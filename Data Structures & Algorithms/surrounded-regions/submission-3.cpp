class Solution {
public:

    pair<int,int> par[200][200];
    int size_[200][200];
    
    struct dir{
        int left,right,up,down;

        void set() {
            left = right = up = down = 0;
        }

        bool check() {
            // cout << left << ' ' << right << ' ' << up << ' ' << down << endl;
            return left + right + up + down == 4;
        }

    } dirs[200][200];

    void make_set(int x,int y, vector<vector<char>> &board) {
        par[x][y] = {x,y};
        size_[x][y] = 1;
        int n = board.size();
        int m = board[0].size();

        dirs[x][y].set();

        if ( x!= 0 )
            dirs[x][y].up = 1;
        if ( x!= n-1)
            dirs[x][y].down = 1;
        if ( y!= 0)
            dirs[x][y].left = 1;
        if ( y!= m-1)
            dirs[x][y].right = 1;
        
    }

    pair<int,int> find_set(int x,int y) {
        if ( par[x][y] == make_pair(x,y) )
            return {x,y};
        return par[x][y] = find_set(par[x][y].first, par[x][y].second);
    }

    void union_sets(pair<int,int> p1, pair<int,int> p2) {
        p1 = find_set(p1.first, p1.second);
        p2 = find_set(p2.first, p2.second);

        if (p1 != p2) {
            if (size_[p1.first][p1.second] < size_[p2.first][p2.second]) 
                swap(p1,p2);
            par[p2.first][p2.second] = p1;
            size_[p1.first][p1.second] += size_[p2.first][p2.second];
            
            dirs[p1.first][p1.second].left = min(dirs[p1.first][p1.second].left , dirs[p2.first][p2.second].left);
            dirs[p1.first][p1.second].right = min(dirs[p1.first][p1.second].right , dirs[p2.first][p2.second].right);
            dirs[p1.first][p1.second].up  = min(dirs[p1.first][p1.second].up , dirs[p2.first][p2.second].up);
            dirs[p1.first][p1.second].down = min(dirs[p1.first][p1.second].down , dirs[p2.first][p2.second].down);
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                make_set(i,j,board);

        int d2i[2] = {0,-1};
        int d2j[2] = {-1,0};

        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ ) {
                if (board[i][j] == 'X')
                    continue;
                int x,y;
                for ( int k = 0; k < 2; k++ ) {
                    x = i + d2i[k];
                    y = j + d2j[k];
                    if ( x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
                        union_sets({i,j},{x,y});
                }
            }

        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ ) {
                // cout << i << ' ' << j << ' ';
                auto tpar = find_set(i,j);
                // cout << '{' << tpar.first << ',' << tpar.second << '}' << ' ';
                if ( dirs[par[i][j].first][par[i][j].second].check() )
                    board[i][j] = 'X';
            }

    }
};
