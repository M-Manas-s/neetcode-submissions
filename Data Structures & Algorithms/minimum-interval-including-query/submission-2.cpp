class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) {

        priority_queue<vector<int>> pq;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        int m = q.size();
        vector<int> idx;
        for ( int i = 0; i < m; i++)
            idx.push_back(i);
        
        vector<int> ans(m, -1);
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return q[a] < q[b];
        });

        int p = 0;
        int n = intervals.size();

        for ( int qi = 0; qi < m; qi++ ) {
            int cur_q = q[idx[qi]];
            // cout << cur_q << endl;
            if ( pq.empty() && p < n && cur_q < intervals[p][0] ) 
                continue;

            while( p < n && intervals[p][0] <= cur_q ) {
                int len = intervals[p][1] - intervals[p][0] + 1;
                pq.push({-len, intervals[p][0], intervals[p][1]});
                p++;
            }

            while (!pq.empty() && pq.top()[2] < cur_q )
                pq.pop();

            // priority_queue<vector<int>> tpq = pq;
            // while ( !tpq.empty() ) {
            //     vector<int> top = tpq.top();
            //     tpq.pop();
            //     cout << top[0] << ' ' << top[1] << ' ' << top[2] << endl;
            // }

            if ( !pq.empty() )
                ans[idx[qi]] = -pq.top()[0];
        }
        
        return ans;
    }
};
