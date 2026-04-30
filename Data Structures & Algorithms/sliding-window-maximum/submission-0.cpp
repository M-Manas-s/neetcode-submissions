class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mst;
        vector<int> ans;
        for ( int i = 0; i <k; i++ )
            mst.insert(-nums[i]);
        ans.push_back(-(*mst.begin()));

        for ( int i = k; i < nums.size(); i++ ) {
            mst.erase(mst.find(-nums[i-k]));
            mst.insert(-nums[i]);
            ans.push_back(-(*mst.begin()));
        }

        return ans;
    }
};
