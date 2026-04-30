class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for ( auto token : tokens ) {
            if ( token.back() >= '0' && token.back() <= '9' ) 
                st.push(std::stoi(token));
            else {
                int num = st.top();
                st.pop();
                if ( token == "*" ) {
                    num *= st.top();
                } else if (token == "+") {
                    num += st.top();
                } else if (token == "/") {
                    num = st.top() / num;
                } else
                    num = st.top() - num;
                st.pop();
                st.push(num);
            }
        }

        return st.top();
    }
};
