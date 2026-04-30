class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n),suff(n);
        for ( int i = 0; i < n; i++ )
            pref[i] = i == 0 ? nums[i] : nums[i] * pref[i-1];
        for ( int i = n - 1; i >= 0; i-- )
            suff[i] = i == n-1 ? nums[i] : nums[i] * suff[i+1];
        vector<int> ans;
        for ( int i = 0; i < n; i++ )
            ans.push_back( i == 0 ? suff[1] : i == n-1 ? pref[i-1] : pref[i-1] * suff[i+1] );
        return ans;
    }
};
