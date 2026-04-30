class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<pair<int,int>> st;
        map<int,int> mp;
        for ( auto x : nums )
            mp[x]++;
        for ( auto x : mp )
            st.insert({-x.second,x.first});
        auto it = st.begin();
        vector<int> ans;
        for ( int i = 0; i < k; i++ ) {
            ans.push_back((*it).second);
            it++;
        }
        return ans;
    }
};
