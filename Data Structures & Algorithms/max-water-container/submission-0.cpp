class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int p = 0, p1 = h.size() - 1;
        int ans = 0;

        while ( p < p1 ) {
            ans = max(ans, min(h[p], h[p1]) * (p1 - p));
            if (h[p] < h[p1])
                p++;
            else
                p1--;
        }

        return ans;

    }
};
