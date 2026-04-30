class Solution {
public:

    vector<pair<int,int>> twoSum(vector<int> &nums, int target, int start) {

        map<int,int> mp, used;
        vector<pair<int,int>> ret;
        for ( int i = start; i < nums.size(); i++ ) {
            if ( mp[target - nums[i]] !=  0 && used[target - nums[i]] == 0) {
                ret.push_back({nums[i], target-nums[i]});
                used[target-nums[i]] = 1;
            }
            mp[nums[i]]++;
        }

        return ret;

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for ( int i = 0; i < nums.size(); i++ ) {
            if (i!=0) {
                while(nums[i] == nums[i-1])
                    i++;
            }
            vector<pair<int,int>> ret = twoSum(nums, -nums[i], i+1);
            for (auto x : ret ) {
                ans.push_back({nums[i], x.first, x.second});
            }
        }
        return ans;
    }
};
