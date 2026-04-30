class MinStack {
public:
    
    stack<int> st, mns;
    MinStack() {
        
    }
    
    void push(int val) {
        if (mns.empty())
            mns.push(val);
        else
            mns.push(min(val,mns.top()));
        st.push(val);
    }
    
    void pop() {
        st.pop();
        mns.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mns.top();
    }
};
