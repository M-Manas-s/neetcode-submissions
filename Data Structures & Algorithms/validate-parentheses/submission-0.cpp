class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        map<int,int> comp;
        comp['['] = ']';
        comp['{'] = '}';
        comp['('] = ')';
        for ( auto x : s ) {
            if ( !st.empty() && comp[st.top()] == x )
                st.pop();
            else
                st.push(x);
        }
        return st.empty();
    }
};
