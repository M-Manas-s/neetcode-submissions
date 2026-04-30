class Solution {
public:
    bool isPalindrome(string s) {
        int b = s.length()-1;
        int f = 0;

        auto alpha = [&](char ch) {
            bool ok = 0;
            ok |= ch >= '0' && ch <= '9';
            ok |= ch >= 'a' && ch <= 'z';
            ok |= ch >= 'A' && ch <= 'Z';
            return ok;
        };

        while(b>f) {
            while(b >= 0 && !alpha(s[b]) ) b--;
            while(f < s.length() && !alpha(s[f]) ) f++;
            if ( tolower(s[b]) != tolower(s[f]) ) {
                cout << b << ' ' << f;
                return 0;
            }
            b--;
            f++;
        }

        return 1;
    }
};
