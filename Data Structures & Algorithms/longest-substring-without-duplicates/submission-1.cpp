class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        int l = 0;
        map<int,int> mp;

        for ( int r = 0; r < s.length(); r++ ) {
            while ( l <= r && mp[s[r]] != 0 ) {
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            ans = max(ans, r - l + 1);
        }

        return ans;

    }
};
