class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int p = 0;
        int p1 = nums.size() - 1;

        while(p1 > p) {
            int sum = nums[p1] + nums[p];
            if ( sum == target )
                return {p+1,1+p1};
            else if ( sum > target )
                p1--;
            else
                p++;
        }

        return {0,0};

    }
};
