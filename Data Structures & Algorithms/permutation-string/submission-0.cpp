class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<vector<int>,int> mp;

        // Pre-compute s2
        vector<int> tmp(26);
        for ( int i = 0; i < min(s2.length(),s1.length()); i++ )
            tmp[s2[i] - 'a']++;
        mp[tmp]++;
        for ( int i = s1.length(); i < s2.length(); i++ ) {
            tmp[s2[i-s1.length()] - 'a']--;
            tmp[s2[i] - 'a']++;
            mp[tmp]++;
        }

        // Check in s1
        vector<int> chk(26);
        for ( int i =0; i < s1.length(); i++ )
            chk[s1[i] - 'a']++;
        if ( mp[chk] != 0 )
            return 1;
        return 0;
    }
};
