class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxP = 0;
        int curMin = prices[0];
        for ( int i = 1 ; i < prices.size(); i++ ) {
            maxP = max(maxP, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }
        return maxP;

    }
};
