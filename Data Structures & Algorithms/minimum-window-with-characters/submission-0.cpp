class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> mask;
        for (auto x : t)
            mask[x]++;

        auto overlaps = [&](map<int,int> mp) {
            bool ok = 1;
            for ( auto x : mask ) {
                ok &= mp[x.first] >= x.second;
            }
            return ok;
        };

        int l = 0;
        map<int,int> cur;
        string ret = "";
        for ( int r = 0; r < s.length(); r++ ) {
            cur[s[r]]++;
            while( l <= r && overlaps(cur) ) {
                if ( ret.length() == 0 || r-l+1 < (int)ret.length())
                    ret = s.substr(l,r-l+1);
                cur[s[l]]--;
                l++;
            }
        }

        return ret;
    }
};
