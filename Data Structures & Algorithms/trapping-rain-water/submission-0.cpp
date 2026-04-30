class Solution {
public:
    int trap(vector<int>& h) {
        
        int n = h.size();
        vector<int> pref(n), suff(n);

        for ( int i=0; i<n; i++ )
            pref[i] = i == 0 ? h[i] : max(h[i],pref[i-1]);
        
        for ( int i=n-1; i>=0; i--)
            suff[i] = i == n-1 ? h[i] : max(h[i],suff[i+1]);
        
        int ans = 0;
        for ( int i = 1; i < n-1; i++) {
            int t = min(pref[i-1],suff[i+1]);
            if (t > h[i]) {
                ans += t - h[i];
            }
        }

        return ans;

    }
};
