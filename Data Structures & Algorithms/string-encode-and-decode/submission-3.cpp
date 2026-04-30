class Solution {
public:

    string encode(vector<string>& strs) {
        string coded = "";
        for ( auto x : strs ) {
            coded += std::to_string(x.length());
            coded += "#" + x;
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> strgs;
        int len = 0;
        for ( int i = 0; i < s.length(); i++ ) {
            if ( s[i] >= '0' && s[i] <= '9' ) {
                len = len * 10 + (s[i] - '0');
            } else if ( s[i] == '#' ) {
                i++;
                int lim = i + len;
                string ts = "";
                for (; i<lim; i++)
                    ts += s[i];
                i--;
                strgs.push_back(ts);
                len = 0;
            }
        }
        return strgs;
    }
};
