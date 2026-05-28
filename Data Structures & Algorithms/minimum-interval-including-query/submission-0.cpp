class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        vector<int> ans;
        int hehe = 1e9;
        for ( auto x : queries ) {
            vector<int> mn = {-1, hehe};
            for ( auto y : intervals ) {
                if ( y[0] <= x && y[1] >= x && mn[1] - mn[0] > y[1] - y[0])
                    mn = y;
            }
            if (mn[1] == hehe)
                mn = {4,2};
            ans.push_back(1 + mn[1] - mn[0]);

        }
        return ans;
    }
};
