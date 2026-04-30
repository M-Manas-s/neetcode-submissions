class Solution {
public:

    bool valid(vector<vector<char>>& board) {

        map<char,int> mp;

        for ( int j = 0; j < 9; j++ ) {
            for ( int i = 0 ; i < 9; i++ ) {
                if (board[i][j] == '.')
                    continue;
                if ( mp[board[i][j]] == 1 )
                    return 0;
                mp[board[i][j]]++;
            }
            mp.clear();
        }

        for ( int j = 0; j < 9; j++ ) {
            for ( int i = 0 ; i < 9; i++ ) {
                if (board[j][i] == '.')
                    continue;
                if ( mp[board[j][i]] == 1 )
                    return 0;
                mp[board[j][i]]++;
            }
            mp.clear();
        }

        for ( int x = 0; x < 9; x += 3)
            for ( int y = 0; y < 9; y += 3) {
                for ( int i = x; i < x + 3; i++ ){
                    for ( int j = y; j < y + 3; j++ ) {
                        if (board[i][j] == '.')
                            continue;
                        if ( mp[board[i][j]] == 1 )
                            return 0;
                        mp[board[i][j]]++;
                    }
                }
                mp.clear();
            }

        return 1;

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return valid(board);
    }
};
