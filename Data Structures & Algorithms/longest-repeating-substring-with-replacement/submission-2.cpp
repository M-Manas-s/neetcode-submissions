class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int> mp;
        int ret = 0;
        int l = 0;
        for ( int r = 0; r < s.length(); r++ ) {
            mp[s[r]]++;
            int c1 = 0;
            for ( auto x : mp )
                c1 = max(c1, x.second);

            while( l <= r && r - l + 1 - c1 > k ) {
                mp[s[l]]--;
                if ( mp[s[l]] == 0 )
                    mp.erase(mp[s[l]]);
                c1 = r - l + 1;
                for ( auto x : mp )
                    c1 = max(c1,x.second);
                l++;
            }

            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};
